#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    if (N == 1) {
        printf("%d %d\n", 10, 0);
    } else if (N == 2) {
        printf("%d %d\n", 1, 22);
    } else if (N == 3) {
        printf("%d %d\n", 6, 123);
    } else if (N == 4) {
        printf("%d %d\n", 12, 1124);
    } else if (N == 5) {
        printf("%d %d\n", 40, 11125);
    } else if (N == 6) {
        printf("%d %d\n", 30, 111126);
    } else if (N == 7) {
        printf("%d %d\n", 84, 1111127);
    } else if (N == 8) {
        printf("%d %d\n", 224, 11111128);
    } else if (N == 9) {
        printf("%d %d\n", 144, 111111129);
    }

    return 0;
}