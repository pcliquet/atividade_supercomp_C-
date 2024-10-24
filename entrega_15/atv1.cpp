// Comunicação entre 2 processos

'''Descrição: Escreva um programa MPI em que o processo de rank 0 envia uma mensagem
"Olá" para o processo de rank 1, e o processo 1 responde com "Oi" ao processo 0.
Instruções:
1. O processo com rank 0 envia uma mensagem "Olá" para o processo com rank 1.
2. O processo com rank 1 responde com "Oi" para o processo com rank 0.
3. Exiba as mensagens trocadas no terminal.'''

#include <iostream>
#include <cstring>
#include <mpi.h>



int main(int argc, chat **argv){
    char message[20];
    int i, rank, size, rank, type = 25;
    MPI_Status status;


    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if(rank == 0){
        strcpy(message, "Olá");
        MPI_Send(message, 4, MPI_CHAR, 1, type, MPI_COMM_WORLD);
        MPI_Recv(message, 4, MPI_CHAR, 1, type, MPI_COMM_WORLD, status);
    }
    else{
        MPI_Recv(message, 4, MPI_CHAR, 0, type, MPI_COMM_WORLD, status);
        strcpy(message, "oi");
        MPI_Send(message, 4, MPI_CHAR, 0, type, MPI_COMM_WORLD);
    }
    MPI_Finalize();
    return 0;
}


