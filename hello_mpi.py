from mpi4py import MPI

# Initialize MPI communicator
comm = MPI.COMM_WORLD

# Get the rank of the process
rank = comm.Get_rank()

# Get the total number of processes
size = comm.Get_size()

# Print a "Hello, MPI World!" message
print(f"Hello from process {rank} of {size} processes!")
