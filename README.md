# HPC Log Analytics Research

A high-performance log analytics framework developed to explore different parallel programming paradigms for large-scale log processing.

This project progressively implements the same log parser using:

- Serial Computing
- OpenMP
- MPI
- Hybrid MPI + OpenMP

The objective is to study scalability, speedup and parallel efficiency while processing multi-gigabyte HTTP server logs.

---

# Features

Current Version (v1.0)

- Parse HTTP access logs
- Count parsed lines
- GET / POST / Other request statistics
- HTTP Response Code statistics
- Total bytes transferred
- Benchmarking across multiple dataset sizes

---

# Project Structure

```
HPC_LogAnalytics_Research
│
├── benchmark/
├── datasets/
├── docs/
├── hybrid/
├── include/
├── mpi/
├── openmp/
├── serial/
├── scripts/
├── src/
│
├── Makefile
└── README.md
```

---

# Implementations

## Serial

Single-threaded parser.

```
Input
   ↓
Parser
   ↓
Analytics
```

---

## OpenMP

Shared-memory parallel parser.

```
Input
   ↓
Thread Chunking
   ↓
OpenMP Threads
   ↓
Local Analytics
   ↓
Merge
```

---

## MPI

Distributed-memory parser.

```
Input
   ↓
MPI Broadcast
   ↓
File Partition
   ↓
MPI Processes
   ↓
MPI Reduce
```

---

## Hybrid

Combination of MPI and OpenMP.

```
Input
   ↓
MPI
   ↓
OpenMP
   ↓
Analytics
   ↓
MPI Reduce
```

---

# Build

Compile everything

```bash
make
```

Compile individual implementations

```bash
make serial
make openmp
make mpi
make hybrid
```

Clean

```bash
make clean
```

---

# Running

Serial

```bash
./serial_parser <log_file>
```

OpenMP

```bash
OMP_NUM_THREADS=8 ./openmp_parser <log_file>
```

MPI

```bash
mpirun -np 8 ./mpi_parser <log_file>
```

Hybrid

```bash
OMP_NUM_THREADS=4 mpirun -np 4 ./hybrid_parser <log_file>
```

---

# Benchmarks

Benchmark reports are available in

```
benchmark/
```

including

- Serial
- OpenMP
- MPI
- Hybrid

---
