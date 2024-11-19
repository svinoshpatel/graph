#include <vector>
#include <stack>
#include <iostream>
#include <queue>

using namespace std;

void dfsI(vector<vector<int>>& graph, int vertex)
{
	int n = graph.size();
	vector<bool> visited(n, false);
	stack<int> stack;
	stack.push(vertex);
	while (!stack.empty()) {
		vertex = stack.top();
		stack.pop();
		if (!visited[vertex]) {
			cout << vertex << " ";
			visited[vertex] = true;
		};
		vector<int>& neighbors = graph[vertex];
		for (int i = 0; i < neighbors.size(); ++i) {
			if (!visited[neighbors[i]])
				stack.push(neighbors[i]);
		};
	};
};

void dfsR(vector<vector<int>>& graph, int vertex, vector<bool>& visited = *(new vector<bool>()))
{
	if (visited.empty())
		visited.resize(graph.size(), false);
	vector<int>& neighbors = graph[vertex];
	cout << vertex << " ";
	visited[vertex] = true;
	for (int i = 0; i < neighbors.size(); ++i) {
		if (!visited[neighbors[i]])
			dfsR(graph, neighbors[i], visited);
	};
};

void bfs(vector<vector<int>>& graph, int vertex)
{

	int n = graph.size();
	vector<bool> visited(n, false);
	queue<int> queue;
	queue.push(vertex);
	while (!queue.empty()) {
		vertex = queue.front();
		queue.pop();
		if (!visited[vertex]) {
			cout << vertex << " ";
			visited[vertex] = true;
		};
		vector<int>& neighbors = graph[vertex];
		for (int i = 0; i < neighbors.size(); ++i) {
			if (!visited[neighbors[i]])
				queue.push(neighbors[i]);
		};
	};
	cout << endl;
}

int main()
{
	vector<vector<int>> graph = {
		{1, 2},        // 0
		{0, 2, 3, 4},  // 1
		{0, 1},        // 2
		{1, 5},        // 3
		{1},           // 4
		{3, 6, 7, 8},  // 5
		{5},           // 6
		{5, 8},        // 7
		{5, 7, 9},     // 8
		{8},           // 9
	};

	// vector<vector<int>> graph = {
	// 	{1, 2},        // 0
	// 	{0, 3},     // 1
	// 	{0, 3},        // 2
	// 	{0, 1, 2, 4},        // 3
	// 	{3},           // 4
	// };

	cout << "DFS Iterative: ";
	dfsI(graph, 0);
	cout << endl;
	cout << "DFS Recursive: ";
	dfsR(graph, 0);
	cout << endl;
	cout << "BFS: ";
	bfs(graph, 0);
	cout << endl;
}
