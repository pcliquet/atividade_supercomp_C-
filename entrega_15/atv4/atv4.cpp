// Comunicação Multipla
// Descrição: Implemente um programa MPI onde o processo com rank 0 envia diferentes
// mensagens para cada um dos outros processos. Cada processo (exceto o 0) recebe sua
// mensagem e imprime o conteúdo.

#include <iostream>
#include <mpi.h>
#include <cstdio>

int main(int argc, char **argv) {
    char message[30];
    int rank, size, type = 25;
    MPI_Status status;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (rank == 0) {
        // Processo 0 envia mensagens únicas para cada processo
        for (int i = 1; i < size; i++) {
            sprintf(message, "Mensagem para o processo %d", i);
            MPI_Send(message, strlen(message) + 1, MPI_CHAR, i, type, MPI_COMM_WORLD);
        }
    } else {
        // Outros processos recebem e exibem suas mensagens
        MPI_Recv(message, 30, MPI_CHAR, 0, type, MPI_COMM_WORLD, &status);
        std::cout << "Processo " << rank << " recebeu: " << message << std::endl;
    }

    MPI_Finalize();
    return 0;
}
