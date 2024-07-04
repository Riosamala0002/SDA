#include <iostream>
#includie <vector>
#include <list>

using namespace std;

class Graph {
private:
    int numVertices; // jumlah vertex
    vector<list<int>> adjLists; // adjacency lists
    vector<bool> visited; // visited array

public:
    Graph(int vertices) {
        numVertices = vertices;
        adjLists.resize(vertices);
        visited.resize(vertices, false);
    }

    void addEdge(int src, int dest) {
        adjLists[src].push_back(dest);
        adjLists[dest].push_back(src); // untuk graph tidak berarah
    }

    void DFS(int vertex) {
        visited[vertex] = true;
        cout << "Visited " << vertex << endl;

        list<int>::iterator it;
        for (it = adjLists[vertex].begin(); it!= adjLists[vertex].end(); ++it) {
            if (!visited[*it]) {
                DFS(*it);
            }
        }
    }

    void printGraph() {
        for (int i = 0; i < numVertices; i++) {
            cout << "Adjacency list of vertex " << i << ": ";
            list<int>::iterator it;
            for (it = adjLists[i].begin(); it!= adjLists[i].end(); ++it) {
                cout << *it << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph graph(5);

    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 4);

    graph.printGraph();

    cout << "Depth First Traversal: " << endl;
    graph.DFS(0);

    return 0;
}
