#include <mpi.h>
#include <stdio.h>

// int MPI_Send(const void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm)

// int MPI_Recv(void *buf, int count, MPI_Datatype datatype, int source, int tag,
//              MPI_Comm comm, MPI_Status *status)

int main(int argc, char **argv)
{
    int world_rank;
    int world_size;
    int message;
    int received_message;
    MPI_Status status;

    MPI_Init(NULL, NULL);

    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    MPI_Comm_size(MPI_COMM_WORLD, &world_size)

        if (world_size < 2)
    {
        fprintf(stderr, "World size must be greater than 1 for this example\n");
        MPI_Abort(MPI_COMM_WORLD, 1);
    }

    if (world_rank == 0)
    {
        message = 123;
        MPI_Send(&message, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
        printf("Process 0 sending message to process 1\n");
    }
    else if (world_rank == 1)
    {
        // Receive the message from process 0
        MPI_Recv(&received_message, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
        printf("Process 1 received message: %d\n", received_message);
    }
    else
    {
        printf("Process %d is not involved in this communication.\n", world_rank);
    }

    MPI_Finalize();
}