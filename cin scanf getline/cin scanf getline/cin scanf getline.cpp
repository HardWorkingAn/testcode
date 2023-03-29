#include <iostream>


using namespace std;
int main()
{
    
    int total = 0;
    char order[20];
    int count = 0;
    int cost;
    char e[20] = "에스프레소";
    char a[20] = "아메리카노";
    char c[20] = "카푸치노";


   /* cout << a << endl;
    cin.getline(order,sizeof(order));
    cout << sizeof(order) << endl;
    cout << order << endl;*/
    //char test[20];
    //cin >> test;
    //cout << test << endl;
    //cin >> order;
    //for (int a = 0; a < sizeof(order); a + 2)
    //{
    //    printf("%c", a);
    //}

    while (total < 20000)
    {
        cin >> order >> count;
        if (order == e)
        {
            total += 2000 * count;
            cost = 2000 * count;
            cout << cost << "원" << endl;
        }
        if(order == a)
        {
            total += 2300 * count;
            cost = 2300 * count;
            cout << cost << "원" << endl;
        }
        if (order == c)
        {
            total += 2500 * count;
            cost = 2500 * count;
            cout << cost << "원" << endl;
        }
        cout << order << endl;
    }
    return 0;
}