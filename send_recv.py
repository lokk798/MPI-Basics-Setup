from mpi4py import MPI

comm = MPI.COMM_WORLD
rank = comm.Get_rank()
size = comm.Get_size()

if size < 2:
    print("World size must be greater than 1 for this example")
    MPI.COMM_WORLD.Abort(1)
    


if rank == 0:
    message = "Hello Process 1!"
    # Send the message to process 1
    comm.send(message, dest=1, tag=0)
    print("Process 0 sending message to process 1")
elif rank == 1:
    # Receive the message from process 0
    received_message = comm.recv(source=0, tag=0)
    print(f"Process 1 received message: {received_message}")
else:
    print(f"Process {rank} is not involved in this communication.")
