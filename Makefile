.PHONY: all serial openmp mpi hybrid clean

CC=gcc
MPICC=mpicc

CFLAGS=-O3 -Wall -Iinclude
OMPFLAGS=-fopenmp

SERIAL_SRC=src/parser.c src/timer.c src/analytics.c serial/main.c
OPENMP_SRC=src/parser.c src/timer.c src/analytics.c openmp/main.c
MPI_SRC=src/parser.c src/timer.c src/analytics.c mpi/main.c
HYBRID_SRC=src/parser.c src/timer.c src/analytics.c hybrid/main.c

all: serial openmp mpi hybrid

serial:
	$(CC) $(CFLAGS) $(SERIAL_SRC) -o serial_parser

openmp:
	$(CC) $(CFLAGS) $(OMPFLAGS) $(OPENMP_SRC) -o openmp_parser

mpi:
	$(MPICC) $(CFLAGS) $(MPI_SRC) -o mpi_parser

hybrid:
	$(MPICC) $(CFLAGS) $(OMPFLAGS) $(HYBRID_SRC) -o hybrid_parser

clean:
	rm -f serial_parser openmp_parser mpi_parser hybrid_parser
