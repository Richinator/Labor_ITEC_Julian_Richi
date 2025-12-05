#include <stdio.h>

#define MAX_LENGTH 100

int main(int argc, char *argv[]) {
    //Überprüfen, ob mindestens ein Argument (neben dem Programmnamen) übergeben wurde
    //Falls nicht Ausgabe mit Hinweis darauf
    if (argc < 2) {
        printf("Please provide a filename as an argument.\n");
        return 1;
    }

    //Übergebenen Dateiname (in argv[1]) öffnen, überprüfen ob erfolgreich geöffnet
    //Falls nicht Fehlermeldung
    FILE *stream = fopen(argv[1], "r");

    if (stream != NULL) {
        char line[MAX_LENGTH];
        int i = 1;
        while (fgets(line, MAX_LENGTH, stream) != NULL) {
            printf("Zeile %i: %s\n", i, line);
            i++;
        }
        fclose(stream);
    }
    else {
        perror("Error opening file");
    }
    return 0;
}