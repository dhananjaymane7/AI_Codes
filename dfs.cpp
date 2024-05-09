#include <iostream>
#include <vector>

using namespace std;

void depthFirstSearch(int currentNode, const vector<vector<int>>& adjacencyList, vector<bool>& visited) {
    // Mark the current node as visited
    visited[currentNode] = true;

    // Process the current node
    cout << currentNode << " ";

    // Traverse all adjacent nodes of the current node
    for (int nextNode : adjacencyList[currentNode]) {
        // If the adjacent node is not visited, recursively call depthFirstSearch
        if (!visited[nextNode]) {
            depthFirstSearch(nextNode, adjacencyList, visited);
        }
    }
}

void addEdge(vector<vector<int>>& adjacencyList, int node1, int node2) {
    adjacencyList[node1].push_back(node2);
    adjacencyList[node2].push_back(node1); // For undirected graph
}

int main() {
    int numVertices, numEdges;
    cout << "Enter the number of vertices and edges: ";
    cin >> numVertices >> numEdges;

    vector<vector<int>> adjacencyList(numVertices);

    // Input edges
    cout << "Enter the edges (source destination):" << endl;
    for (int i = 0; i < numEdges; ++i) {
        int source, destination;
        cin >> source >> destination;
        addEdge(adjacencyList, source, destination);
    }

    // Initialize visited array
    vector<bool> visited(numVertices, false);

    // Perform DFS traversal from each unvisited vertex
    cout << "DFS traversal:" << endl;
    for (int i = 0; i < numVertices; ++i) {
        if (!visited[i]) {
            depthFirstSearch(i, adjacencyList, visited);
        }
    }

    return 0;
}
