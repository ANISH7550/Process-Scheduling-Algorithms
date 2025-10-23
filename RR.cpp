#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Process {
    int pid;
    int arrivalTime;
    int burstTime;
    int remainingTime;
    int waitingTime;
    int turnaroundTime;
};

int main() {
    int n, quantum;
    cout << "=== Round Robin Scheduling Algorithm ===\n";
    cout << "Enter number of processes: ";
    cin >> n;

    vector<Process> procs(n);
    for(int i = 0; i < n; i++) {
        procs[i].pid = i + 1;
        cout << "Enter Arrival Time for Process " << i + 1 << ": ";
        cin >> procs[i].arrivalTime;
        cout << "Enter Burst Time for Process " << i + 1 << ": ";
        cin >> procs[i].burstTime;
        procs[i].remainingTime = procs[i].burstTime;
    }

    cout << "Enter Time Quantum: ";
    cin >> quantum;

    int currentTime = 0;
    bool doneAll = false;
    double totalWT = 0, totalTAT = 0;

    cout << "\\nPID  AT  BT  WT  TAT\\n";

    while(!doneAll) {
        doneAll = true;
        for(int i = 0; i < n; i++) {
            if(procs[i].remainingTime > 0) {
                doneAll = false;
                int t = min(quantum, procs[i].remainingTime);
                procs[i].remainingTime -= t;
                currentTime += t;
                if(procs[i].remainingTime == 0) {
                    procs[i].turnaroundTime = currentTime - procs[i].arrivalTime;
                    procs[i].waitingTime = procs[i].turnaroundTime - procs[i].burstTime;

                    totalWT += procs[i].waitingTime;
                    totalTAT += procs[i].turnaroundTime;

                    cout << procs[i].pid << "    "
                         << procs[i].arrivalTime << "    "
                         << procs[i].burstTime << "    "
                         << procs[i].waitingTime << "    "
                         << procs[i].turnaroundTime << "\\n";
                }
            }
        }
    }

    cout.setf(ios::fixed); cout<<setprecision(2);
    cout << "\\nAverage Waiting Time: " << totalWT / n << "\\n";
    cout << "Average Turnaround Time: " << totalTAT / n << "\\n";

    return 0;
}
