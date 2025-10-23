#include <iostream>
#include <vector>
#include <iomanip>
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
    cout << "=== FCFS Scheduling Algorithm ===\n";
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

    int currentTime = 0;
    double totalWT = 0, totalTAT = 0;

    cout << "\\nPID  AT  BT  WT  TAT\\n";

    for(int i = 0; i < n; i++) {
        if(currentTime < procs[i].arrivalTime) currentTime = procs[i].arrivalTime;
        procs[i].waitingTime = currentTime - procs[i].arrivalTime;
        currentTime += procs[i].burstTime;
        procs[i].turnaroundTime = procs[i].waitingTime + procs[i].burstTime;

        totalWT += procs[i].waitingTime;
        totalTAT += procs[i].turnaroundTime;

        cout << procs[i].pid << "    "
             << procs[i].arrivalTime << "    "
             << procs[i].burstTime << "    "
             << procs[i].waitingTime << "    "
             << procs[i].turnaroundTime << "\\n";
    }

    cout.setf(ios::fixed); cout<<setprecision(2);
    cout << "\\nAverage Waiting Time: " << totalWT / n << "\\n";
    cout << "Average Turnaround Time: " << totalTAT / n << "\\n";

    return 0;
}
