#include <queue>
#include <vector>
#include <utility>

using namespace std;

void neighbors(int img[5][5], int row, int col, int start)
{
	int indices[4][2] = {
		{row - 1, col},
		{row + 1, col},
		{row, col - 1},
		{row, col + 1}
	};
}

void floodFill(int img[5][5], int row, int col, int p)
{
	int start = img[row][col];
	queue<pair<int, int>> queue;
	queue.push({row, col});
	vector<pair<int, int>> visited;
	while (!queue.empty()) {
		pair<int, int> current = queue.front();
		queue.pop();
		row = current.first;
		col = current.second;
		visited.push_back({row, col});
		img[row][col] = p;
		for (pair<int, int> i : neighbors())
	}
}

int main() 
{
	int img[5][5] = {
		{1, 0, 1, 1, 0},
		{0, 1, 0, 1, 0},
		{1, 1, 1, 1, 1},
		{0, 0, 1, 0, 1},
		{1, 0, 0, 0, 0},
	};
}
