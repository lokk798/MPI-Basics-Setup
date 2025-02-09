# MPI-Basics-Setup

This folder demonstrates **MPI (Message Passing Interface)** communication in **C and Python**, including:

- **Point-to-Point Communication** (send & receive between two processes)
- **Ring Communication** (each process sends to the next in a circular pattern)

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

### Python Implementation

    mpiexec -n 2 python send_recv.py
