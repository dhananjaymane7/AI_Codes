#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// Function to perform graph coloring and return the minimum number of colors required
int graphColoring(vector<string>& colorNames) {
    int numVertices, numEdges;
    cout << "Enter the number of vertices and edges in the graph: ";
    cin >> numVertices >> numEdges;

    vector<vector<int>> adjacencyList(numVertices);

    cout << "Enter edges in the format 'src dest' (0 based indexing)" << endl;
    for (int i = 0; i < numEdges; i++) {
        int src, dest;
        cin >> src >> dest;
        adjacencyList[src].push_back(dest);
        adjacencyList[dest].push_back(src);
    }

    vector<int> colors(numVertices, -1);

    int maxDegree = 0;
    for (int i = 0; i < numVertices; i++)
        maxDegree = max(maxDegree, static_cast<int>(adjacencyList[i].size()));

    for (int i = 0; i < numVertices; i++) {
        vector<bool> available(maxDegree + 1, true);
        for (int j : adjacencyList[i]) {
            if (colors[j] != -1)
                available[colors[j]] = false;
        }

        for (int j = 0; j <= maxDegree; j++) {
            if (available[j]) {
                colors[i] = j;
                break;
            }
        }
    }

    // Assign color names to each node
    for (int i = 0; i < numVertices; i++) {
        if (colors[i] == 0)
            colorNames.push_back("Red");
        else if (colors[i] == 1)
            colorNames.push_back("Blue");
        else if (colors[i] == 2)
            colorNames.push_back("Green");
        // Add more color names as needed
        // You can also define an array of color names and access them using indices
    }

    return *max_element(colors.begin(), colors.end()) + 1;
}

int main() {
    vector<string> colorNames;
    int minNumColors = graphColoring(colorNames);
    cout << "Minimum no. of colors required to color graph: " << minNumColors << endl;

    cout << "Colors for each node:" << endl;
    for (int i = 0; i < colorNames.size(); i++) {
        cout << "Node " << i << " is colored with " << colorNames[i] << endl;
    }

    return 0;
}
