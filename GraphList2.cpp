#include <iostream>
#include <vector>
using namespace std;
//Для взвешенного
void addEdge(vector<vector<pair<int, int>>>& adj, int u, int v, int w) {
    adj[u].push_back({ v,w }); //Для ориентированного графа
    adj[v].push_back({ u,w }); //Для неориентированного графа (оба p_b(v/u))
}

void displayAdjList(vector<vector<pair<int, int>>>& adj) {
    for (int i = 0; i < adj.size(); i++) {
        cout << i << ": ";
        for (auto& j : adj[i]) {
            cout << "{" << j.first << ", " << j.second << "} ";
        }
        cout << endl;
    }
}

int main() {    
    setlocale(LC_ALL, "ru");
    int V = 3;
    vector<vector<pair<int, int>>> adj(V);

    addEdge(adj, 1, 0, 4);
    addEdge(adj, 1, 2, 3);
    addEdge(adj, 2, 0, 1);

    cout << "Представление списка смежности "
         << "для ориентированного графа : " << endl;
    displayAdjList(adj);

    return 0;
}