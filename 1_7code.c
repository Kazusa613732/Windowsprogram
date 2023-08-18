#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <process.h>

#include <time.h>

UINT __stdcall staff(PVOID lp){
    int count_num = *(LPINT) lp;
    printf("The num is %d , ³ø¤W¼Æ¦r %d.\n", GetCurrentThreadId(),count_num);
    return 0;
}

int main(){
    double START,END;
	START = clock();
    const int staff_num = 10000;
    HANDLE hd[staff_num];
    int count_num[staff_num];
    int num = 0;
    for(int i = 0; i < staff_num; i++){
        count_num[i] = i + 1;
        hd[i] = (HANDLE)_beginthreadex(NULL, 0 ,staff, &count_num[i], 0,NULL);
    }
       
    WaitForMultipleObjects(staff_num , hd , TRUE ,INFINITE);
    for(int i = 0; i < staff_num; i++){
        CloseHandle(hd[i]);
    }

    END = clock();
    printf("Time = %f\n==========================", (double)clock()/CLOCKS_PER_SEC);
    printf("Time2 = %f\n========================= \n", (END - START) / CLOCKS_PER_SEC);
    
    
}