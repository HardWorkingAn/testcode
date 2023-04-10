//https://school.programmers.co.kr/learn/courses/30/lessons/176963

#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    int point;
    unordered_map<string, int> member;

    for (int k = 0; k < name.size(); ++k)
    {
        member[name[k]] = yearning[k];
    }
    for (int i = 0; i < photo.size(); ++i)
    {
        point = 0;
        for (int j = 0; j < photo[i].size(); ++j)
        {
            if (member.find(photo[i][j]) != member.end())
            {
                point += member[photo[i][j]];
            }
        }
                
        answer.push_back(point);
        
    }
    
    return answer;
}