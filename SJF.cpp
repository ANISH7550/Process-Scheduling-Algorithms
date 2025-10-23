#include <iostream>
#include <vector>
using namespace std;

struct Process {
    int pid;
    int arrivalTime;
    int burstTime;
    int waitingTime;
    int turnaroundTime;
};

int main() {
    int n;
    cout << "=== SJF Scheduling Algorithm (Non-preemptive) ===\n";
    cout << "Enter number of processes: ";
    cin >> n;

    vector<Process> procs(n);
    for(int i = 0; i < n; i++) {
        procs[i].pid = i + 1;
        cout << "Enter Arrival Time for Process " << i + 1 << ": ";
        cin >> procs[i].arrivalTime;
        cout << "Enter Burst Time for Process " << i + 1 << ": ";
        cin >> procs[i].burstTime;
    }

    vector<bool> done(n, false);
    int completed = 0, currentTime = 0;
    double totalWT = 0, totalTAT = 0;

    cout << "\\nPID  AT  BT  WT  TAT\\n";

    while(completed < n) {
        int idx = -1;
        int minBurst = 1000000000;
        for(int i = 0; i < n; i++) {
            if(!done[i] && procs[i].arrivalTime <= currentTime && procs[i].burstTime < minBurst) {
                minBurst = procs[i].burstTime;
                idx = i;
            }
        }
        if(idx == -1) { currentTime++; continue; }

        procs[idx].waitingTime = currentTime - procs[idx].arrivalTime;
        currentTime += procs[idx].burstTime;
        procs[idx].turnaroundTime = procs[idx].waitingTime + procs[idx].burstTime;

        totalWT += procs[idx].waitingTime;
        totalTAT += procs[idx].turnaroundTime;

        done[idx] = true;
        completed++;

        cout << procs[idx].pid << "    "
             << procs[idx].arrivalTime << "    "
             << procs[idx].burstTime << "    "
             << procs[idx].waitingTime << "    "
             << procs[idx].turnaroundTime << "\\n";
    }

    cout.setf(ios::fixed); cout<<setprecision(2);
    cout << "\\nAverage Waiting Time: " << totalWT / n << "\\n";
    cout << "Average Turnaround Time: " << totalTAT / n << "\\n";

    return 0;
}
