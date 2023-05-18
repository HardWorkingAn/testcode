#include <iostream>
#include <thread>

using std::thread;

using namespace std;
int i = 0, j = 0, k = 0;
__int64 a = 0;
void func1() {
    for (i = 0; i < 2000; i++)
    {
        for ( j = 0; j < 2000; j++)
        {
            for ( k = 0; k < 2000; k++)
            {
                ++a;
            }
        }
    }
}

int main()
{
    /*
    char a;
    int b;
    
    do
    {
        scanf_s(" %c", &a);
        
        if ((a > 49) && (a < 59))
        {
            a = a - '0';
            //a = a - 48;
            
            for (b = 1; b < 10; b++)
            {
                printf("%d * %d = %d\n", a, b, a * b);
            }
        }
        //else if ((a == 'q') || (a == 'Q'))
        else if ((a == 'q') || (a == 'Q'))
            break;
        else
            printf("> 유효하지 않은 데이터 값\n> 다시 입력하세요.\n");
    } while (1);
    */
    /*
    long a = 0;
    for (int i = 0; i < 2000; i++)
    {
        for (int j = 0; j < 2000; j++)
        {
            for (int k = 0; k < 2000; k++)
            {
                ++a;
                cout << a << endl;
            }
        }
    }
    */

    thread t1(func1);
    //thread t2(func1);
    //thread t3(func1);
 

    t1.join();
    //t2.join();
    //t3.join();

    cout << a << endl;
}