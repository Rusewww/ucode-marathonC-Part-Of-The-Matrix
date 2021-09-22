#include "header.h"

/*char *mx_strtrim(const char *str) {
    if (str == NULL) {
        return NULL;
    }

    int begin = 0;
    while (*str && mx_isspace(*str)) {
        str++;
        begin++;
    }
    str = str - begin;

    int last = mx_strlen(str);
    while (mx_isspace(str[last])) {
        last--;
    }

    char *res = mx_strnew(last + 1 - begin);
    for (int i = begin, j = 0; i <= last + 1 - begin; i++, j++) {
        res[j] = str[i];
    }
    return res;
}*/

char *mx_strtrim(const char *str) {
    if (str == NULL) {
        return NULL;
    }

    int begin = 0;
    while (*str && mx_isspace(*str)) {
        str++;
        begin++;
    }
    str = str - begin;

    int last = mx_strlen(str) - 1;
    while (mx_isspace(str[last])) {
        last--;
    }

    char *res = mx_strnew(last + 1 - begin);
    for (int i = 0; i < last + 1 - begin; i++) {
        res[i] = str[i + begin];
    }
    return res;
}
