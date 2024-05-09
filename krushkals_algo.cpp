#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int src, dest, weight;
};

bool compareEdges(Edge a, Edge b) {
    return a.weight < b.weight;
}
class Graph {
    int V, E;
public:
    vector<Edge> edges;
    Graph(int v, int e) {
        V = v;
        E = e;
        edges.resize(E);
    }

    int getV() const { return V; }
    int getE() const { return E; }

    static int find(int parent[], int vertex) {
        if (parent[vertex] != vertex) {
            parent[vertex] = find(parent, parent[vertex]);
        }
        return parent[vertex];
    }
    static void Union(int parent[], int x, int y) {
        int xSet = find(parent, x);
        int ySet = find(parent, y);
        parent[ySet] = xSet;
    }
};
int kruskalMST(Graph& graph) {
    int V = graph.getV();
    int E = graph.getE();

    sort(graph.edges.begin(), graph.edges.end(), compareEdges);

    int parent[V];
    for (int i = 0; i < V; i++) {
        parent[i] = i;
    }
    int minimumCost = 0;
    int edgeCount = 0;
    int i = 0;
    while (edgeCount < V - 1 && i < E) {
        Edge nextEdge = graph.edges[i++];

        int x = Graph::find(parent, nextEdge.src);
        int y = Graph::find(parent, nextEdge.dest);

        if (x != y) {
            minimumCost += nextEdge.weight;
            Graph::Union(parent, x, y);
            edgeCount++;
        }
    }
    return minimumCost;
}
int main() {
    int V, E;
    cout << "Enter the number of vertices in the graph: ";
    cin >> V;
    cout << "Enter the number of edges in the graph: ";
    cin >> E;
    Graph graph(V, E);
    for (int i = 0; i < E; i++) {
        cout << "Enter details of edge " << (i + 1) << ":" << endl;
        cout << "Source: ";
        cin >> graph.edges[i].src;
        cout << "Destination: ";
        cin >> graph.edges[i].dest;
        cout << "Weight: ";
        cin >> graph.edges[i].weight;
    }
    int minimumCost = kruskalMST(graph);
    cout << "Minimum Cost Spanning Tree: " << minimumCost << endl;
    return 0;
}

// Enter the number of vertices in the graph:5

// Enter the number of edges in the graph:6
// Enter the details of edge 1:
// Source: 1
// Destination: 2
// Weight: 7
// Enter the details of edge 2:
// Source: 1
// Destination: 4
// Weight: 9
// Enter the details of edge 3:
// Source: 2
// Destination: 3
// Weight: 3
// Enter the details of edge 4:
// Source: 3
// Destination: 4
// Weight: 7
// Enter the details of edge 5:
// Source: 2
// Destination: 5
// Weight: 12
// Enter the details of edge 6:
// Source: 4
// Destination: 5
// Weight: 5
