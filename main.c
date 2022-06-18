#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>

void clrscr()
{
    system("@cls||clear");
}
COORD coord ={0,0};
void gotoxy (int x,int y)
{
    coord.X = x;coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
int draw_box();

void print_X(int);
void print_O(int);
void check(int *);
int *plr1_pos,*plr2_pos;

int loc_n[9][2]={{67,27},
                {79,27},
                {91,27},
                {67,21},
                {79,21},
                {91,21},
                {67,15},
                {79,15},
                {91,15}
                };

int main()
{
    plr1_pos = (int *)calloc(9,sizeof(plr1_pos));
    plr2_pos = (int *)calloc(9,sizeof(plr2_pos));
    int in,user_in,i;
    int err;
    void (*plr1)(int);
    void (*plr2)(int);
    while(1)
    {
        printf("________MENU________\n1: Play with X\n2: Play with O\n3: Exit\nEnter your choice:>");
        err = draw_box();
        if( err!=0)
        {
            exit(2);
        }
        l3:gotoxy(20,4);
        user_in=getch();
        if(user_in==49)       //3.Play with X
        {
            plr1= &print_X;
            plr2= &print_O;
            printf("X");
        }
        else if(user_in==50)  //2.Play with O
        {
            plr1 = &print_O;
            plr2 = &print_X;
            printf("O");
        }
        else if(user_in==51) //3.Exit
            break;
        else
            goto l3;
        for(i=0;i<9;i++)
        {
            l1:in = getch();
            if(in>48&&in<58)
            {
                (*plr1)(in-49);
                plr1_pos[in-49]= 1;
            }
            else
            {
                goto l1;
                //break;
            }
            i++;
            if(i>=9)
                break;
            l2:in = getch();
            if(in>48&&in<58)
            {
                (*plr2)(in-49);
                plr2_pos[in-49]= 1;
            }
            else
            {
                goto l2;
                //break;
            }
        }
        getch();
        clrscr();
        gotoxy(80,21);
        printf("GAME OVER");
        getch();
    }
    return 0;
}

int draw_box()
{
    int ax_x=62,ax_y=18,drw_k,drw_l,drw_p;
    for(drw_k=-2;drw_k<18;drw_k++)
    {
        if(drw_k<0)
        for(drw_l=0,ax_x=62,ax_y=18;drw_l<36;drw_l++)//for horizontal lines
        {
            gotoxy(ax_x+drw_l,ax_y+drw_p-9);
            printf("_");
        }
        else
        for(drw_l=0,ax_x=74,ax_y=13;drw_l<13;drw_l+=12)//for vertical lines
        {
            gotoxy(ax_x+drw_l,ax_y+drw_k);
            printf("|");
        }
        drw_p+=6;
    }
    return 0;
}

void print_X(int loc)
{
    gotoxy((int)loc_n[loc][0],(int)loc_n[loc][1]);
    printf("\\/");
    gotoxy((int)loc_n[loc][0],(int)(loc_n[loc][1]+1));
    printf("/\\");
}

void print_O(int loc)
{
    gotoxy((int)loc_n[loc][0],(int)loc_n[loc][1]);
    printf("/``\\");
    gotoxy((int)loc_n[loc][0],(int)(loc_n[loc][1]+1));
    printf("\\../");
}

void check(int *loc)
{

}
