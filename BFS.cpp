#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void displayAdjList(const vector<vector<int>>& adj) {
    for (int i = 0; i < adj.size(); i++) {
        cout << i << ": ";
        for (int j : adj[i]) {
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;
}

vector<int> bfs(vector<vector<int>>& adj) {
    int V = adj.size();
    int s = 0; // Исходный узел
    vector<int> res; // Создаём массив для хранения результатов обхода
    queue<int> q; // Создаём очередь для BFS
    vector<bool> visited(V, false); // Помечаем все вершины как не посещенные
    visited[s] = true; // 1.Исходный узел как посещенный и ставим его в очередь
    q.push(s);

    while (!q.empty()) { // Выполняем итерации по очереди
        // 2.Извлекаем вершину из очереди и сохраняем ее
        int curr = q.front();
        q.pop();
        res.push_back(curr);

        // Получаем все смежные вершины, удаленные из очереди 
        // 2.5.Просматриваем вершины, если соседняя не была 
        // посещена, отмечаем ее посещенной и ставим в очередь
        for (int x : adj[curr]) {
            if (!visited[x]) {
                visited[x] = true;
                q.push(x);
            }
        }
    }
    return res;
}
int main() {
    //vector<vector<int>> adj = { {1,2}, {0,2,3}, {0,1,4}, {1,4}, {2,3} };
    vector<vector<int>> adj = { {1,2}, {0,2}, {0,1,3,4}, {2}, {2} };
    displayAdjList(adj);
    vector<int> ans = bfs(adj); cout << "BFS: ";
    for (auto i : ans) {
        cout << i << " ";
    }
    return 0;
}

