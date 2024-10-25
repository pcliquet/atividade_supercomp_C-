// Anel de Processos
// Descrição: Crie um programa MPI onde cada processo envia uma mensagem para o
// próximo processo, formando um anel. O último processo envia a mensagem de volta ao
// primeiro.
// Instruções:
// 1. Cada processo com rank `i` envia uma mensagem para o processo de rank `i+1`.
// 2. O último processo (com o maior rank) envia de volta ao processo com rank 0.
// 3. O número de processos deve ser maior que 2.
// 4. Exiba a mensagem recebida por cada processo no terminal.

#include <iostream>
#include <cstring>
#include <mpi.h>

int main(int argc, char **argv) {
    char message[20];
    int rank, size, type = 25;
    MPI_Status status;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (size <= 2) {
        if (rank == 0) {
            std::cerr << "O número de processos deve ser maior que 2." << std::endl;
        }
        MPI_Finalize();
        return 1;
    }

    // Inicializa a mensagem apenas no processo 0
    if (rank == 0) {
        strcpy(message, "Olá do processo 0");
        MPI_Send(message, strlen(message) + 1, MPI_CHAR, (rank + 1) % size, type, MPI_COMM_WORLD);
        MPI_Recv(message, 20, MPI_CHAR, size - 1, type, MPI_COMM_WORLD, &status);
        std::cout << "Processo " << rank << " recebeu: " << message << std::endl;
    } else {
        MPI_Recv(message, 20, MPI_CHAR, rank - 1, type, MPI_COMM_WORLD, &status);
        std::cout << "Processo " << rank << " recebeu: " << message << std::endl;
        snprintf(message, sizeof(message), "Olá do processo %d", rank);
        MPI_Send(message, strlen(message) + 1, MPI_CHAR, (rank + 1) % size, type, MPI_COMM_WORLD);
    }

    MPI_Finalize();
    return 0;
}
