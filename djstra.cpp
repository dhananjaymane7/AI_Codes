#include <iostream>
#include <limits>
using namespace std;

class office
{
    int n;
    int graph[25][25];
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
            for (int j = i; j < n; j++)
            {
                if (i == j)
                {
                    graph[i][j] = 0;
                    continue;
                }
                cout << "Enter the cost between " << office[i] << " and " << office[j] << " :";
                cin >> graph[i][j];
                graph[j][i] = graph[i][j];
            }
        }
        dijkstra(0);
    }

    void display()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << graph[i][j] << " ";
            }
            cout << endl;
        }
    }

    void dijkstra(int src)
    {
        int dist[n];
        bool visited[n];

        for (int i = 0; i < n; i++)
        {
            dist[i] = numeric_limits<int>::max();
            visited[i] = false;
        }

        dist[src] = 0;

        for (int count = 0; count < n - 1; count++)
        {
            int u = minDistance(dist, visited);

            visited[u] = true;

            for (int v = 0; v < n; v++)
            {
                if (!visited[v] && graph[u][v] && dist[u] != numeric_limits<int>::max() && dist[u] + graph[u][v] < dist[v])
                {
                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }

        printSolution(dist);
    }

    int minDistance(int dist[], bool visited[])
    {
        int min = numeric_limits<int>::max();
        int min_index = -1;

        for (int i = 0; i < n; i++)
        {
            if (!visited[i] && dist[i] <= min)
            {
                min = dist[i];
                min_index = i;
            }
        }

        return min_index;
    }

    void printSolution(int dist[])
    {
        cout << "Vertex \t Distance from Source" << endl;
        for (int i = 0; i < n; i++)
        {
            cout << i << " \t\t" << dist[i] << endl;
        }
    }
};

int main()
{
    office f;
    f.input();
    f.display();
    return 0;
}
