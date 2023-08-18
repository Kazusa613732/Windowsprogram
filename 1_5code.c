#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <process.h>
#include <time.h>

UINT __stdcall staff(PVOID lp){

    printf("The num is %d\n", GetCurrentThreadId());
    return 0;
}

int main(){
    HANDLE h0 = (HANDLE)_beginthreadex(NULL, 0 ,staff, NULL, 0,NULL);
    WaitForSingleObject(h0, INFINITE);
    CloseHandle(h0);
}