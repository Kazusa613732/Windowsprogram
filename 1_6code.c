#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <process.h>

UINT __stdcall staff(PVOID lp){

    printf("The num is %d\n", GetCurrentThreadId());
    return 0;
}

int main(){
    const int staff_num = 5;
    HANDLE hd[staff_num];
    for(int i = 0; i < staff_num; i++){
        hd[i] = (HANDLE)_beginthreadex(NULL, 0 ,staff, NULL, 0,NULL);
    }
    
    WaitForMultipleObjects(staff_num , hd , TRUE ,INFINITE);
    for(int i = 0; i < staff_num; i++){
        CloseHandle(hd[i]);
    }
    
}