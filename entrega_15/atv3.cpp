//Difusão Linear

'''Descrição: O processo com rank 0 inicia enviando uma mensagem para o processo 1. O
processo 1, ao receber a mensagem, envia-a para o processo 2, e assim sucessivamente,
até que todos os processos tenham recebido a mensagem.
Instruções:
1. O processo com rank 0 envia uma mensagem inicial para o processo com rank 1.
2. Cada processo recebe a mensagem do processo anterior e a envia para o próximo.
3. O último processo exibe a mensagem no terminal.
Dicas:
• Cada processo (exceto o último) deve executar um `MPI_Recv` seguido de um
`MPI_Send`.'''

