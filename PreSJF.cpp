#include <bits/stdc++.h>

using namespace std;

struct process {
    int pid;           // process ID
    int at;            // arrival time
    int bt;            // burst time
    int rt;            // remaining time
};

bool compare(process a, process b) 
{
    return a.at < b.at;
}

int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    process p[n];
    for(int i = 0; i < n; i++) {
        cout << "Enter Arrival Time and Burst Time for Process " << i+1 << ": ";
        cin >> p[i].at >> p[i].bt;
        p[i].pid = i+1;
        p[i].rt = p[i].bt;
    }

    sort(p, p+n, compare);    // sort the processes according to their arrival time

    int currentTime = 0, completed = 0;
    float avg_tat = 0, avg_wt = 0;

    cout << "\nGantt Chart\n-----------\n";
    cout << "0";
    while(completed < n) 
    {
        int min_rt = 1000 , selected = -1;    // selected process with minimum remaining time
        for(int i = 0; i < n; i++) 
        {
            if(p[i].at <= currentTime && p[i].rt < min_rt && p[i].rt > 0) 
            {
                min_rt = p[i].rt;
                selected = i;
            }
        }

        if(selected == -1) 
        {    // if no process is selected, increment the current time
            currentTime++;
            continue;
        }

        p[selected].rt--;    // execute the process for 1 unit of time
        currentTime++;

        cout << " | P" << p[selected].pid << " | " << currentTime;

        if(p[selected].rt == 0) {    // if the process has completed execution
            completed++;
            int tat = currentTime - p[selected].at;     // turnaround time
            int wt = tat - p[selected].bt;              // waiting time
            avg_tat += tat;
            avg_wt += wt;
        }
    }

    avg_tat /= n;
    avg_wt /= n;

    cout << "\n\nAverage Turnaround Time = " << avg_tat << endl;
    cout << "Average Waiting Time = " << avg_wt << endl;

    return 0;
}
