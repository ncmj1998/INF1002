//
//  main.c
//  Wk8Lab_GuessInt
//
//  Created by Norman Chia on 26/10/21.
//

#include <stdio.h>
#define TOTALGUESS 10
#define MAXNUM 1000
#define LOWNUM 1

//a recursive function to get a valid input by player1.
int p1input(){
    int chosenNum;
    printf("Player 1, enter a number between 1 and 1000:\n");
    scanf("%d", &chosenNum);
    if (chosenNum<LOWNUM || chosenNum>MAXNUM){
        printf("That number is out of range.\n");
        chosenNum = p1input();
    }else{
        return chosenNum;
    }
    return chosenNum;
}

//recursive function to loop through the number of counts
int p2guess(int guessCount, int correctNum){
    if(guessCount == 0){
        printf("You have ran out of tries. The correct num is %d \n",correctNum);
    }else{
        int p2num;
        printf("Player 2, you have %d guesses remaining.\n",guessCount);
        printf("Enter your guess:\n");
        scanf("%d",&p2num);
        if(correctNum == p2num){
        printf("Player 2 wins.\n");
        return 1;
        }else{
            if(p2num>correctNum){
                printf("Too high.\n");
                guessCount = guessCount-1;
                p2guess(guessCount, correctNum);
            }else{
                printf("Too low.\n");
                guessCount = guessCount-1;
                p2guess(guessCount, correctNum);
            }
        }
    }
    return 0;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int num = p1input();
    p2guess(TOTALGUESS, num);

    
    return 0;
}
