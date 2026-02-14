// C++ Program to represent a graph using an incidence
// matrix

#include <iostream>
#include <vector>

using namespace std;

class Graph {
private:
    int v;
    int e;
    vector<vector<int> > incidenceMatrix;

public:
    // Constructor to initialize the graph with V vertices
    // and E edges
    Graph(int V, int E)
    {
        v = V;
        e = E;
        // Resize the incidence matrix with V rows and E
        // columns, initializing to 0
        incidenceMatrix.resize(V, vector<int>(E, 0));
    }

    // Function to add an edge in the incidence matrix
    void addEdge(int vertex1, int vertex2, int edgeIndex)
    {
        if (vertex1 >= 0 && vertex1 < v && vertex2 >= 0
            && vertex2 < v && edgeIndex >= 0
            && edgeIndex < e) {
            incidenceMatrix[vertex1][edgeIndex] = 1;
            incidenceMatrix[vertex2][edgeIndex] = 1;
        }
    }

    // Method to print the incidence matrix
    void printMatrix(const vector<char>& vertexLabels,
        const vector<string>& edgeLabels)
    {
        // Print edge labels
        cout << "  ";
        for (const auto& label : edgeLabels) {
            cout << label << " ";
        }
        cout << endl;

        // Print the matrix with vertex labels
        for (int i = 0; i < v; ++i) {
            cout << vertexLabels[i] << " ";
            for (int j = 0; j < e; ++j) {
                cout << incidenceMatrix[i][j] << "  ";
            }
            cout << endl;
        }
    }
};

// Driver Code
int main()
{
    // Create a graph with 5 vertices and 7 edges
    Graph g(5, 7);

    // Add the edges
    g.addEdge(0, 1, 0);
    g.addEdge(0, 2, 1);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 3);
    g.addEdge(2, 4, 4);
    g.addEdge(3, 4, 5);
    g.addEdge(1, 4, 6);

    // Define labels for vertices and edges
    vector<char> vertexLabels = { 'A', 'B', 'C', 'D', 'E' };
    vector<string> edgeLabels
        = { "e1", "e2", "e3", "e4", "e5", "e6", "e7" };

    // Print the incidence matrix for the graph
    cout << "Incidence Matrix of the Graph:" << endl;
    g.printMatrix(vertexLabels, edgeLabels);

    return 0;
}