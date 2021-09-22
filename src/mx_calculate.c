#include "header.h"

void mx_calculate(char *a, char *znak, char *b, char *result) {
    if (*znak == '?') {
        mx_calculate(a, "+", b, result);
        mx_calculate(a, "-", b, result);
        mx_calculate(a, "*", b, result);
        mx_calculate(a, "/", b, result);
        return;
    }
    int a_length = mx_strlen(a);
    int b_length = mx_strlen(b);
    int result_length = mx_strlen(result);
    if (*znak == '/' && *b == '0') {
        return;
    }
    bool a_neg = false;
    bool b_neg = false;
    bool result_neg = false;
    if (a[0] == '-') {
        a_neg = true;
        a_length--;
        a++;
    }
    if (b[0] == '-') {
        b_neg = true;
        b_length--;
        b++;
    }
    if (result[0] == '-') {
        result_neg = true;
        result_length--;
        result++;
    }
    int a_num = mx_atoi(a);
    int b_num = mx_atoi(b);
    int result_num = mx_atoi(result);
    long long max_a = mx_pow_rec(10, a_length);
    long long max_b = mx_pow_rec(10, b_length);
    long long max_result = mx_pow_rec(10, result_length);
    for (long long i = 0; i < max_a; i++) {
        if (a_num > 0) {
            i = a_num;
        }
        char *iqueue = mx_itoa(i);
        int ilen = mx_strlen(iqueue);
        bool iiscorrect = true;

        for (int j = 0; j < a_length - ilen; j++) {
            if (mx_isdigit(a[j]) && a[j] != '0') {
                iiscorrect = false;
                break;
            }
        }

        for (int j = a_length - ilen, k = 0; j < a_length; j++, k++) {
            if (a[j] != '?' && a[j] != iqueue[k]) {
                iiscorrect = false;
                break;
            }
        }

        free(iqueue);
        iqueue = NULL;
        if (!iiscorrect) {
            continue;
        }
        for (long long j = 0; j < max_b; j++) {
            if (b_num > 0) {
                j = b_num;
            }
            char *jqueue = mx_itoa(j);
            int jlen = mx_strlen(jqueue);
            bool jiscorrect = true;

            for (int p = 0; p < b_length - jlen; p++) {
                if (mx_isdigit(b[p]) && b[p] != '0') {
                    jiscorrect = false;
                    break;
                }
            }

            for (int p = b_length - jlen, jqueue_i = 0; p < b_length; p++, jqueue_i++) {
                if (b[p] != '?' && b[p] != jqueue[jqueue_i]) {
                    jiscorrect = false;
                    break;
                }
            }

            free(jqueue);
            jqueue = NULL;
            if (!jiscorrect) {
                continue;
            }

            for (long long k = 0; k < max_result; k++) {
                if (result_num > 0) {
                    k = result_num;
                }
                char *kqueue = mx_itoa(k);
                int kqueue_len = mx_strlen(kqueue);
                bool isCorrectK = true;

                for (int n = 0; n < result_length - kqueue_len; n++) {
                    if (mx_isdigit(result[n]) && result[n] != '0') {
                        isCorrectK = false;
                        break;
                    }
                }

                for (int n = result_length - kqueue_len, kqueue_i = 0; n < result_length; n++, kqueue_i++) {
                    if (result[n] != '?' && result[n] != kqueue[kqueue_i]) {
                        isCorrectK = false;
                        break;
                    }
                }

                free(kqueue);
                kqueue = NULL;
                if (!isCorrectK) {
                    continue;
                }
                if (a_neg == true) {
                    i *= -1;
                }
                if (b_neg == true) {
                    j *= -1;
                }
                if (a_neg == true) {
                    k *= -1;
                }
                if (*znak == '+' && (i + j == k)) {
                    mx_printint(i);
                    mx_printstr(" + ");
                    mx_printint(j);
                    mx_printstr(" = ");
                    mx_printint(k);
                    mx_printchar('\n');
                }
                else if (*znak == '-' && (i - j == k)) {
                    mx_printint(i);
                    mx_printstr(" - ");
                    mx_printint(j);
                    mx_printstr(" = ");
                    mx_printint(k);
                    mx_printchar('\n');
                }
                else if (*znak == '*' && (i * j == k)) {
                    mx_printint(i);
                    mx_printstr(" * ");
                    mx_printint(j);
                    mx_printstr(" = ");
                    mx_printint(k);
                    mx_printchar('\n');
                }
                else if (j != 0 && *znak == '/' && (i / j == k)) {
                    mx_printint(i);
                    mx_printstr(" / ");
                    mx_printint(j);
                    mx_printstr(" = ");
                    mx_printint(k);
                    mx_printchar('\n');
                }
                if (a_neg == true) {
                    i *= -1;
                }
                if (b_neg == true) {
                    j *= -1;
                }
                if (a_neg == true) {
                    k *= -1;
                }
                if (result_num > 0) {
                    break;
                }
            }
            if (b_num > 0) {
                break;
            }
        }
        if (a_num > 0) {
            break;
        }
    }
    if (a_neg == true) {
        a--;
    }
    if (b_neg == true) {
        b--;
    }
    if (result_neg == true) {
        result--;
    }
}
