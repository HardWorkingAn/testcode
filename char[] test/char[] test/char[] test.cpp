#include <iostream>

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
}