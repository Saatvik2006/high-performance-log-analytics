# OpenMP Benchmark Results

## System Configuration

- CPU: Intel Core i5-12450HX
- Logical Cores: 12
- OS: Ubuntu
- Programming Model: OpenMP

---

# 1 Thread

| Dataset | Runtime (s) |
|---------|------------:|
| access.log (160 MB) | 0.631592 |
| 500 MB | 1.981847 |
| 1 GB | 4.062862 |
| 2 GB | 8.154469 |
| 4 GB | 16.353655 |
| 8 GB | 32.526183 |
| 10 GB | 40.438457 |

---

# 2 Threads

| Dataset | Runtime (s) |
|---------|------------:|
| access.log (160 MB) | 0.339394 |
| 500 MB | 1.079622 |
| 1 GB | 2.148109 |
| 2 GB | 4.289907 |
| 4 GB | 8.611270 |
| 8 GB | 17.149426 |
| 10 GB | 21.552115 |

---

# 4 Threads

| Dataset | Runtime (s) |
|---------|------------:|
| access.log (160 MB) | 0.176514 |
| 500 MB | 0.552248 |
| 1 GB | 1.075154 |
| 2 GB | 2.225736 |
| 4 GB | 4.443581 |
| 8 GB | 8.879600 |
| 10 GB | 10.929324 |

---

# 8 Threads

| Dataset | Runtime (s) |
|---------|------------:|
| access.log (160 MB) | 0.156039 |
| 500 MB | 0.394777 |
| 1 GB | 0.734692 |
| 2 GB | 1.444767 |
| 4 GB | 2.886169 |
| 8 GB | 5.697879 |
| 10 GB | 7.292338 |

---

# 12 Threads

| Dataset | Runtime (s) |
|---------|------------:|
| access.log (160 MB) | 0.149666 |
| 500 MB | 0.327879 |
| 1 GB | 0.649172 |
| 2 GB | 1.265059 |
| 4 GB | 2.578427 |
| 8 GB | 4.995542 |
| 10 GB | 6.209505 |

---

# Benchmark Summary

## Correctness

All OpenMP configurations produced identical results after fixing the chunk boundary synchronization.

Verified metrics:

- Parsed Lines
- GET Requests
- POST Requests
- Other Requests
- HTTP Status Counts (2xx, 3xx, 4xx, 5xx)
- Total Bytes

No duplicate or missing records were observed in the final implementation.

---

## Observations

- Runtime decreases consistently as the number of OpenMP threads increases.
- Near-linear scaling is observed up to 8 threads.
- Performance continues to improve at 12 threads, although gains begin to diminish due to synchronization overhead and memory bandwidth limitations.
- The best performance was achieved using **12 OpenMP threads**, reducing the runtime of the 10 GB dataset from **40.44 s** to **6.21 s**, corresponding to an approximate **6.5× speedup** over the single-threaded implementation.
- OpenMP provides efficient shared-memory parallelism with minimal communication overhead compared to distributed-memory MPI.

# OpenMP Benchmark (Version 2)

| Dataset | 1 Thread | 2 Threads | 4 Threads | 8 Threads |
|----------|---------:|----------:|----------:|----------:|
| access.log | 0.738886 | 0.431533 | 0.252609 | 0.184683 |
| nasa_500MB.log | 2.180893 | 1.235666 | 0.630699 | 0.397300 |
| nasa_1GB.log | 4.472436 | 2.496866 | 1.262572 | 0.838453 |
| nasa_2GB.log | 8.966837 | 4.821825 | 2.425707 | 1.624004 |
| nasa_4GB.log | 17.512463 | 9.394446 | 5.022061 | 3.182029 |
| nasa_8GB.log | 35.497754 | 19.340592 | 9.640064 | 6.437089 |
| nasa_10GB.log | 44.768196 | 23.635363 | 12.050007 | 7.990562 |
