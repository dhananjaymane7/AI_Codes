#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class office
{
    int n;
    vector<pair<int, pair<int, int>>> edges;
    string office[25];

public:
    void input()
    {
        cout << "Enter number of offices" << endl;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cout << "Enter name of office " << i + 1 << " :";
            cin >> office[i];
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int cost;
                cout << "Enter the cost between " << office[i] << " and " << office[j] << " :";
                cin >> cost;
                edges.push_back({cost, {i, j}});
            }
        }
        kruskal();
    }

    void display()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << office[i][j] << " ";
            }
            cout << endl;
        }
    }

    int findParent(int parent[], int i)
    {
        if (parent[i] == -1)
            return i;
        return findParent(parent, parent[i]);
    }

    void unionSet(int parent[], int x, int y)
    {
        int xset = findParent(parent, x);
        int yset = findParent(parent, y);
        parent[xset] = yset;
    }

    void kruskal()
    {
        int parent[n];
        for (int i = 0; i < n; i++)
            parent[i] = -1;

        vector<pair<int, pair<int, int>>> result;

        sort(edges.begin(), edges.end());

        int totalCost = 0;

        for (auto edge : edges)
        {
            int cost = edge.first;
            int u = edge.second.first;
            int v = edge.second.second;

            int setU = findParent(parent, u);
            int setV = findParent(parent, v);

            if (setU != setV)
            {
                result.push_back({cost, {u, v}});
                totalCost += cost;
                unionSet(parent, setU, setV);
            }
        }

        cout << "Minimum Spanning Tree Edges:" << endl;
        for (auto edge : result)
        {
            int u = edge.second.first;
            int v = edge.second.second;
            cout << office[u] << " - " << office[v] << " : " << edge.first << endl;
        }
        cout << "Total Cost: " << totalCost << endl;
    }
};

int main()
{
    office f;
    f.input();
    f.display();
    return 0;
}
