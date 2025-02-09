from mpi4py import MPI

comm = MPI.COMM_WORLD
rank = comm.Get_rank()
size = comm.Get_size()

next = (rank + 1) % size
prev = (rank - 1 + size) % size

message = rank

comm.send(message, dest=next, tag=0)

received_message = comm.recv(source=prev, tag=0)

print(f"Process {rank} received message {received_message} from process {prev}")

