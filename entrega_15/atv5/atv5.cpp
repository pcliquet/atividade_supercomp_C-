// Somas Paralelas
// Descrição: Crie um programa MPI em que cada processo recebe um valor numérico
// exclusivo, soma-o ao valor de um processo anterior, e o último processo exibe a soma
// total de todos os processos.

#include <iostream>
#include <mpi.h>

int main(int argc, char **argv) {
    int value, rank, size, type = 25;
    MPI_Status status;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    // Cada processo tem um valor único para somar
    value = rank + 1; // Cada processo soma seu `rank + 1` por simplicidade

    if (rank == 0) {
        // Processo 0 envia seu valor para o próximo processo
        MPI_Send(&value, 1, MPI_INT, rank + 1, type, MPI_COMM_WORLD);
    } else {
        // Processos > 0 recebem, somam e enviam ao próximo
        MPI_Recv(&value, 1, MPI_INT, rank - 1, type, MPI_COMM_WORLD, &status);
        
        // Adiciona seu próprio valor
        value += rank + 1;

        // Se não for o último processo, envia para o próximo
        if (rank < size - 1) {
            MPI_Send(&value, 1, MPI_INT, rank + 1, type, MPI_COMM_WORLD);
        } else {
            // Último processo exibe o resultado final
            std::cout << "Soma total: " << value << std::endl;
        }
    }

    MPI_Finalize();
    return 0;
}
