# MPI Benchmark Results

## System Configuration

### Master Node
- CPU: Intel Core i5-12450HX
- Logical Cores: 12
- OS: Ubuntu

### Worker Node
- CPU: Intel Core i5-3540
- Logical Cores: 4
- OS: Ubuntu

---

# 1 Process

| Dataset | Runtime (s) |
|---------|------------:|
| access.log (160 MB) | 0.650954 |
| 500 MB | 2.019396 |
| 1 GB | 4.118804 |
| 2 GB | 8.273037 |
| 4 GB | 16.393878 |
| 8 GB | 32.621494 |
| 10 GB | 40.971616 |

---

# 2 Processes

| Dataset | Runtime (s) |
|---------|------------:|
| access.log (160 MB) | 0.334724 |
| 500 MB | 1.054281 |
| 1 GB | 2.149448 |
| 2 GB | 4.190447 |
| 4 GB | 8.359551 |
| 8 GB | 16.358187 |
| 10 GB | 21.049130 |

---

# 4 Processes

| Dataset | Runtime (s) |
|---------|------------:|
| access.log (160 MB) | 0.244654 |
| 500 MB | 0.687836 |
| 1 GB | 1.150938 |
| 2 GB | 2.578224 |
| 4 GB | 4.737192 |
| 8 GB | 9.589068 |
| 10 GB | 11.889037 |

---

# 8 Processes

| Dataset | Runtime (s) |
|---------|------------:|
| access.log (160 MB) | 0.128799 |
| 500 MB | 0.401347 |
| 1 GB | 0.841289 |
| 2 GB | 1.585028 |
| 4 GB | 3.140552 |
| 8 GB | 6.571781 |
| 10 GB | 7.752880 |

---

# 13 Processes (12 Master + 1 Worker)

| Dataset | Runtime (s) |
|---------|------------:|
| access.log (160 MB) | 0.106468 |
| 500 MB | 0.336446 |
| 1 GB | 0.648439 |
| 2 GB | 1.382373 |
| 4 GB | 2.431590 |
| 8 GB | 4.813735 |
| 10 GB | 5.907940 |

---

# 14 Processes (12 Master + 2 Worker)

| Dataset | Runtime (s) |
|---------|------------:|
| access.log (160 MB) | 0.115591 |
| 500 MB | 0.279871 |
| 1 GB | 0.601893 |
| 2 GB | 1.266814 |
| 4 GB | 2.310342 |
| 8 GB | 4.519476 |
| 10 GB | 5.742030 |

---

# 15 Processes (12 Master + 3 Worker)

| Dataset | Runtime (s) |
|---------|------------:|
| access.log (160 MB) | 0.091227 |
| 500 MB | 0.273954 |
| 1 GB | 0.546892 |
| 2 GB | 1.136390 |
| 4 GB | 2.213229 |
| 8 GB | 4.152705 |
| 10 GB | 5.059298 |

---

# 16 Processes (12 Master + 4 Worker)

| Dataset | Runtime (s) |
|---------|------------:|
| access.log (160 MB) | 0.122581 |
| 500 MB | 0.298930 |
| 1 GB | 0.545564 |
| 2 GB | 1.033463 |
| 4 GB | 1.977700 |
| 8 GB | 4.038383 |
| 10 GB | 5.065544 |

---

# Benchmark Summary

## Correctness

All MPI configurations produced identical results:

- Parsed Lines
- GET Requests
- POST Requests
- Other Requests
- HTTP Status Counts
- Total Bytes

No duplicate or missing records were observed.

---

## Observations

- Runtime scales consistently with increasing process count.
- Near-linear speedup is observed up to 8 local MPI processes.
- Distributed execution across the two-node cluster further reduces runtime.
- The best performance for larger datasets was achieved with **15–16 MPI processes**, utilizing both the master and worker nodes.
- The heterogeneous cluster (Intel Core i5-12450HX + Intel Core i5-3540) demonstrates the benefit of distributed execution despite differing processor capabilities.
