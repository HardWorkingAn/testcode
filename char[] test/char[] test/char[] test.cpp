#include <iostream>
#pragma warning(disable:4996)



using namespace std;

void copy_str(char* dest, const char* src) {
    while (*src) {
        *dest = *src;
        src++;
        dest++;
    }

    *dest = '\0';
}


void copy_int(int* dest, const int* src) {
    while (*src) {
        *dest = *src;
        src++;
        dest++;
    }

    *dest = '\0';
}

int main()
{
    char a[10] = "test1";
    cout << a << endl;

    copy_str(a, "가나다라");
    cout << a << endl;

    int a_int[20] = { 1,2,3,4,5,6,7,8,10 };
    int b_int[10] = { 11,12,13,14,15,16 };
    for (int i : a_int)
    {
        cout << i << ' ';
    }
    cout << endl;

    copy_int(a_int, b_int);
    
    for (int i :a_int)
    {
        cout << i << ' ';
    }
    cout << endl;


    // 버퍼 오버플로우 테스트
    /*
    char name[10];
    scanf_s("%s", name, 9);
    printf("%s\n", name);
    scanf_s("%s", name, 9);
    printf("%s\n", name);
    scanf_s("%s", name, 9);
    printf("%s\n", name);
    */

    char name[10];
    scanf("%9s%*[^\n]", name);
    getchar(); // 개행 문자 처리
    printf("%s\n", name);
    scanf("%9s%*[^\n]", name);
    getchar(); // 개행 문자 처리
    printf("%s\n", name);
}

/*

#include <iostream>
using namespace std;
#include <stdio.h>


struct Books {
    // 책 이름
    char name[10];
    // 저자 이름
    char auth[10];
    // 출판사 이름
    char publ[10];
}b1;

int main()
{

    printf("책 이름 : ");
    scanf_s("%s", b1.name, 10);

    printf("저자 이름 : ");
    scanf_s("%s", b1.auth, 10);

    printf("출판사 이름 : ");
    scanf_s("%s", b1.publ, 10);

    printf("책 이름 : %s\n저자 이름 : %s\n출판사 이름 : %s\n", b1.name, b1.auth, b1.publ);
    return 0;
}


*/