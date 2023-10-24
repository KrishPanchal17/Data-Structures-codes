#include <iostream>
#include <vector>
using namespace std;

class Graph {
private:
    int numVertices;
    vector<vector<int>> adjacencyMatrix;

public:
    Graph(int numVertices);
    void addEdge(int src, int dest);
    void insertNode(int newNode);
    void deleteNode(int nodeToDelete);
    void printGraph();
};

Graph::Graph(int numVertices) {
    this->numVertices = numVertices;
    adjacencyMatrix.resize(numVertices, vector<int>(numVertices, 0));
}

void Graph::addEdge(int src, int dest) {
    if (src >= 0 && src < numVertices && dest >= 0 && dest < numVertices) {
        adjacencyMatrix[src][dest] = 1;
        adjacencyMatrix[dest][src] = 1;
    }
}

void Graph::insertNode(int newNode) {
    if (newNode >= 0 && newNode < numVertices) {
        numVertices++;
        adjacencyMatrix.push_back(vector<int>(numVertices, 0));
        for (int i = 0; i < numVertices; i++) {
            adjacencyMatrix[i].push_back(0);
        }
    }
}

void Graph::deleteNode(int nodeToDelete) {
    if (nodeToDelete >= 0 && nodeToDelete < numVertices) {
        for (int i = 0; i < numVertices; i++) {
            adjacencyMatrix[i][nodeToDelete] = 0;
            adjacencyMatrix[nodeToDelete][i] = 0;
        }
        numVertices--;
        adjacencyMatrix.pop_back();
        for (int i = 0; i < numVertices; i++) {
            adjacencyMatrix[i].pop_back();
        }
    }
}

void Graph::printGraph() {
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            cout << adjacencyMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int numVertices;
    cout << "Enter the number of vertices: ";
    cin >> numVertices;
    Graph g(numVertices);
    int numEdges;
    cout << "Enter the number of edges: ";
    cin >> numEdges;
    for (int i = 0; i < numEdges; i++) {
        int src, dest;
        cout << "Enter edge " << i + 1 << " (source destination): ";
        cin >> src >> dest;
        g.addEdge(src, dest);
    }
    int choice;
    do {
        cout << "1. Insert Node\n";
        cout << "2. Delete Node\n";
        cout << "3. Print Graph\n";
        cout << "4. Quit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                int newNode;
                cout << "Enter the node to insert: ";
                cin >> newNode;
                g.insertNode(newNode);
                break;
            }
            case 2: {
                int nodeToDelete;
                cout << "Enter the node to delete: ";
                cin >> nodeToDelete;
                g.deleteNode(nodeToDelete);
                break;
            }
            case 3:
                g.printGraph();
                break;
        }
    } while (choice != 4);
    return 0;
}
