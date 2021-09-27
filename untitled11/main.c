#include <stdio.h>
#include <windows.h>
#include <conio.h>
#define nc 150
#define hc 200
void gotoxy(int x,int y)
 {
    COORD coord={0,0};
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
 }
void textattr(int i)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
}
int main() {
    char menuitems[5][12]={{"Add"},{"Edit"},{"Display"},{"Display All"},{"Exit"}};
    int Currentitem=0,quit=0,c=0,col=40,row=7,size=5;
    printf("Mainmenu");
    textattr(nc);
    do{
        for(int i=0;i<size;i++){
            gotoxy(col,row+i);
            if(i==Currentitem) {
                textattr(hc);
                printf("%s",menuitems[i]);
            }
            else{
                textattr(nc);
                printf("%s",menuitems[i]);
            }
            textattr(nc);
        }
        c=getch();
        switch(c){
            default:
                c=getch(); //Extended Keys
                switch(c){
                    case 72: //up
                    if(Currentitem!=0) Currentitem--;
                        break;
                    case 80: //down
                        if(Currentitem<size-1) Currentitem++;
                        break;
                }
                break;
            case 13: //Enter case
                system("cls");
                printf("%s",menuitems[Currentitem]);
                break;
            case 27: //Escape case
                quit=1;
                break;
        }
    } while(quit!=1);
    return 0;
}
