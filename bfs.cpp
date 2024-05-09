#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void breadthFirstSearch(const vector<vector<int>>& adjacencyList, vector<bool>& visited, queue<int>& bfsQueue) {
    // Base case: if the queue is empty, stop the recursion
    if (bfsQueue.empty()) return;

    // Get the front element of the queue and remove it
    int currentNode = bfsQueue.front();
    bfsQueue.pop();

    // Process the current node
    cout << currentNode << " ";

    // Enqueue unvisited neighbors of the current node
    for (int nextNode : adjacencyList[currentNode]) {
        if (!visited[nextNode]) {
            visited[nextNode] = true;
            bfsQueue.push(nextNode);
        }
    }

    // Recursively call breadthFirstSearch with the updated queue
    breadthFirstSearch(adjacencyList, visited, bfsQueue);
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

    cout << "Enter the edges (source destination):" << endl;
    for (int i = 0; i < numEdges; ++i) {
        int source, destination;
        cin >> source >> destination;
        addEdge(adjacencyList, source, destination);
    }

    // Initialize visited array and queue for BFS
    vector<bool> visited(numVertices, false);
    queue<int> bfsQueue;

    // Perform BFS traversal from each unvisited vertex
    cout << "BFS traversal:" << endl;
    for (int i = 0; i < numVertices; ++i) {
        if (!visited[i]) {
            visited[i] = true;
            bfsQueue.push(i);
            breadthFirstSearch(adjacencyList, visited, bfsQueue);
        }
    }

    return 0;
}
