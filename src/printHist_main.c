#include "itec.h"

int main(int argc, char * argv[]) {
    struct winsize w;
    get_terminal_dim(&w); //Terminal window size
    
    // 1. Aufgabe: Histogramm aus array
    /* int hist[] = {1,2,3,4,5,6,7,8,9,2,6,8,9,1,3,8,12,3};
    int hist_length = sizeof(hist) / sizeof(hist[0]);
    print_hist1(hist, hist_length); */


    // 2. Aufgabe: Histogramm aus struct(length, array)
    /* struct array_static hist2 ={18, {9,2,3,4,5,6,7,8,3,2,6,8,9,1,3,8,12,3}};
    print_hist2(&hist2); */

    struct array_static hist_s = {160, {
        3, 7, 1, 9, 4, 2, 8, 6, 5, 3,
        12, 4, 7, 9, 1, 3, 8, 5, 6, 2,
        11, 3, 5, 7, 9, 2, 4, 10, 6, 8,
        1, 12, 4, 9, 3, 7, 5, 8, 6, 2,
        10, 3, 7, 11, 4, 1, 6, 9, 8, 5,
        2, 12, 3, 7, 10, 4, 6, 1, 9, 8,
        5, 11, 3, 7, 2, 10, 4, 6, 9, 1,
        8, 12, 5, 3, 7, 9, 2, 10, 6, 4,
        11, 1, 8, 5, 3, 12, 7, 4, 9, 10,
        2, 6, 11, 8, 5, 3, 1, 7, 10, 4,
        9, 12, 6, 2, 8, 5, 3, 11, 7, 4,
        10, 1, 9, 6, 12, 5, 3, 8, 7, 4,
        2, 10, 11, 9, 6, 12, 5, 3, 8, 7,
        4, 1, 10, 11, 2, 6, 9, 12, 5, 3,
        7, 4, 8, 10, 1, 11, 6, 9, 5, 12,
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10
        } };

    int max_hist_s = max_arr_struct(&hist_s);
    print_hist_large(&hist_s, max_hist_s, &w); //Methode für großes Histogramm

    return 0;
}