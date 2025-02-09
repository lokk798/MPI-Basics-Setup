#include <mpi.h>
#include <stdio.h>

// argc argument count ./program arg1 arg3 ===> argc = 3 ./program is also counted.
// To run more than the number of cors,
// mpirun --oversubscribe -np 15 lok_hello_mpi

int main(int argc, char **argv)
{
    int world_rank; // Stores the rank the ID of the current process.
    int world_size; /[/ Store the total number of processes in the communication.

    // Initialize MPI
    MPI_Init(NULL, NULL);

    // Get the rank of the process.
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank); // MPI_COMM_WORLD is the default communicator
                                                // that includes all processes in the MPI program.

    // Get the total number of processes.
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    printf("Hello from process %d of %d processes!\n", world_rank, world_size);

    // Finalize MPI
    MPI_Finalize();

    return 0;
}