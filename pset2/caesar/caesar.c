#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[]) {
    if (argc != 2) {
        printf("missing command-line arguments\n");
        return 1;
    }
    int k = atoi(argv[1]);
    printf("plaintext:  ");
    string p = get_string();
    printf("ciphertext: ");
    for (int i = 0, n = strlen(p); i < n; i++) {
        if (isalpha(p[i])) {
            if (isupper(p[i])) {
                printf("%c", 65 + (p[i] - 65 + k) % 26);
            } else {
                printf("%c", 97 + (p[i] - 97 + k) % 26);
            }
        } else {
            printf("%c", p[i]);
        }
    }
    printf("\n");
    return 0;
}