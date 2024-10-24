// Anel de Processos

'''Descrição: Crie um programa MPI onde cada processo envia uma mensagem para o
próximo processo, formando um anel. O último processo envia a mensagem de volta ao
primeiro.
Instruções:
1. Cada processo com rank `i` envia uma mensagem para o processo de rank `i+1`.
2. O último processo (com o maior rank) envia de volta ao processo com rank 0.
3. O número de processos deve ser maior que 2.
4. Exiba a mensagem recebida por cada processo no terminal.
Dicas:
• O processo com rank 0 envia e recebe por último para fechar o anel.'''



