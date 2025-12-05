#include <stdio.h> //printf

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(int argc, char* argv[]) { //char argv[][]

    int x = 3;
    int y = 5;

    printf("Start: x = %i, y = %i\n", x, y);
    //swap: Tauschen von den Werten in x und y
    //ToDo: Erstelle eine Methode swap
    swap(&x , &y);
    printf("Swap: x = %i, y = %i\n", x, y);

    int arr[2];
    arr[0] = 7;
    arr[1] = 8; //*(arr+1) = 8;

    int * arr_ptr = arr;
    int * arr_ptr_0 = &arr[0];
    int * arr_ptr_1 = &arr[1];

    if((arr_ptr_0 + 1) == arr_ptr_1) {
        printf("ist gleich\n");
    }

    //--------------

    //Ausgabe aller Argumente auf der Konsole
    for(int i = 0; i < argc; i++) {
        printf("Argument %d: %s\n", i, argv[i]);

        //jedes Zeichen einzeln eingeben
        //Ende des Strings ist '\0'
        int j = 0;
        while(argv[i][j] != '\0') {
            printf("%c, ", argv[i][j]);
            j++;
        }
        printf("\n");
    }

    return 1;
}