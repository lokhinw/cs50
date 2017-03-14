#include <stdio.h>
#include <cs50.h>

int main(void){
    int height = 0;
    
    do {
        printf("Height: ");
        height = get_int();
        if (height == 0) {
            return 0;
        }
    } while (height < 1 || height > 23);
    
    for (int i = 0; i < height; i++) {
        
        for (int j = 0; j < height - i - 1 ; j++) {
            printf(" ");
        }
        
        for (int k = 0; k < i + 1; k++) {
            printf("#");
        }
        printf("  ");
        for (int l = 0; l < i + 1;l ++) {
            printf("#");
        }
        printf("\n");
        
    }
    
}