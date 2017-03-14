#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void){
    printf("Number: ");
    long long card_number = get_long_long();
    char card_str[16];
    sprintf(card_str, "%lld", card_number);
    int card_sum = 0;
    int temp = 0;
    int card_length = strlen(card_str);
    for (int i = card_length; i >= 0; i-=2) {
        if (card_str[i] != 0) {
            temp = (card_str[i] - 48) * 2;
            if (temp > 9) {
                card_sum += 1 + (temp - 10);
            } else {
                card_sum += temp;
            }
        }
    }
    for (int j = card_length - 1; j >= 0; j-=2) {
        if (card_str[j] != 0) {
            temp = card_str[j] - 48;
            card_sum += temp;
        }
    }

    if (card_sum % 10 == 0) {
        if ((card_str[0] == '3') && (card_str[1] == '4' || card_str[1] == '7')) {
            printf("AMEX\n");
        } else if (card_str[0] == '4') {
            printf("VISA\n");
        } else if ((card_str[0] == '5') && (card_str[1] >= '1' || card_str[1] <= '5')) {
            printf("MASTERCARD\n");
        }
    } else {
        printf("INVALID\n");    
    }

}