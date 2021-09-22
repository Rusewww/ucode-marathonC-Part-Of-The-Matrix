#include "../inc/header.h"

void mx_checking(char *argv[], char *a, char *znak, char *b, char *result) {
    if (mx_strlen(a) < 1) {
        mx_printerr("Invalid operand: ");
        mx_printerr(argv[1]);
        mx_printerr("\n");
        exit(-1);
    }
    if (mx_strlen(znak) != 1 || (*znak != '?' && *znak != '+'
        && *znak != '-' && *znak != '*' && *znak != '/')) {
        mx_printerr("Invalid operation: ");
        mx_printerr(argv[2]);
        mx_printerr("\n");
        exit(-1);
    }
    if (mx_strlen(b) < 1) {
        mx_printerr("Invalid operand: ");
        mx_printerr(argv[3]);
        mx_printerr("\n");
        exit(-1);
    }
    if (mx_strlen(result) < 1) {
        mx_printerr("Invalid result: ");
        mx_printerr(argv[4]);
        mx_printerr("\n");
        exit(-1);
    }

    for (int i = 0; i < mx_strlen(a); i++) {
        if (i == 0 && a[i] == '-') {
            continue;
        }
        else if (a[i] != '?' && mx_isdigit(a[i]) == false) {
            mx_printerr("Invalid operand: ");
            mx_printerr(argv[1]);
            mx_printerr("\n");
            exit(-1);
        }
    }

    for (int i = 0; i < mx_strlen(b); i++) {
        if (i == 0 && b[i] == '-') {
            continue;
        }
        else if (b[i] != '?' && mx_isdigit(b[i]) == false) {
            mx_printerr("Invalid operand: ");
            mx_printerr(argv[3]);
            mx_printerr("\n");
            exit(-1);
        }
    }

    for (int i = 0; i < mx_strlen(result); i++) {
        if (i == 0 && result[i] == '-') {
            continue;
        }
        else if (result[i] != '?' && mx_isdigit(result[i]) == false) {
            mx_printerr("Invalid operand: ");
            mx_printerr(argv[4]);
            mx_printerr("\n");
            exit(-1);
        }
    }

}
