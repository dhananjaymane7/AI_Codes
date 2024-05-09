#include <iostream>
using namespace std;

class office
{
    int n;
    int a[10][10];
    string office[10];

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
                    a[i][j] = 0;
                    continue;
                }
                cout << "Enter the cost  between " << office[i] << " and " << office[j] << " :";
                cin >> a[i][j];
                a[j][i] = a[i][j];
            }
        }
        prims();
    }

    // display function
    void display()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }

    // prims
    void prims()
    {
        int visit[n]={0}, mincost, minindex, cost = 0, count = 1;
        visit[0] = 1;
        cout << office[0];
        while (true)
        {
            mincost = 99999999;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (visit[i] == 1 && visit[j] == 0 && a[i][j] != 0 && a[i][j] < mincost )
                    {
                        minindex = j;
                        mincost = a[i][j];
                    }
                }
            }
            cost += mincost;
            count++;
            visit[minindex] = 1;
            cout << " -> " << office[minindex];
            if (count == n)
                break;
        }
        cout << endl
            << "Total cost : " << cost << endl;
    }
};

int main()
{
    office f;
    f.input();
    f.display();
}