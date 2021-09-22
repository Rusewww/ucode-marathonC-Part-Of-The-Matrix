#include "header.h"

char *mx_strdup(const char *str) {
    int len = mx_strlen(str);
    char *str2 = mx_strnew(len);
    str2 = mx_strcpy(str2, str);
    return str2;
}
