#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include "itec.h"

/**
 * @returns the max value of the array in a struct
 */
int max_arr_struct(struct array_static *arr) {
    int max = arr->values[0];
    for(size_t i = 1; i < arr->length; i++) {
        if(max < arr->values[i]) {
            max = arr->values[i];
        }
    }
    return max;
}

/**
 * @returns a histogram of an array
 */
void print_hist1(int *arr, int arr_length) {
    int max = arr[0];
    for(size_t i = 1; i < arr_length; i++) {
        if(max < arr[i]) {
            max = arr[i];
        }
    }
    for(int zeile = 1; zeile <= max; zeile++) {
        for(int spalte = 0; spalte < arr_length; spalte++) {
            if(arr[spalte] >= max-zeile+1) {
                printf("#");
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void print_hist2(struct array_static *arr) {
    int max = arr->values[0];
    for(size_t i = 1; i < arr->length; i++) {
        if(max < arr->values[i]) {
            max = arr->values[i];
        }
    }
    for(int zeile = 1; zeile <= max; zeile++) {
        for(int spalte = 0; spalte < arr->length; spalte++) {
            if(arr->values[spalte] >= max - zeile + 1) {
                printf("#");
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

/**
 * @returns the dynamic histogram
 */
void print_hist_large(struct array_static *arr, int maxE, struct winsize *w) {
    if(arr->length > w->ws_col) {
        for(int move = 0; move <= arr->length - w->ws_col; move++) {
            for (int zeile = 0; zeile < maxE; zeile++) {
                for (int spalte = 0; spalte < w->ws_col; spalte++) {
                    if (arr->values[spalte + move] >= (maxE - zeile)) {
                        printf("#");
                    }
                    else {
                        printf(" ");
                    }
                }
                printf("\n");
            }
            if(move == arr->length - w->ws_col) {
                usleep(3000*1000); //3s warten bis Histogramm gelöscht wird
            }
            usleep(500*1000); //500ms warten
            system("clear"); //Konsole löschen
        }
    }
    else {
        for (int zeile = 0; zeile < maxE; zeile++) {
            for (int spalte = 0; spalte < arr->length; spalte++) {
                if (arr->values[spalte] >= (maxE - zeile)) {
                    printf("#");
                }
                else {
                    printf(" ");
                }
            }
            printf("\n");
        }
    }
}

/**
 * @returns the windows size
 */
int get_terminal_dim(struct winsize *w){
    // Get terminal window size
    if (ioctl(STDOUT_FILENO, TIOCGWINSZ, w) == -1) {
        perror("ioctl");
        return 1;
    }
    //printf("Terminal width: %d columns\n", w->ws_col);
    //printf("Terminal height: %d rows\n", w->ws_row);
    return 0;
}