//
//  main.c
//  ICT_Week11_Lab
//
//  Created by Norman Chia on 18/11/21.
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_LENGTH 32

struct word {
    char *word;
    struct word *next;
};

typedef struct word Word;
typedef Word * WordPtr;

int main(){
    WordPtr head = NULL;
    int com = 0;

    while(!com){
        char *word = (char *) calloc(MAX_LENGTH, sizeof(char));
        printf("Please enter a word:\n");
        fgets(word, MAX_LENGTH, stdin);
        word[strlen(word)-1] = '\0';
        if (strcmp(word, "***") == 0) {
            com = 1;
            break;
        }
        int invalid = 0;
        //Check for only alphabets
        for (int i = 0; (i < strlen(word)) && !invalid; i++){
            if (isalpha(word[i])) {
                word[i] = tolower(word[i]);
            }else{
                invalid = 1;
                break;
            }
        }
        
        if (invalid) {
            printf("Invalid character entered\n");
            continue;
        }
        
        //Compare and arrange
        WordPtr current = (WordPtr) calloc(2, sizeof(Word));
        current->word = word;
        current->next = NULL;

        if (head == NULL) {
            head = current;
            continue;
        }

        WordPtr tempPtr = head;
        WordPtr prevptr = NULL;
        int exist = 0;
        while (tempPtr != NULL) {
            if (strcmp(word, tempPtr->word) < 0) {
                exist = 1;
                if (prevptr == NULL){
                    current->next = head;
                    head = current;
                } else {
                    current->next = tempPtr;
                    prevptr->next = current;
                }
                break;
            }
            prevptr = tempPtr;
            tempPtr = tempPtr->next;
        }

        if (!exist) {
            prevptr->next = current;
        }
    };

    printf("All the entered words in order:\n");
    WordPtr current = head;
    while (current != NULL) {
        printf("%s\n", current->word);
        current = current->next;
    }

    return 0;
}
