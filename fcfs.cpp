#include <iostream>

using namespace std;

int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    int bt[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter the burst time for process " << (i + 1) << ": ";
        cin >> bt[i];
    }

    int wt[n];
    int tt[n];

    wt[0] = 0;
    tt[0] = bt[0];

    for (int i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
        tt[i] = wt[i] + bt[i];
    }

    cout << "\nProcesses || Burst Time || Waiting Time || Turn-Around Time" << endl;
    float awt = 0;
    float att = 0;

    for (int i = 0; i < n; i++) {
        awt += wt[i];
        att += tt[i];
        cout << i + 1 << "\t  ||\t" << bt[i] << "\t||\t" << wt[i] << "\t||\t " << tt[i] << endl;
    }

    awt /= n;
    att /= n;

    cout << "\nAverage waiting time = " << awt << endl;
    cout << "Average turn around time = " << att << endl;

    return 0;
}
