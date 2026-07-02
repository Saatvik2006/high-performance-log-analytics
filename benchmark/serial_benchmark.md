# Serial Benchmark Results

## System Configuration

**Machine:** Master (saatvik-LOQ)

| Component | Specification |
|-----------|---------------|
| CPU | Intel Core i5-12450HX |
| Physical Cores | 8 |
| Logical Threads | 12 |
| RAM | 16 GB |
| Compiler | GCC 13.3.0 |
| OS | Ubuntu 24.04 |
| Optimization | -O3 |

---

## Dataset Information

| Dataset | Size |
|---------|------|
| access.log | 161 MB |
| nasa_500MB.log | 500 MB |
| nasa_1GB.log | 1 GB |
| nasa_2GB.log | 2 GB |
| nasa_4GB.log | 4 GB |
| nasa_8GB.log | 8 GB |
| nasa_10GB.log | 10 GB |

---

## Benchmark Results

| Dataset | Parsed Lines | Runtime (s) | Throughput (Million Lines/s) |
|---------|-------------:|------------:|-----------------------------:|
| access.log | 1,539,554 | 0.585253 | 2.63 |
| nasa_500MB.log | 4,809,316 | 1.867251 | 2.58 |
| nasa_1GB.log | 9,853,815 | 3.795663 | 2.60 |
| nasa_2GB.log | 19,702,148 | 7.607081 | 2.59 |
| nasa_4GB.log | 39,404,702 | 15.232362 | 2.59 |
| nasa_8GB.log | 78,804,865 | 30.380638 | 2.59 |
| nasa_10GB.log | 98,507,287 | 37.876085 | 2.60 |

---

## Observations

- Runtime scales approximately linearly with dataset size.
- Average throughput remains close to **2.6 million log entries per second**.
- This benchmark serves as the baseline for evaluating OpenMP, MPI, and Hybrid implementations.

---

## Compiler Command

```bash
gcc -O3 -Wall -Iinclude \
src/parser.c \
src/timer.c \
src/analytics.c \
serial/main.c \
-o serial_parser
```

---

## Execution Command

```bash
./serial_parser <dataset>
```

# Serial Benchmark (Version 2)

Hardware
--------
Master Node
- Intel Core i5-12450HX
- 8 Physical Cores
- Ubuntu Linux

Dataset Results

| Dataset | Runtime (sec) |
|----------|--------------:|
| access.log | 0.681325 |
| nasa_500MB.log | 2.077168 |
| nasa_1GB.log | 4.213752 |
| nasa_2GB.log | 8.449862 |
| nasa_4GB.log | 16.996737 |
| nasa_8GB.log | 33.734138 |
| nasa_10GB.log | 42.082686 |

