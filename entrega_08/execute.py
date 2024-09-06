import subprocess
import os

# Caminho para o arquivo C++ e para o compilador
arquivo_cpp = '/home/pcliquet/Documents/Supercomp/atividade_supercomp_C-/entrega_07/hill_climb.cpp'  # Atualize o caminho se necessário
executavel = 'hill_climb'
saida_arquivo = '/home/pcliquet/Documents/Supercomp/atividade_supercomp_C-/entrega_07/saida.txt'  # Atualize o caminho se necessário

# Número de vezes para executar o código
num_execucoes = 5

# Função para compilar o código C++
def compilar_codigo():
    comando = f'g++ -O2 -o {executavel} {arquivo_cpp}'
    print(f'Compilando com: {comando}')
    subprocess.run(comando, shell=True, check=True)
    print('Compilação concluída.')

# Função para executar o código C++ e redirecionar a saída para um arquivo
def executar_codigo():
    comando = f'./{executavel}'
    print(f'Executando: {comando}')
    with open(saida_arquivo, 'a') as f:
        resultado = subprocess.run(comando, shell=True, capture_output=True, text=True)
        f.write(f'Execução:\n{resultado.stdout}')
        if resultado.stderr:
            f.write(f'Erros:\n{resultado.stderr}')
        f.write('-----------------------------\n')

# Verifique se o arquivo C++ existe
if not os.path.isfile(arquivo_cpp):
    print(f'Erro: O arquivo {arquivo_cpp} não foi encontrado.')
else:
    # Compilar o código
    compilar_codigo()

    # Limpar o arquivo de saída antes de iniciar as execuções
    if os.path.isfile(saida_arquivo):
        os.remove(saida_arquivo)
    
    # Executar o código várias vezes e redirecionar a saída para o arquivo
    for i in range(num_execucoes):
        print(f'\nExecução {i + 1}:')
        executar_codigo()

    print('Todas as execuções foram concluídas. Saída gravada em', saida_arquivo)
