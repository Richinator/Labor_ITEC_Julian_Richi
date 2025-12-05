# Extract Methode

Ziel ist es Code in eine Methode auszulagern, so dass dieser Code an mehreren Stellen aufgerufen werden kann.

## Ausgangssituation

```c
int main(int argc, char* argv[]) {

    int x = 3;
    int y = 5;

    printf("x = %i, y = %i\n", x, y);

    int temp = x;
    x = y;
    y = temp;
    
    printf("Swap: x = %i, y = %i\n", x, y);
}
```

## Zielzustand

Aufgabe: Methode `swap`extrahieren, so dass man diese mehrmals verwenden kann.

```c
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(int argc, char* argv[]) {

    int x = 3;
    int y = 5;

    printf("Start: x = %i, y = %i\n", x, y);

    swap(&x , &y);

    printf("Swap: x = %i, y = %i\n", x, y);
}
```