#include <iostream>
#include <vector>
using namespace std;

void addEdge(vector<vector<int>>& mat, int i, int j)
{
    mat[i][j] = 1;
    mat[j][i] = 1; // для неориентированного графа
}

void displayMatrix(vector<vector<int>>& mat)
{
    int V = mat.size();
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
}

int main0()
{   
    setlocale(LC_ALL, "ru");
    int V = 4; // Создаём граф с 4 вершинами
    // Все значения инициализируем как 0
    vector<vector<int>> mat(V, vector<int>(V, 0)); 

    // Добавляем ребра.
    addEdge(mat, 0, 1); addEdge(mat, 0, 2);
    addEdge(mat, 1, 2); addEdge(mat, 2, 3);
    
    cout << "Представление матрицы смежности" << endl;
    displayMatrix(mat);

    return 0;
}