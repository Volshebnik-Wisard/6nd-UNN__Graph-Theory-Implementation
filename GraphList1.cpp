#include <iostream>
#include <vector>
using namespace std;
//Для невзвешенного
void addEdge(vector<vector<int>>& adj, int u, int v) 
{
    adj[u].push_back(v); //Для ориентированного графа
    adj[v].push_back(u); //Для неориентированного графа (оба p_b(v/u))
}

void displayAdjList(const vector<vector<int>>& adj) {
    for (int i = 0; i < adj.size(); i++) {
        cout << i << ": ";
        for (int j : adj[i]) {
            cout << j << " ";
        }
        cout << endl;
    }
}

int main() {

    setlocale(LC_ALL, "ru");
    int V = 3; // Создаём граф с 3 вершинами и 3 ребрами
    vector<vector<int>> adj(V);

    // Добавляем ребра.
    addEdge(adj, 1, 0);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 0);

    cout << "Представление списка смежности "
         << "для неориентированного графа: " << endl;
    displayAdjList(adj);

    return 0;
}