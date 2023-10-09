#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int childAge, cost, boardchoice, categorychoice, activityCount, TP, IS, CC=0, BC=0; //Declaration of global variables.
int transportReq, international;
char parentName[30];
char board[3][5]={"ICSE", "CBSE", "STATE"};
char categor[2][8]={"Stable", "Needy"};

void menu() {
    printf("\nPlease fill out these questions to help us assess the cost of your child's education. \n");
    printf("\nDoes your ward require transportation? [True --> 1] [False --> 0]\n");
    scanf("%d", &transportReq);
    printf("\nAre you looking for international schools? [True --> 1] [False --> 0]\n");
    scanf("%d", &international);
    
    if(transportReq == 1){
        cost+=20000;
        TP=20000;}
    if(international == 1){
        cost+=10000;
        IS=10000;}
    extraActivities();
    boardChoosing();
    category();
    display();
}

int extraActivities() {
    
    while(activityCount<3) {
    
        int activitychoice;
        printf("\n\nExtra activities: \n");
        printf("\n1. Dance  [1000 per annum]\n");
        printf("\n2. Singing  [1000 per annum]\n");
        printf("\n3. Sports [1000 per annum]\n");
        printf("\n4. Finish Selection.");
        printf("\nEnter your choice: \n");
        scanf("%d", &activitychoice);
        
        if(activitychoice == 4) {
            break;
        }
        else if(activitychoice == 1) {
            cost+=1000;
            activityCount+=1;
        }
        else if(activitychoice == 2) {
            cost+=1000;
            activityCount+=1;
        }
        else if(activitychoice == 3){
            cost+=1000;
            activityCount+=1;
        }
    }
}

int boardChoosing() {
    printf("\n\nChoose your preferred board: \n");
    printf("\n1. ICSE  [13,000 per annum]\n");
    printf("\n2. CBSE  [13,000 per annum]\n");
    printf("\n3. STATE [13,000 per annum]\n");
    printf("\nEnter your choice: \n");
    scanf("%d", &boardchoice);
    
    if(boardchoice == 1) {
        cost+=20000;
        BC=20000;
    }
    else if(boardchoice == 2) {
        cost+=15000;
        BC=15000;
    }
    else if(boardchoice == 3){
        cost+=10000;
        BC=10000;
    }
}

int category() {
    printf("\n\nFinancial category: \n");
    printf("\n1. Financially stable  [Normal fees]\n");
    printf("\n2. Financially needy  [Annual income statement must be provided at a later time]\n");
    printf("\nEnter your choice: \n");
    scanf("%d", &categorychoice);
    
    if(categorychoice == 1) {
        cost+=0;
    }
    else if(categorychoice == 2) {
        cost-=5000;
        CC=-5000;
    }
}


int display() {
    printf("\n\n\n\nExpected Total Expenses Report:- \n");
    printf("\nFacility Choosen:---Selection--------Cost\n");
    printf("\nTransportation:--------%d------------(%d)\n", transportReq, TP);
    printf("\nInternational School:--%d------------(%d)\n", international, IS);
    printf("\nActivities chosen:-----%d------------(%d)\n", activityCount, activityCount*1000);
    printf("\nBoard chosen:--------%s-----------(%d)\n", board[boardchoice-1], BC);
    printf("\nCategory chosen:-----%s----------(%d)\n", categor[categorychoice-1], CC);
    printf("------------------------------------------");
    printf("\nTotal Cost:------------------------(%d)\n", cost);
    printf("\nBEST WISHES FOR YOUR CHILD'S BRIGHT FUTURE\n");
}

int main() {
    printf("\nWelcome to Schoolera! \n");
    printf("\nEnter your name: \n");
    scanf("%s", parentName);
    printf("\nWhat is the age of your child? \n");
    scanf("%d", &childAge);
    
    if(childAge>5 || childAge<3)
    {
        printf("\nYour ward is not eligible for admission.");
        printf("\n\nThankyou For Using Scholera.\n\n");
        exit(0);
    }
    
    menu();
    getch();

    return 0;
}