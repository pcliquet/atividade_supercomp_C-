#!/bin/bash
#As instruções SBATCH não devem ser descomentadas

#SBATCH --job-name=atv1_amaral
# define o nome do job. Esse nome aparece nas listas de jobs e é útil para identificar o job.

#SBATCH --output=atv1.out
# Especifica o arquivo onde a saída padrão (stdout) do job será salva.

#SBATCH --ntasks=2
# Define o número de tarefas que o job executará. Neste caso, o job executa uma única tarefa.

#SBATCH --time=00:10:00
# Define o tempo máximo de execução para o job. Neste caso, o job tem um tempo limite de 10 minutos. Se o job exceder esse tempo, ele será automaticamente encerrado.

#SBATCH --mem=512MB   

#SBATCH --partition=espec
# Especifica a partição (ou fila) onde o job será submetido. Aqui, o job será submetido a fila "normal".

mpirun ./atv1
#Executa o programa python3 dentro do nó de computação.