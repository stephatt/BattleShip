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

void main()
{
    void outputmap(int line);
    outputmap(10);
    void planePlayer(int head);
    printf("input your plane's head is:");
    scanf("%d",&headPlayer);
    planePlayer(headPlayer);
    //headComputer=rand()%100;
    //planePlayer(headComputer,computerPlayer[10][10]);
    
    
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
void planePlayer(int head)
{
    humanPlayer[(int)(head/10)][head%10-1]=0;
    int angel;
    printf("choose the angel of your plane,0,90,180 or 270:");
    scanf("%d",&angel);
    switch (angel) {
        case 0:
            for (int i=1; i<=4; i++) {
                humanPlayer[(int)(head/10)+i][head%10-1]=0;
                if (i==1) {
                    for (int j=1; j<=2; j++) {
                        humanPlayer[(int)(head/10)+i][head%10-1-j]=0;
                        humanPlayer[(int)(head/10)+i][head%10-1+j]=0;
                    }
                }
                if (i==4) {
                    humanPlayer[(int)(head/10)+i][head%10-1-1]=0;
                    humanPlayer[(int)(head/10)+i][head%10-1+1]=0;
                }
            }
            
            
            break;
        case 90:
            for (int i=1; i<=4; i++) {
                humanPlayer[(int)(head/10)][head%10-1-i]=0;
                if (i==1) {
                    for (int j=1; j<=2; j++) {
                        humanPlayer[(int)(head/10)-j][head%10-1-i]=0;
                        humanPlayer[(int)(head/10)+j][head%10-1-i]=0;
                    }
                }
                if (i==4) {
                    humanPlayer[(int)(head/10)-1][head%10-1-i]=0;
                    humanPlayer[(int)(head/10)+1][head%10-1-i]=0;
                }
            }
            
            
            break;
        case 180:
            for (int i=1; i<=4; i++) {
                humanPlayer[(int)(head/10)+i][head%10-1]=0;
                if (i==1) {
                    for (int j=1; j<=2; j++) {
                        humanPlayer[(int)(head/10)-i][head%10-1-j]=0;
                        humanPlayer[(int)(head/10)-i][head%10-1+j]=0;
                    }
                }
                if (i==4) {
                    humanPlayer[(int)(head/10)-i][head%10-1-1]=0;
                    humanPlayer[(int)(head/10)-i][head%10-1+1]=0;
                }
            }
            
            
            break;
        case 270:
            for (int i=1; i<=4; i++) {
                humanPlayer[(int)(head/10)][head%10-1+i]=0;
                if (i==1) {
                    for (int j=1; j<=2; j++) {
                        humanPlayer[(int)(head/10)-j][head%10-1+i]=0;
                        humanPlayer[(int)(head/10)+j][head%10-1+i]=0;
                    }
                }
                if (i==4) {
                    humanPlayer[(int)(head/10)-1][head%10-1+i]=0;
                    humanPlayer[(int)(head/10)+1][head%10-1+i]=0;
                }
            }
            
            
            break;
            
        default:
            break;
    }
    for (int i=0; i<10; i++) {
        for (int j=0; j<10; j++) {
            printf("%d",humanPlayer[i][j]);
            printf("\t");
        }
        printf("\n");
    }
}