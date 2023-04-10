// 에러 signal: illegal instruction (core dumped)

/*
#include <string>
#include <vector>

using namespace std;
struct Point {
	int x = 0;
	int y = 0;
};
vector<int> solution(vector<string> park, vector<string> routes) {
	vector<int> answer;
	char way;
	int distance;
	string cutline = " ";
	vector<vector<char>> load;
	Point robot;
	Point copy_robot;
	int X_size = park.size();
	int Y_size = park[0].size();
	load.resize(X_size);
	for (int i = 0; i < X_size; ++i)
	{
		for (char c : park[i])
		{
			load[i].push_back(c);
		}
	}

	for (int i = 0; i < X_size; ++i)
	{
		for (int j = 0; j < Y_size; ++j)
		{
			if (load[i][j] == 'S')
			{
				robot.x = i;
				robot.y = j;
			}
		}
	}
	for (auto move : routes)
	{
		way = move[0];
		distance = stoi(move.substr(move.find(cutline) + 1, move.length() - 1));
		copy_robot = robot;
		switch (way)
		{
		case 'E':
			
			for(int i = robot.y; i < Y_size; ++i)
			{
				copy_robot.y += 1;
				if (copy_robot.y >= Y_size || load[robot.x][copy_robot.y] == 'X') {
					// 장애물이 있거나 공원을 벗어난 경우, 원래 위치로 돌아감
					copy_robot = robot;
					break;
				}
			}
			robot = copy_robot;
			break;
		case 'W':
			
			for (int i = robot.y; 0 < i; --i)
			{
				copy_robot.y -= 1;
				if (copy_robot.y < 0 || load[robot.x][copy_robot.y] == 'X') {
					// 장애물이 있거나 공원을 벗어난 경우, 원래 위치로 돌아감
					copy_robot = robot;
					break;
				}
			}
			robot = copy_robot;
			break;
		case 'S':
			
			for (int i = robot.x; 0 < i; --i)
			{
				copy_robot.x += 1;
				if (copy_robot.x < 0 || load[robot.x][copy_robot.y] == 'X') {
					// 장애물이 있거나 공원을 벗어난 경우, 원래 위치로 돌아감
					copy_robot = robot;
					break;
				}
			}
			robot = copy_robot;
			break;
		case 'N':
			
			for (int i = robot.x; i < X_size; ++i)
			{
				copy_robot.x -= 1;
				if (copy_robot.x >= X_size || load[robot.x][copy_robot.y] == 'X') {
					// 장애물이 있거나 공원을 벗어난 경우, 원래 위치로 돌아감
					copy_robot = robot;
					break;
				}
			}
			robot = copy_robot;
			break;
		}
	}
	answer.push_back(robot.x);
	answer.push_back(robot.y);


	return answer;
}
*/

#include <string>
#include <vector>

using namespace std;
struct Point {
	int x = 0;
	int y = 0;
};

vector<int> solution(vector<string> park, vector<string> routes) {
	vector<int> answer;
	Point robot;
	int X_size = park.size();
	int Y_size = park[0].size();
	vector<vector<char>> load(X_size, vector<char>(Y_size));

	for (int i = 0; i < X_size; ++i) {
		for (int j = 0; j < Y_size; ++j) {
			load[i][j] = park[i][j];
			if (load[i][j] == 'S') {
				robot.x = i;
				robot.y = j;
			}
		}
	}

	for (auto move : routes) {
		char way = move[0];
		int distance = stoi(move.substr(2));
		Point copy_robot = robot;

		for (int i = 0; i < distance; ++i) {
			switch (way) {
			case 'E':
				if (copy_robot.y + 1 < Y_size && load[copy_robot.x][copy_robot.y + 1] != 'X') {
					copy_robot.y += 1;
				}
				else {
					copy_robot = robot;
					i = distance;
				}
				break;
			case 'W':
				if (copy_robot.y - 1 >= 0 && load[copy_robot.x][copy_robot.y - 1] != 'X') {
					copy_robot.y -= 1;
				}
				else {
					copy_robot = robot;
					i = distance;
				}
				break;
			case 'N':
				if (copy_robot.x - 1 >= 0 && load[copy_robot.x - 1][copy_robot.y] != 'X') {
					copy_robot.x -= 1;
				}
				else {
					copy_robot = robot;
					i = distance;
				}
				break;
			case 'S':
				if (copy_robot.x + 1 < X_size && load[copy_robot.x + 1][copy_robot.y] != 'X') {
					copy_robot.x += 1;
				}
				else {
					copy_robot = robot;
					i = distance;
				}
				break;
			}
		}
		robot = copy_robot;
	}

	answer.push_back(robot.x);
	answer.push_back(robot.y);

	return answer;
}
/*
#include <string>
#include <vector>

using namespace std;
struct Point {
	int x = 0;
	int y = 0;
};
vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
	char way;
	int distance;
	string cutline = " ";
	vector<vector<char>> load;
	Point robot;
	Point copy_robot;
	int x = 0;
	int y = 0;
	int X_size = park.size();
	int Y_size = park[0].size();
	for (string a : park)
	{
		y = 0;
		for (char c : a)
		{

			load[x].push_back(c);
			++y;
		}
		++x;
	}


	for (int i = 0; i < X_size; ++i)
	{
		for (int j = 0; j < Y_size; ++j)
		{
			if (load[i][j] == 'S')
			{
				robot.x = i;
				robot.y = j;
			}
		}
	}
	for (auto move : routes)
	{
		way = move[0];
		distance = stoi(move.substr(move.find(cutline) + 1, move.length() - 1));
		copy_robot = robot;
		switch (way)
		{
		case 'E':
			for (int i = robot.y; i < X_size; ++i)
			{
				++i;
				if (load[robot.x][i] == 'X' || i < X_size)
				{
					copy_robot = robot;
					break;
				}
				else
				{
					copy_robot.y += 1;
				}
			}
			robot = copy_robot;
			break;
		case 'W':
			for (int i = robot.y; i < X_size; ++i)
			{
				++i;
				if (load[robot.x][i] == 'X' || i < X_size)
				{
					copy_robot = robot;
					break;
				}
				else
				{
					copy_robot.y -= 1;
				}
			}
			robot = copy_robot;
			break;
		case 'N':
			for (int i = robot.x; i < X_size; ++i)
			{
				++i;
				if (load[i][robot.y] == 'X' || i < X_size)
				{
					copy_robot = robot;
					break;
				}
				else
				{
					copy_robot.x -= 1;
				}
			}
			robot = copy_robot;
			break;
		case 'S':
			for (int i = robot.x; i < X_size; ++i)
			{
				++i;
				if (load[i][robot.y] == 'X' || i < X_size)
				{
					copy_robot = robot;
					break;
				}
				else
				{
					copy_robot.x += 1;
				}
			}
			robot = copy_robot;
			break;
		default:
			break;
		}
	}

	answer.push_back(robot.x);
	answer.push_back(robot.y);


	return answer;
}

*/