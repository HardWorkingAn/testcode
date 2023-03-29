#include <iostream>
#include <cstdlib> //난수 관련 라이브러리
#include <ctime> //시간 관련 라이브러리

#include<Windows.h>
#include<mmsystem.h>
#include<conio.h>
#pragma comment(lib, "winmm.lib")

using namespace std;

int main()
{
    
    int a;
    
    for (int i = 0; i < 10; ++i)
    {
        printf("%d\n", rand());
    }
    printf("\n");
    for (int i = 0; i < 10; ++i)
    {
        srand((unsigned int)time(0));
        printf("%d\n", rand());
    }
    
    PlaySound(TEXT("C:/Users/user/Desktop/심심풀이/random_test_01/test1.wav"), NULL, SND_ASYNC | SND_NODEFAULT);
    while (1)
    {
        scanf_s("%d", &a);
        if (a == 0)
        {
            break;
        }
        if (a == 1)
        {
            PlaySound(TEXT("C:/Users/user/Desktop/심심풀이/random_test_01/test1.wav"), NULL, SND_ASYNC | SND_NODEFAULT);
        }
        if (a == 2)
        {
            PlaySound(NULL, NULL, SND_ASYNC);
        }
    }

}