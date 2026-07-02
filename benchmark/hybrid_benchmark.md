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


# Hybrid MPI + OpenMP Benchmark (Version 2)

| Dataset | 2x8 | 4x4 | 8x2 | 16x1 |
|----------|----:|----:|----:|-----:|
| access.log | 0.308706 | 0.160995 | 0.178087 | 0.099993 |
| nasa_500MB.log | 0.912952 | 0.394940 | 0.380076 | 0.279743 |
| nasa_1GB.log | 1.853346 | 0.721285 | 0.761825 | 0.510059 |
| nasa_2GB.log | 3.686663 | 1.355221 | 1.454424 | 1.012693 |
| nasa_4GB.log | 7.287409 | 2.578176 | 2.794507 | 1.984138 |
| nasa_8GB.log | 14.793881 | 5.325699 | 5.753891 | 3.860896 |
| nasa_10GB.log | 18.368635 | 6.722755 | 6.931400 | 5.083724 |

