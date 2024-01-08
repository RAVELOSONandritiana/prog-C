#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <unistd.h>
void text(int color);
int main(){
    char mot[]="Andry de couleur ";
    int i = 0;
    for(int i = 0;i<30;i++)
    {
        text(34);
        printf("AAAA");
        usleep(50000);
    }
    while(i<200){
        text(i);
            printf("%s %d\n",mot,i);
            i++;
    }
    return 0;
}
void text(int color){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole,color);
}
