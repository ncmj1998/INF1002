a//
//  main.c
//  Week10Lab_GuessWork
//
//  Created by Norman Chia on 9/11/21.
//

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXCHAR 12
#define GUESSES 10

void player1Input(void);
void appendList(char);
void removeIndex(int);
int player2Input(int guess);
int checkWord(char *);
int matchWord(char);
int checkBlank(char *);
char p1Word[MAXCHAR];
char p1Guess[MAXCHAR+MAXCHAR];
int validation;
int victory = 0;

int main(int argc, const char * argv[]) {
    
    player1Input();
    int totalGuess = GUESSES;
    while (totalGuess!=0){
        printf("\nPlayer 2 has so far guessed: %s\n",p1Guess);
        if(strcmp(p1Guess, p1Word)==0){
            puts("Player 2 wins.");
            victory = 1;
            break;
        }
        int result = player2Input(totalGuess);
//        printf("match result = %d\n",result);
        totalGuess = totalGuess - result;
    }
    if(victory == 0){
        printf("Player 1 wins. The word is %s.\n",p1Word);
    }
    return 0;
}

void player1Input(){
    printf("Player 1, enter a word of no more than 12 letters:\n");
    fgets(p1Word, MAXCHAR, stdin);
    p1Word[strlen(p1Word)-1] = '\0';
    validation = checkWord(p1Word);
printf("==>%s[%d]\n", p1Word, (int)strlen(p1Word));  // debug    
    if(validation == 0){
        puts("Sorry, the word must contain only english letter.\n");
        player1Input();
    }else{
        for(int i=0;i<strlen(p1Word);i++){
//            appendList('_');
//            appendList(' ');
            p1Guess[i]='_';

        }
    }
}
void appendList(char value){
    int size =strlen(p1Guess);
    p1Guess[size]= value;
}
int player2Input(int guess){
        int result =0;
        if(guess==0){
            printf("Player 1 wins. The word is %s.",p1Word);
        }else{
        char guessChar[1];
//        int result = matchWord(guessChar[0]);
        
            printf("Player 2 have %d guesses remaining. Enter your next guess: ",guess);
            scanf("%s",guessChar);
        
            int valid = isalpha(guessChar[0]);
        
            if(valid == 0){
                puts("Sorry, the word must contain only english letter.");
                player2Input(guess);
            }
            else{
                result = matchWord(guessChar[0]);
            }
        
        
    }
    return result;
}

int matchWord(char letter){
    int matched = 1;
    for(int i=0;i<strlen(p1Word);i++){
        if(letter==p1Word[i]){
            p1Guess[i] = letter;
     
            matched=0;
        }
    }
    return matched;
}

int checkBlank(char *word){
    int completed =1;
    for(int i=0;i<strlen(word);i++){
        if(word[i]=='_'){
            completed = 0;
        }
    }
    return completed;
    
}

int checkWord(char *word){
    int valid = 0;
    
    for(int i=0;i<strlen(word);i++){
        if(isalpha(word[i])!=0){
            valid =1;
            word[i]= tolower(word[i]);

        }else{
            valid =0;
            break;
        }
    }
    
    return valid;
}
