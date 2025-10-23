# Process-Scheduling-Algorithms
A collection of five classic CPU scheduling algorithms implemented in C++ — FCFS, SJF, SRTF, Priority, and Round Robin. Each algorithm runs on Linux/Unix terminals with clear input/output formatting and example test cases. Perfect for learning Operating System concepts like waiting time, turnaround time, and process handling
Folders:
- `FCFS/` — First Come First Serve
- `SJF/` — Shortest Job First (Non-preemptive)
- `SRTF/` — Shortest Remaining Time First (Preemptive)
- `PBR/` — Priority Based Scheduling (Non-preemptive)
- `RR/` — Round Robin Scheduling

How to compile and run (example for FCFS):
```
g++ FCFS.cpp -o FCFS
./FCFS
```
For RR, the program will ask for the time quantum at runtime.

Notes:
- Output columns are spaced for readability.
- Priority: lower number = higher priority.
