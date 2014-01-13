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
int angelPlayer;

void main()
{
    void outputmapA(int line);
    void outputmapB(int line);
    
    void headHuman();
    void headCom();
    
    void planePlayer(int head,int player[10][10]);
    void planeComputer(int head,int player[10][10]);
    headHuman();
    headCom();
    
    void guess();
    guess();
   
        
        
}

/*给出图纸坐标*/
void outputmapA(int line)
{
    for (int i=1; i<=100; i++) {
        
        humanPlayer[(int)(i/10)][i%10-1]=i;
        printf("%d",i);
        printf("\t");  //使数字对齐输出
        if (i%10==0) {
            printf("\n");
        }
        else continue;
    }
}

void outputmapB(int line)
{
    for (int i=1; i<=100; i++) {
        computerPlayer[(int)(i/10)][i%10-1]=i;
        printf("%d",i);
        printf("\t");  //使数字对齐输出
        if (i%10==0) {
            printf("\n");
        }
        else continue;
    }
}

/*玩家定义飞机中部*/
void headHuman()
{
    outputmapA(10);
    printf("input your plane's center is:");
    scanf("%d",&headPlayer);
    planePlayer(headPlayer,humanPlayer);
}

/*电脑定义飞机中部*/
void headCom()
{
    outputmapB(10);
    srand((unsigned long)time(NULL));
    headComputer=rand()%100;
    //int angel=90*rand()%4;
    planeComputer(headComputer,computerPlayer);
}

/*用户画飞机*/
void planePlayer(int head,int player[10][10])
{
    
    player[(int)(head/10)][head%10-1]=0;
    printf("choose the angel of plane,0,90,180 or 270:");
    scanf("%d",&angelPlayer);
    switch (angelPlayer) {
        case 0:
            for (int i=1; i<=2; i++) {
                if ((int)(head/10)+i>9||(int)(head/10)-i<0) {
                    printf("you draw the wrong place");
                    printf("\n");
                    headHuman();
                    break;
                }
                player[(int)(head/10)-i][head%10-1]=0;
                player[(int)(head/10)+i][head%10-1]=0;
                if (i==1) {
                    for (int j=1; j<=2; j++) {
                        if (head%10-1-j<0||head%10-1+j>9) {
                            printf("you draw the wrong place");
                            printf("\n");
                            headHuman();
                            break;
                        }
                        player[(int)(head/10)-i][head%10-1-j]=0;
                        player[(int)(head/10)-i][head%10-1+j]=0;
                    }
                }
                if (i==2) {
                    player[(int)(head/10)+i][head%10-1-1]=0;
                    player[(int)(head/10)+i][head%10-1+1]=0;
                }
            }
            
            
            break;
        case 90:
            for (int i=1; i<=2; i++) {
                if (head%10-1-i<0||head%10-1+i>9) {
                    printf("you draw the wrong place");
                    printf("\n");
                    headHuman();
                    break;
                }
                player[(int)(head/10)][head%10-1-i]=0;
                player[(int)(head/10)][head%10-1+i]=0;
                if (i==1) {
                    for (int j=1; j<=2; j++) {
                        if ((int)(head/10)-j<0||(int)(head/10)+j>9) {
                            printf("you draw the wrong place");
                            printf("\n");
                            headHuman();
                            break;
                        }
                        player[(int)(head/10)-j][head%10-1+i]=0;
                        player[(int)(head/10)+j][head%10-1+i]=0;
                    }
                }
                if (i==2) {
                    player[(int)(head/10)-1][head%10-i-1]=0;
                    player[(int)(head/10)+1][head%10-i-1]=0;
                }
            }
            
            
            break;
        case 180:
            for (int i=1; i<=2; i++) {
                if ((int)(head/10)+i>9||(int)(head/10)-i<0) {
                    printf("you draw the wrong place");
                    printf("\n");
                    headHuman();
                    break;
                }
                player[(int)(head/10)-i][head%10-1]=0;
                player[(int)(head/10)+i][head%10-1]=0;
                if (i==1) {
                    for (int j=1; j<=2; j++) {
                        if (head%10-1-j<0||head%10-1+j>9) {
                            printf("you draw the wrong place");
                            printf("\n");
                            headHuman();
                            break;
                        }
                        player[(int)(head/10)+i][head%10-1+j]=0;
                        player[(int)(head/10)+i][head%10-1-j]=0;
                    }
                }
                if (i==2) {
                    player[(int)(head/10)-i][head%10-1-1]=0;
                    player[(int)(head/10)-i][head%10-1+1]=0;
                }
            }
            
            
            break;
        case 270:
            for (int i=1; i<=2; i++) {
                if (head%10-1-i<0||head%10-1+i>9) {
                    printf("you draw the wrong place");
                    printf("\n");
                    headHuman();
                    break;
                }
                player[(int)(head/10)][head%10-i-1]=0;
                player[(int)(head/10)][head%10+i-1]=0;
                if (i==1) {
                    for (int j=1; j<=2; j++) {
                        if ((int)(head/10)-j<0||(int)(head/10)+j>9) {
                            printf("you draw the wrong place");
                            printf("\n");
                            headHuman();
                            break;
                        }
                        player[(int)(head/10)-j][head%10-i-1]=0;
                        player[(int)(head/10)+j][head%10-i-1]=0;
                    }
                }
                if (i==2) {
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


/*电脑画飞机*/
void planeComputer(int head,int player[10][10])
{
    
    player[(int)(head/10)][head%10-1]=0;
    int angel;
    srand((unsigned long)time(NULL));
    int b[4]={0,1,2,3};
    int m=rand()%4;
    angel=b[m];
    angel*=90;
    printf("%d",angel);
    printf("\n");
    switch (angel) {
        case 0:
            for (int i=1; i<=2; i++) {
                if ((int)(head/10)+i>9||(int)(head/10)-i<0) {
                    printf("you draw the wrong place");
                    printf("\n");
                    headCom();
                    break;
                }
                player[(int)(head/10)-i][head%10-1]=0;
                player[(int)(head/10)+i][head%10-1]=0;
                if (i==1) {
                    for (int j=1; j<=2; j++) {
                        if (head%10-1-j<0||head%10-1+j>9) {
                            printf("you draw the wrong place");
                            printf("\n");
                            headCom();
                            break;
                        }
                        player[(int)(head/10)-i][head%10-1-j]=0;
                        player[(int)(head/10)-i][head%10-1+j]=0;
                    }
                }
                if (i==2) {
                    player[(int)(head/10)+i][head%10-1-1]=0;
                    player[(int)(head/10)+i][head%10-1+1]=0;
                }
            }
            
            
            break;
        case 90:
            for (int i=1; i<=2; i++) {
                if (head%10-1-i<0||head%10-1+i>9) {
                    printf("you draw the wrong place");
                    printf("\n");
                    headCom();
                    break;
                }
                player[(int)(head/10)][head%10-1-i]=0;
                player[(int)(head/10)][head%10-1+i]=0;
                if (i==1) {
                    for (int j=1; j<=2; j++) {
                        if ((int)(head/10)-j<0||(int)(head/10)+j>9) {
                            printf("you draw the wrong place");
                            printf("\n");
                            headCom();
                            break;
                        }
                        player[(int)(head/10)-j][head%10-1+i]=0;
                        player[(int)(head/10)+j][head%10-1+i]=0;
                    }
                }
                if (i==2) {
                    player[(int)(head/10)-1][head%10-i-1]=0;
                    player[(int)(head/10)+1][head%10-i-1]=0;
                }
            }
            
            
            break;
        case 180:
            for (int i=1; i<=2; i++) {
                if ((int)(head/10)+i>9||(int)(head/10)-i<0) {
                    printf("you draw the wrong place");
                    printf("\n");
                    headCom();
                    break;
                }
                player[(int)(head/10)-i][head%10-1]=0;
                player[(int)(head/10)+i][head%10-1]=0;
                if (i==1) {
                    for (int j=1; j<=2; j++) {
                        if (head%10-1-j<0||head%10-1+j>9) {
                            printf("you draw the wrong place");
                            printf("\n");
                            headCom();
                            break;
                        }
                        player[(int)(head/10)+i][head%10-1+j]=0;
                        player[(int)(head/10)+i][head%10-1-j]=0;
                    }
                }
                if (i==2) {
                    player[(int)(head/10)-i][head%10-1-1]=0;
                    player[(int)(head/10)-i][head%10-1+1]=0;
                }
            }
            
            
            break;
        case 270:
            for (int i=1; i<=2; i++) {
                if (head%10-1-i<0||head%10-1+i>9) {
                    printf("you draw the wrong place");
                    printf("\n");
                    headCom();
                    break;
                }
                player[(int)(head/10)][head%10-i-1]=0;
                player[(int)(head/10)][head%10+i-1]=0;
                if (i==1) {
                    for (int j=1; j<=2; j++) {
                        if ((int)(head/10)-j<0||(int)(head/10)+j>9) {
                            printf("you draw the wrong place");
                            printf("\n");
                            headCom();
                            break;
                        }
                        player[(int)(head/10)-j][head%10-i-1]=0;
                        player[(int)(head/10)+j][head%10-i-1]=0;
                    }
                }
                if (i==2) {
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



/*用户猜飞机*/
int AbattlePlane(int guess)
{
    if (computerPlayer[(int)(guess/10)][guess%10-1]==0&&(guess==headComputer-20||guess==headComputer-10||guess==headComputer-2||guess==headComputer+2)) {
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
        return 2;
    }
}

/*电脑猜飞机*/
int BbattlePlane(int guess)
{
    if (humanPlayer[(int)(guess/10)][guess%10-1]==0&&(guess==headPlayer-20||guess==headPlayer-10||guess==headPlayer-2||guess==headPlayer+2)) {
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
        return 2;
    }
}

void guess()
{
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
        else if (i==1&&j==2){
            computerGuess=headPlayer;
        }
        else if (j==1){
            int a[21]={headPlayer-21,headPlayer-20,headPlayer-19,headPlayer-12,headPlayer-11,headPlayer-10,headPlayer-9,headPlayer-8,headPlayer-2,headPlayer-1,headPlayer,headPlayer+1,headPlayer+2,headPlayer+8,headPlayer+9,headPlayer+10,headPlayer+11,headPlayer+12,headPlayer+19,headPlayer+20,headPlayer+21};
            int x=rand()%21;
            computerGuess=a[x];
            printf("%d",computerGuess);
        }
    }
}

