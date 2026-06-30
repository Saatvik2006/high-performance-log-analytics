# Project Architecture

## Version 1

### Serial

```
Log File
    │
Parser
    │
Analytics
    │
Output
```

---

### OpenMP

```
Log File
      │
Thread Partitioning
      │
OpenMP Threads
      │
Local Analytics
      │
Merge
      │
Output
```

---

### MPI

```
Log File
      │
MPI Broadcast
      │
File Partitioning
      │
MPI Processes
      │
MPI Reduce
      │
Output
```

---

### Hybrid

```
Log File
      │
MPI Partition
      │
OpenMP Threads
      │
Local Analytics
      │
MPI Reduce
      │
Output
```
