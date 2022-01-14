//Author: Garrett Giddings | Date:5/30/2020
#include <stdio.h>

int main(void) {
    int total = 0, words = 1;
    char word;
    
    printf("Enter a sentence: ");

    while((word = getchar()) != '\n') {
        if(word == ' ') {

            words++;

        } else {

            total++;

        }
    }

    printf("Average word length: %.1f\n", total/(float)words);
    return 0;
}