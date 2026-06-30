# Hybrid Parser Benchmark (MPI + OpenMP)

## System Configuration

### Master Node
- CPU: Intel Core i5-12450HX
- Physical Cores: 8
- Logical Threads: 12
- RAM: 16 GB
- OS: Ubuntu 24.04 LTS

### Worker Node
- CPU: Intel Core i5-3540
- Physical Cores: 4
- RAM: 16 GB
- OS: Ubuntu 24.04 LTS

---

## Compiler

- Compiler: mpicc
- Optimization: -O3
- OpenMP: Enabled (-fopenmp)

---

## Benchmark Dataset

| Dataset | Size |
|---------|------|
| access.log | 161 MB |

---

## Single Node Benchmarks

| MPI Processes | OpenMP Threads | Total Workers | Runtime (sec) |
|--------------:|---------------:|--------------:|--------------:|
| 1 | 8 | 8 | 0.574302 |
| 1 | 12 | 12 | 0.548610 |
| 2 | 6 | 12 | 0.281018 |
| 3 | 4 | 12 | **0.136980** |
| 4 | 3 | 12 | 0.149490 |
| 6 | 2 | 12 | 0.156846 |

---

## Cluster Benchmark

Host Configuration

```
master slots=12
worker slots=4
```

| MPI Processes | OpenMP Threads | Total Workers | Runtime (sec) |
|--------------:|---------------:|--------------:|--------------:|
| 16 | 3 | 48 | **0.110500** |

---

## Observations

- Hybrid execution successfully combines MPI process-level parallelism with OpenMP thread-level parallelism.
- Using only a single MPI process introduces MPI overhead without significant benefit.
- Increasing MPI processes while reducing OpenMP threads improves performance.
- The best single-node configuration was **3 MPI processes × 4 OpenMP threads**, achieving **0.136980 s**.
- Utilizing both the master and worker nodes reduced execution time further to **0.110500 s**.
- Open MPI reports "Authorization required, but no authorization protocol specified" when launching remote processes. This message is related to X11 forwarding and does not affect benchmark correctness.

---

## Conclusion

Version 1 demonstrates four working implementations:

- Serial Parser
- OpenMP Parser
- MPI Parser
- Hybrid MPI + OpenMP Parser

The Hybrid implementation provides the fastest execution when distributed across both nodes, serving as the baseline for future feature additions and optimization in Version 2.
