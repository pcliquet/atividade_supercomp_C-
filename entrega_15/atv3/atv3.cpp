// Difusão Linear
// Descrição: O processo com rank 0 inicia enviando uma mensagem para o processo 1. O
// processo 1, ao receber a mensagem, envia-a para o processo 2, e assim sucessivamente,
// até que todos os processos tenham recebido a mensagem.
// Instruções:
// 1. O processo com rank 0 envia uma mensagem inicial para o processo com rank 1.
// 2. Cada processo recebe a mensagem do processo anterior e a envia para o próximo.
// 3. O último processo exibe a mensagem no terminal.

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

    if (rank == 0) {
        strcpy(message, "Mensagem do Rank 0");
        MPI_Send(message, strlen(message) + 1, MPI_CHAR, rank + 1, type, MPI_COMM_WORLD);
    } else {
        MPI_Recv(message, 20, MPI_CHAR, rank - 1, type, MPI_COMM_WORLD, &status);

        if (rank < size - 1) {
            MPI_Send(message, strlen(message) + 1, MPI_CHAR, rank + 1, type, MPI_COMM_WORLD);
        } else {
            std::cout << "Último processo (Rank " << rank << ") recebeu: " << message << std::endl;
        }
    }

    MPI_Finalize();
    return 0;
}
