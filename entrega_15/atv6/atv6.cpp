#include <iostream>
#include <mpi.h>

int main(int argc, char **argv) {
    int message;
    int rank, size, type = 25;
    MPI_Status status;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (rank == 0) {
        // Processo 0 envia a primeira mensagem e espera resposta dos demais processos
        for (int i = 1; i < size; i++) {
            // Envia mensagem para o processo i
            message = i;
            MPI_Send(&message, 1, MPI_INT, i, type, MPI_COMM_WORLD);
            std::cout << "Processo 0 enviou mensagem para o processo " << i << std::endl;

            // Recebe resposta do processo i
            MPI_Recv(&message, 1, MPI_INT, i, type, MPI_COMM_WORLD, &status);
            std::cout << "Processo 0 recebeu resposta do processo " << i << std::endl;
        }
    } else {
        // Todos os outros processos recebem a mensagem e respondem de volta
        MPI_Recv(&message, 1, MPI_INT, 0, type, MPI_COMM_WORLD, &status);
        std::cout << "Processo " << rank << " recebeu mensagem do processo 0" << std::endl;

        // Envia resposta de volta para o processo 0
        MPI_Send(&message, 1, MPI_INT, 0, type, MPI_COMM_WORLD);
        std::cout << "Processo " << rank << " enviou resposta para o processo 0" << std::endl;
    }

    MPI_Finalize();
    return 0;
}
