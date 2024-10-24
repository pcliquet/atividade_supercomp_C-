// Comunicação Multipla

'''Descrição: Implemente um programa MPI onde o processo com rank 0 envia diferentes
mensagens para cada um dos outros processos. Cada processo (exceto o 0) recebe sua
mensagem e imprime o conteúdo.
Instruções:
1. O processo com rank 0 envia mensagens exclusivas para cada processo, incluindo
o número do processo na mensagem (ex: "Mensagem para o processo X").
2. Cada processo, ao receber sua mensagem, imprime no terminal o que recebeu.
3. Use um laço no processo 0 para enviar as mensagens para todos os outros.
Dicas:
• Lembre-se de utilizar tags nas mensagens para diferenciá-las, se necessário.'''

