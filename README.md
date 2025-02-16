# MPI-Basics-Setup

This folder demonstrates **MPI (Message Passing Interface)** communication in **C and Python**, including:

- **Point-to-Point Communication** (send & receive between two processes)
- **Ring Communication** (each process sends to the next in a circular pattern)
- **Parallel Computation of Pi** using numerical integration

## How to Run

### **C Implementation**

1. **Compile** the code:
   ```bash
   mpicc send_recv.c -o send_recv
   ```
2. **Run with multiple processes**
   ```bash
   mpiexec -n 4 ./send_recv
   ```

### **Python Implementation**

```bash
mpiexec -n 2 python send_recv.py
```

### **Parallel Computation of Pi** (C Implementation)

This program computes the value of π using numerical integration with MPI. Each process calculates a portion of the integral, and results are combined using `MPI_Bcast` to distribute the number of intervals and `MPI_Reduce` to sum up the computed values from all processes.

1. **Compile the code:**
   ```bash
   mpicc pi_computation.c -o pi_computation -lm
   ```
2. **Run with multiple processes:**
   ```bash
   mpiexec -n 4 ./pi_computation
   ```
