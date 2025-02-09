#include <mpi.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    int world_rank, world_size, message;
    MPI_Status status;

    // Initialize MPI
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    // Each process sends its rank as a message
    message = world_rank;

    // Calculate the next process in the ring
    int next = (world_rank + 1) % world_size;
    int prev = (world_rank - 1 + world_size) % world_size;

    // Send message to the next process
    MPI_Send(&message, 1, MPI_INT, next, 0, MPI_COMM_WORLD);

    // Receive message from the previous process
    MPI_Recv(&message, 1, MPI_INT, prev, 0, MPI_COMM_WORLD, &status);

    printf("Process %d received message %d from process %d\n", world_rank, message, prev);

    // Finalize MPI
    MPI_Finalize();
    return 0;
}
