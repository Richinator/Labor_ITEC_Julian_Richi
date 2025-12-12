// 22072025
// C-Programm zum Lesen eines µControllers über USB (Jetson Nano)
// Port: /dev/ttyUSB0
// Baudrate: 115200
// Endlosschleife zum Dauerlauf

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int main() {
    const char* port = "/dev/ttyUSB0";
    int serial_port = open(port, O_RDWR);

    if (serial_port < 0) {
        printf("Fehler beim Öffnen von %s: %s\n", port, strerror(errno));
        return 1;
    }

    struct termios tty;
    if (tcgetattr(serial_port, &tty) != 0) {
        printf("Fehler beim Abrufen der Einstellungen: %s\n", strerror(errno));
        close(serial_port);
        return 1;
    }

    // Baudrate setzen
    cfsetispeed(&tty, B115200);
    cfsetospeed(&tty, B115200);

    // 8N1 Konfiguration
    tty.c_cflag &= ~PARENB;        // Keine Parität
    tty.c_cflag &= ~CSTOPB;        // 1 Stopbit
    tty.c_cflag &= ~CSIZE;
    tty.c_cflag |= CS8;            // 8 Datenbits
    tty.c_cflag &= ~CRTSCTS;       // Keine Hardware-Flowcontrol
    tty.c_cflag |= CREAD | CLOCAL; // Lesen aktivieren & lokaler Modus

    // Raw-Modus
    tty.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG);
    tty.c_iflag &= ~(IXON | IXOFF | IXANY | ICRNL | INLCR);
    tty.c_oflag &= ~OPOST;

    // Timeout und minimale Anzahl an Bytes
    tty.c_cc[VTIME] = 10; // 1s Timeout
    tty.c_cc[VMIN]  = 10; // mindestens 10 Zeichen

    // Einstellungen übernehmen
    if (tcsetattr(serial_port, TCSANOW, &tty) != 0) {
        printf("Fehler beim Setzen der Einstellungen: %s\n", strerror(errno));
        close(serial_port);
        return 1;
    }

    FILE *stream = fopen("../src/daten.csv", "w");
    if(stream == NULL) {
        printf("Fehler beim öffnen von daten.csv");
    }

    // Endlosschleife zum Lesen
    for (int i = 1; i <= 3; i++) {
        char buffer[256];
        memset(buffer, 0, sizeof(buffer));

        int num_bytes = read(serial_port, buffer, sizeof(buffer));

        if (num_bytes < 0) {
            printf("Lesefehler: %s\n", strerror(errno));
        } else {
            double real_dist;
            printf("Bitte geben Sie die reale Distanz ein: ");
            scanf("%lf", &real_dist);
            double sensor_dist = atof(buffer);
            double diff_dist = real_dist - sensor_dist;
            //printf("gemessene Distanz: %s\n", buffer);
            printf("gemessene Distanz: %lf\n", sensor_dist);
            printf("Differenz: %lf\n", diff_dist);
            fprintf(stream, "%lf, %lf, %lf\n", real_dist, sensor_dist, diff_dist);
        }
    }
    fclose(stream);

    // void save_measurement(sqlite3 *db, double real_dist, double sensor_dist, double diff_dist) {
    //     sqlite3_stmt *stmt;
    //     const char *sql = "INSERT INTO messungen (realer_abstand, sensor_wert, differenz) VALUES (?, ?, ?);";
    //     int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
    // }

    close(serial_port);
    return 0;
}