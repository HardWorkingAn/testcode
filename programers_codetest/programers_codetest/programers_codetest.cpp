#include <iostream>
#include <string>
#include <vector>


#include "공원산책.cpp"
using namespace std;


int main()
{

    vector<string> a;
    a.push_back("SOO");
    a.push_back("OOO");
    a.push_back("OOO");  
    vector<string> b;
    b.push_back("E 2");
    b.push_back("S 2");
    b.push_back("W 1");
    

    solution(a, b);

    std::cout << "Hello World!\n";
}