/* 1.4 執行續 */

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <process.h>
#include <tchar.h>

int number1 = 0;
int number2 = 0;

UINT __stdcall staffA(LPVOID);
UINT __stdcall staffB(LPVOID);


int _tmain(int argc, char* argv[]){

    UINT id;
    HANDLE hd[2];
    srand(GetTickCount());
    hd[0] = (HANDLE)_beginthreadex(NULL,0, staffA,NULL ,0 , &id);
    hd[1] = (HANDLE)_beginthreadex(NULL,0 ,staffB ,NULL ,0 , &id);
    WaitForMultipleObjects(2, hd ,TRUE, INFINITE);
    CloseHandle(hd[0]);
    CloseHandle(hd[1]);
    return 0;
}

UINT __stdcall staffA(LPVOID p){
        
    while(number1 < 10000){
        printf("Begin of A ==============\n");
        number1++;
        number2++;
        printf("A add num ===============\n");
        printf("num1(A) %d \n", number1);
        Sleep(rand() % 2);
        printf("num1(A) %d \n", number2);
        printf("End of A ==============\n");
        Sleep(rand() % 2);
    }
    return 0;

}

UINT __stdcall staffB(LPVOID p){

    while(number1 < 10000){
        printf("Begin of B ==============\n");
        number1++;
        number2++;
        printf("B add num ===============\n");
        printf("num1(B) %d \n", number1);
        Sleep(rand() % 2);
        printf("num1(B) %d \n", number2);
        printf("End of A ==============\n");
        Sleep(rand() % 2);
    }
    return 0;

}

