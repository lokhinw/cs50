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
    string k = argv[1];
    for (int i = 0, n = strlen(argv[1]); i < n; i++) {
        if (isdigit(k[i])) {
            printf("cannot contain numbers\n");
            return 1;
        }
    }
    printf("plaintext:  ");
    string p = get_string();
    printf("ciphertext: ");
    int j = 0;
    for (int i = 0, n = strlen(p); i < n; i++) {
        if (isalpha(p[i])) {
            if (isupper(p[i])) {
                if (isupper(k[j % strlen(k)])) {
                    printf("%c", 65 + (p[i] - 65 + (k[j % strlen(k)] - 65)) % 26);    
                } else {
                    printf("%c", 65 + (p[i] - 97 + (k[j % strlen(k)] - 65)) % 26);    
                }
            } else {
                if (isupper(k[j % strlen(k)])) {
                    printf("%c", 97 + (p[i] - 65 + (k[j % strlen(k)] - 97)) % 26);    
                } else {
                    printf("%c", 97 + (p[i] - 97 + (k[j % strlen(k)] - 97)) % 26);    
                }
            }
        j++;
        } else {
            printf("%c", p[i]);
        }
    }
    printf("\n");
    return 0;
}