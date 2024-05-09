#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> shortestPath(int numVertices, int numEdges, vector<vector<int>> &edges) {
        vector<vector<pair<int, int>>> adj(numVertices + 1);
        for (auto it : edges) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
        vector<int> dist(numVertices + 1, 1e9), parent(numVertices + 1);   //1e9 for the infinite 
        for (int i = 1; i <= numVertices; i++)
            parent[i] = i;
        
        dist[1] = 0;

        pq.push({0, 1});
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int node = it.second;
            int dis = it.first;
            
            for (auto it : adj[node]) {
                int adjNode = it.first;
                int edW = it.second;
                
                if (dis + edW < dist[adjNode]) {
                    dist[adjNode] = dis + edW;
                    pq.push({dis + edW, adjNode});
                    parent[adjNode] = node;
                }
            }
        }
        if (dist[numVertices] == 1e9)
            return {-1};
        vector<int> path;
        int node = numVertices; 
        while (parent[node] != node) {
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(1);
        reverse(path.begin(), path.end());
        return path;
    }
};

int main() {
    int numVertices, numEdges;
    cout << "Enter the number of vertices in the graph: ";
    cin >> numVertices;
    cout << "Enter the number of edges in the graph: ";
    cin >> numEdges;
    
    vector<vector<int>> edges;
    cout << "Enter details of edges (source, destination, weight):" << endl;
    for (int i = 0; i < numEdges; ++i) {
        int source, destination, weight;
        cin >> source >> destination >> weight;
        edges.push_back({source, destination, weight});
    }

    Solution obj;
    vector<int> path = obj.shortestPath(numVertices, numEdges, edges);

    cout << "Shortest Path from node 1 to node " << numVertices << ": ";
    for (int i = 0; i < path.size(); i++) {
        cout << path[i] << " ";
    }
    cout << endl;
    return 0;
}


//input as {{1, 2, 2}, {2, 5, 5}, {2, 3, 4}, {1, 4, 1}, {4, 3, 3}, {3, 5, 1}};
