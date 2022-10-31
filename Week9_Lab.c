//
//  main.c
//  Week9_Lab_Assignment
//
//  Created by Norman Chia on 2/11/21.
//

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXLEN 255

int matchPattern(char text[],char pattern[],int sen);
int matched = 0;
int main(int argc, const char * argv[]) {

    // ask to enter line of text of up to 255 char
    char sentence[MAXLEN];
    printf("Enter a sentence, up to 255 characters:");
    fgets(sentence, MAXLEN, stdin);
    sentence[strlen(sentence)-1] = '\0';
    
    char pattern[MAXLEN];
    printf("\nEnter a pattern, up to 255 characters:");
    fgets(pattern, MAXLEN, stdin);
    pattern[strlen(pattern)-1] = '\0';

    printf("%s, %s", sentence, pattern);

  
    int sensitive;
    printf("\nInput 1 for case sensitive, 0 for case insensitive.\n");
    scanf("%d",&sensitive);
    
    //call function
    int out= -1;
    out=matchPattern(sentence,pattern,sensitive);
    if(matched == 0){
        printf("No match.");
    }else{
        printf("Matches at position %d\n",out);
    }
}

//The cat sat on the mat.
int matchPattern(char text[],char pattern[],int sen){
    int ret=0;
    int dotcount=0;
    
    // check if there is any _ present in p
    if (strchr(pattern, '_')){
        //if found, change spaces in text to _
        for (int i=0;i<strlen(text);i++){
            if (text[i]==' '){
                text[i]='_';
            }
        }
    }
    // if case insensitive
    if (sen==0){
        for (int i=0;i<strlen(text);i++){
            text[i]= tolower(text[i]);
        }
    }

    for (int i=0;i<strlen(pattern);i++){
        for (int j=0;j<strlen(text);j++){
         if (pattern[i] == text[j]){
                text=text+j;
                ret = strncmp(text,pattern,strlen(pattern));
                if (ret==0){
                    matched = 1;
                    return j-dotcount;
                }
                text=text-j;
            }else if (pattern[i]== '.'){
                ++dotcount;
                pattern = pattern+1;
            }
        }
    }
    return 0;
}
