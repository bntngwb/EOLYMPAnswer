#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int rdecode(char c) {
    switch (c) {
        case 'M':
            return 1000;
        case 'D':
            return 500;
        case 'C':
            return 100;
        case 'L':
            return 50;
        case 'X':
            return 10;
        case 'V':
            return 5;
        case 'I':
            return 1;
        default:
            return 0;
    }
}

char* encode_roman(int x) {
    char* ret = (char*)malloc(100 * sizeof(char));
    int i = 0;
    while (x > 0) {
        if (x >= 1000) {
            strcat(ret, "M");
            x -= 1000;
        } else if (x >= 900) {
            strcat(ret, "CM");
            x -= 900;
        } else if (x >= 500) {
            strcat(ret, "D");
            x -= 500;
        } else if (x >= 400) {
            strcat(ret, "CD");
            x -= 400;
        } else if (x >= 100) {
            strcat(ret, "C");
            x -= 100;
        } else if (x >= 90) {
            strcat(ret, "XC");
            x -= 90;
        } else if (x >= 50) {
            strcat(ret, "L");
            x -= 50;
        } else if (x >= 40) {
            strcat(ret, "XL");
            x -= 40;
        } else if (x >= 10) {
            strcat(ret, "X");
            x -= 10;
        } else if (x >= 9) {
            strcat(ret, "IX");
            x -= 9;
        } else if (x >= 5) {
            strcat(ret, "V");
            x -= 5;
        } else if (x >= 4) {
            strcat(ret, "IV");
            x -= 4;
        } else if (x >= 1) {
            strcat(ret, "I");
            x -= 1;
        }
    }
    return ret;
}

int decode_roman(char* roman) {
    int result = 0;
    int length = strlen(roman);
    for (int i = 0; i < length - 1; i++) {
        int rd = rdecode(roman[i]);
        int rd1 = rdecode(roman[i + 1]);
        result += (rd < rd1) ? -rd : rd;
    }
    result += rdecode(roman[length - 1]);
    return result;
}

int main() {
    char input[100];
    scanf("%s", input);
    char a[50];
    char b[50];
    sscanf(input, "%[^+]+%s", a, b);
    int a_decoded = decode_roman(a);
    int b_decoded = decode_roman(b);
    int result = a_decoded + b_decoded;
    char* encoded_result = encode_roman(result);
    printf("%s\n", encoded_result);
    free(encoded_result);
    return 0;
}
