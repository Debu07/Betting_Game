//simple Betting Game Using  concept of memory allocation in stack frame
// Jack ,Queen , King -> Computer will shuffle these cards randomly using sran, random function by in C in time.h header file
//Player has to guess the position of the Queen in order to win the game from the positions (1,2 or 3)
//if he wins he take 3*betting amount
//if he losses he losses only bet amount
//player has 100$ initially

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int cash =100 ;  // global declaration
void play(int bet){
    char C[3]={'J','Q','K'}; // J-> Jack , Q->Queen , K-> King
    printf("Shuffling...");
    srand(time(NULL));
    int i;
    for(i=0;i<5;i++){
        int x= rand()%3;
        int y = rand()%3;
        int temp=C[x];
        C[x]=C[y];
        C[y]=temp;
    }
    int playerGuess;
    printf("Position of the queen? 1, 2 or 3");
    scanf("%d",&playerGuess);
    if(C[playerGuess - 1]=='Q'){
        cash+=3*bet;
        printf("YOU WIN !! Result = %c%c%c Total Cash %d",C[0],C[1],C[2],cash);
    }
    else {
        cash -= bet;
        printf("YOU LOOSE !! Result = %c%c%c Total Cash %d", C[0], C[1], C[2], cash);
    }
}
int main(){
    int bet;
    printf("Welcome to Virtual Casino\n\n");
    printf("Available Cash = %d \n",cash);

    while(cash>0){
        printf("what's your bet??");
        scanf("%d",&bet);
        if(bet==0 || bet>cash){
            break;
        }
        play(bet);
        printf("************************\n");
    }

}