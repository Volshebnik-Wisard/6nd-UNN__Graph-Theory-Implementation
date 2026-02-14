#include <iostream>
#include <vector>
#include <stack>
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

// Рекурсивная функция для обхода DFS
void dfsRec(vector<vector<int>>& adj, vector<bool>& visited, int s, vector<int>& res)
{
    visited[s] = true;
    res.push_back(s);
    // Рекурсивно посещает все соседние вершины которые еще не посещены
    for (int i : adj[s])
        if (visited[i] == false)
            dfsRec(adj, visited, i, res);
}

// Основная функция DFS, которая инициализирует посещенный массив и вызывает DFSRec
vector<int> DFS(vector<vector<int>>& adj)
{
    vector<bool> visited(adj.size(), false);
    vector<int> res;
    dfsRec(adj, visited, 0, res);
    return res;
}

vector<int> DFS_Stack(vector<vector<int>>& adj)
{
    int V = adj.size();
    vector<bool> visited(V, false);
    vector<int> res;
    stack<int> st;
    // Начинаем с вершины 0
    st.push(0);
    visited[0] = true;

    while (!st.empty()) {
        int current = st.top();
        st.pop();
        res.push_back(current);

        // Добавляем соседей в стек в обратном порядке
        // для сохранения порядка обхода как в рекурсивной версии
        for (auto it = adj[current].rbegin(); it != adj[current].rend(); ++it) {
            int neighbor = *it;
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                st.push(neighbor);
            }
        }
    }

    return res;
}

int main()
{
    int V = 5;
    //vector<vector<int>> adj = { {1,2}, {0,2}, {0,1,3,4}, {2}, {2} };
    vector<vector<int>> adj = { {2, 3, 1}, {0}, {0,4}, {0}, {2} };
    displayAdjList(adj);
    vector<int> res = DFS_Stack(adj); cout << "DFS_Stack: ";
    for (int i = 0; i < V; i++)
        cout << res[i] << " ";
}