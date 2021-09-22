#include "header.h"

int main(int argc, char *argv[]) {
    if (argc != 5) {
        mx_printerr("usage: ./part_of_the_matrix [operand1] [operation] [operand2] [result]\n");
        return 1;
    }
    char *a = mx_strtrim(argv[1]);
    char *znak = mx_strtrim(argv[2]);
    char *b = mx_strtrim(argv[3]);
    char *result = mx_strtrim(argv[4]);
    mx_checking(argv, a, znak, b, result);
    mx_calculate(a, znak, b, result);

    free(a);
    free(znak);
    free(b);
    free(result);

    return 0;
}
