#include <stdio.h>
#include <stdlib.h>
#include<time.h>
int cash=100;
void Play(int bet){
    char *c=(char*)malloc(3*sizeof(char));
    c[0]='J'; c[1]='Q'; c[2]='K';
    printf("shuffling...\n");
    srand(time(NULL));
    int i;
    for(i=0;i<5;i++){
        int x =rand() %3;
        int y =rand() %3;
        int temp=c[x];
        c[x]=c[y];
        c[y]=temp;
    }
    int playersGuess;
    printf("Guess the position of Queen-1,2 0r 3\n");
    scanf("%d",&playersGuess);
    if(c[playersGuess-1]=='Q'){
        cash+=3*bet;
        printf("Result -> %c %c %c \n YOU WIN !!\n  Cash = %d\n",c[0],c[1],c[2],cash);
    }
    else{
            cash-=bet;
        printf("Result -> %c %c %c \n YOU LOOSE !!\n  Cash = %d\n",c[0],c[1],c[2],cash);
    }
    free(c); // to  avoid memory leak

}
int main()
{
    int bet;
    printf("*** WELCOME TO ROYAL CASINO ***\n");
    printf("You have : $%d\n",cash);
    while(cash>0){
        printf("What's Your bet?? $");
        scanf("%d",&bet);
        if(bet==0||bet>cash) break;
        Play(bet);
        printf("*****************************\n");
    }
    return 0;
}
