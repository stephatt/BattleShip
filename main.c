//
//  main.c
//  BattleShip
//
//  Created by Tong Tingting on 14-1-2.
//  Copyright (c) 2014年 Tong Tingting. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>


int computerPlayer[10][10]={0};
int humanPlayer[10][10]={0};

int headComputer;
int headPlayer;
int playerGuess;
int computerGuess;


void main()
{
    void outputmap(int line);
    outputmap(10);
    
    void planePlayer(int head,int player[10][10]);
    printf("input your plane's head is:");
    scanf("%d",&headPlayer);
    planePlayer(headPlayer,humanPlayer);
    srand((unsigned long)time(NULL));
    headComputer=rand()%100;
    planePlayer(headComputer,computerPlayer);
    
    int AbattlePlane(int guess);
    int BbattlePlane(int guess);
    srand((unsigned long)time(NULL));
    computerGuess=rand()%100;
    for (int i=1,j=1;;) {
        printf("Your turn to guess where is the plane:");
        scanf("%d",&playerGuess);
        i=AbattlePlane(playerGuess);
        j=BbattlePlane(computerGuess);
        if (i==0||j==0) {
            break;
        }
    }
        
        
}

/*给出图纸坐标*/
void outputmap(int line)
{
    for (int i=1; i<=100; i++) {
        computerPlayer[(int)(i/10)][i%10-1]=i;
        humanPlayer[(int)(i/10)][i%10-1]=i;
        printf("%d",i);
        printf("\t");  //使数字对齐输出
        if (i%10==0) {
            printf("\n");
        }
        else continue;
    }
}

/*画飞机*/
void planePlayer(int head,int player[10][10])
{
    player[(int)(head/10)][head%10-1]=0;
    int angel;
    printf("choose the angel of your plane,0,90,180 or 270:");
    scanf("%d",&angel);
    switch (angel) {
        case 0:
            for (int i=1; i<=4; i++) {
                player[(int)(head/10)+i][head%10-1]=0;
                if (i==1) {
                    for (int j=1; j<=2; j++) {
                        player[(int)(head/10)+i][head%10-1-j]=0;
                        player[(int)(head/10)+i][head%10-1+j]=0;
                    }
                }
                if (i==4) {
                    player[(int)(head/10)+i-1][head%10-1-1]=0;
                    player[(int)(head/10)+i-1][head%10-1+1]=0;
                }
            }
            
            
            break;
        case 90:
            for (int i=1; i<=4; i++) {
                player[(int)(head/10)][head%10-i]=0;
                if (i==1) {
                    for (int j=1; j<=2; j++) {
                        player[(int)(head/10)-j][head%10-1-i]=0;
                        player[(int)(head/10)+j][head%10-1-i]=0;
                    }
                }
                if (i==4) {
                    player[(int)(head/10)-1][head%10-i]=0;
                    player[(int)(head/10)+1][head%10-i]=0;
                }
            }
            
            
            break;
        case 180:
            for (int i=1; i<=3; i++) {
                player[(int)(head/10)-i][head%10-1]=0;
                if (i==1) {
                    for (int j=1; j<=2; j++) {
                        player[(int)(head/10)-i][head%10-1-j]=0;
                        player[(int)(head/10)-i][head%10-1+j]=0;
                    }
                }
                if (i==3) {
                    player[(int)(head/10)-i][head%10-1-1]=0;
                    player[(int)(head/10)-i][head%10-1+1]=0;
                }
            }
            
            
            break;
        case 270:
            for (int i=1; i<=3; i++) {
                player[(int)(head/10)][head%10+i-1]=0;
                if (i==1) {
                    for (int j=1; j<=2; j++) {
                        player[(int)(head/10)-j][head%10+i-1]=0;
                        player[(int)(head/10)+j][head%10+i-1]=0;
                    }
                }
                if (i==3) {
                    player[(int)(head/10)-1][head%10+i-1]=0;
                    player[(int)(head/10)+1][head%10+i-1]=0;
                }
            }
            
            
            break;
            
        default:
            break;
    }
    for (int i=0; i<10; i++) {
        for (int j=0; j<10; j++) {
            printf("%d",player[i][j]);
            printf("\t");
        }
        printf("\n");
    }
}

/*用户猜数打飞机*/
int AbattlePlane(int guess)
{
    if (computerPlayer[(int)(guess/10)][guess%10-1]==0&computerPlayer[(int)(guess/10)-1][guess%10-1]!=0&computerPlayer[(int)(guess/10)][guess%10+1]!=0) {
        printf("RIGHT");
        printf("\n");
        return 0;
    }
    else if (computerPlayer[(int)(guess/10)][guess%10-1]==0){
        printf("NEARLY");
        printf("\n");
        return 1;
    }
    else if (computerPlayer[(int)(guess/10)][guess%10-1]!=0){
        printf("BAD");
        printf("\n");
        return 1;
    }
}

/*电脑猜飞机*/
int BbattlePlane(int guess)
{
    if (humanPlayer[(int)(guess/10)][guess%10-1]==0&humanPlayer[(int)(guess/10)-1][guess%10-1]!=0&humanPlayer[(int)(guess/10)][guess%10]!=0) {
        printf("RIGHT");
        printf("\n");
        return 0;
    }
    else if (humanPlayer[(int)(guess/10)][guess%10-1]==0){
        printf("NEARLY");
        printf("\n");
        return 1;
    }
    else if (humanPlayer[(int)(guess/10)][guess%10-1]!=0){
        printf("BAD");
        printf("\n");
        return 1;
    }
}

