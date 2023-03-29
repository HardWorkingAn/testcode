#include <iostream>
#include <fstream>
#include <string>
#include <list>
using namespace std;

int main() {
    string line;
    char line_c[100];
    int it_start = 0;
    int it_end = 0;
    // 읽을 원본파일
    ifstream file1("Al_metalcase.txt"); // txt 파일을 연다. 없으면 생성. 
    // 값 바꿀 파일 생성
    ofstream file2("75.txt");
    //ofstream file3("50.txt");
    //ofstream file4("75.txt");
    //list<ofstream> files;

    if (file1.is_open()) {
        // file1의 한줄의 문자열을 line에 저장
        while (getline(file1, line)) {
            int it = line.find('Z');
            it_start = -1;
            it_end = -1;
            //line_s = "";
            
            // 문자열 line을 문자배열 line_c 에 복사
            strcpy_s(line_c, line.c_str());
            
            if (line_c[it + 1] == '-') // Z 다음 문자가 '-' 일경우
            {
                it_start = it + 2;
                it_end = it_start;
                // Z- 다음 숫자를 다 읽을 때 까지 반복
                //원본 파일에는 Z - 숫자 다음이 다 F나 개행문자로 시작하기 때문에 F나 NULL 이 아닐경우로 함 getline 함수는 개행문자를 가져오지 않음.
                while (line_c[it_end] != NULL && line_c[it_end] != 'F')
                {
                    it_end++;
                }
            }

            if (it_start > -1)
            {
                //cout << it_start << " " << it_end << endl;;
                string s_float = line.substr(it_start, it_end - it_start);
                float f_float = atof(s_float.c_str()) * 0.75;

                string newStr = to_string(f_float);
                while (newStr.back() == '0')
                {
                    newStr.pop_back();
                }
                line.replace(it_start, it_end - it_start, newStr);
                cout << line << endl;
            }
            else
            {
                cout << line << endl;
            }
            // 다른파일에 저장하기준 line에는 개행문자가 없으므로 추가
            line += '\n';
            // file2 안에 저장된 텍스트파일 안에 문자 작성
            file2.write(line.c_str(), line.size());
        }
        file1.close(); // 열었떤 파일을 닫는다. 
    }
    else {
        cout << "Unable to open file";
        return 1;
    }

    // string -> float 하면 float 0.25 그대로, 하지만
    // float -> string 하면 0.25000000 소숫점 8개 다 출력됨
    /*
    float f_a = atof(".25");
    f_a = f_a * 2;
    cout << "float : " << f_a << endl;
    string s_a = to_string(f_a);
    cout << "string : " << s_a << endl;
    */
    return 0;
    

}