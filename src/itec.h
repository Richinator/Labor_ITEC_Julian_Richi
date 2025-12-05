#include <sys/ioctl.h>

#define MAX_ARRAY_LENGTH 10000

struct array_static
{
    int length;
    int values[MAX_ARRAY_LENGTH];
};

/**
 * @returns the max value of the array in a struct
 */
int max_arr_struct(struct array_static *arr);

/**
 * @returns the histogram
 */
void print_hist1(int *arr, int arr_length);

/**
 * @returns the histogram
 */
void print_hist2(struct array_static *arr);

/**
 * @returns the dynamic histogram
 */
void print_hist_large(struct array_static *arr, int maxE, struct winsize *w);

/**
 * @returns the terminal size
 */
int get_terminal_dim(struct winsize *w);