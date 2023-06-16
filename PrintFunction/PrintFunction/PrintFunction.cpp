#include <iostream>
#include <string>
#define print_func() printf("FILENAME: %s, FUNCNAME :%s, LINENO :%d\n",__FILE__, __FUNCTION__, __LINE__)
#define log(fmt, ...) printf("[%s: %d][%s] " fmt "\t\t\t (%s, %s)\n", __FILE__, __LINE__, __func__, __DATE__, __TIME__)
#define test_str(test_string, ...) printf("test left\t  " test_string "\ttest right\n")
void func_a() {
    print_func();
    log("\n\nfunc_aaaa testing");
    //printf("func_a : %s , %s , %d\n", __FILEW__, __FUNCTIONW__, __LINE__);
}

void func_b() {
    print_func();
    log("\n\nfunc_bbbb testing");
    //printf("func_b : %s , %s , %d\n", __FILEW__, __FUNCTIONW__, __LINE__);
}
int main()
{
    func_a();

    func_b();
    std::string a;
    test_str("testing");
    std::cout << "Hello World!\n";
}