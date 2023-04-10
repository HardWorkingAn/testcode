#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    string *temp;
    int index;
    for (auto calling : callings)
    {
        /*
        auto target = find(begin(players), end(players), calling);
        swap(*target, *(target - 1));
        */
        /*
        temp = players[target];
        players[target] = players[target - 1];
        players[target - 1] = temp;
        */
        
    }
    unordered_map<string, int> player_indices;
    for (int i = 0; i < players.size(); ++i) {
        player_indices[players[i]] = i;
    }

    for (const string& calling : callings) {
        int target_index = player_indices[calling];
        if (target_index > 0) {
            swap(players[target_index], players[target_index - 1]);
            player_indices[players[target_index]] = target_index;
            player_indices[calling] = target_index - 1;
        }
    }
    return players;
}