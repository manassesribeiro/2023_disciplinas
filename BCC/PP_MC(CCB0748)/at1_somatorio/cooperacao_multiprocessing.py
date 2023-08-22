import multiprocessing

def calcular_soma(inicio, fim, resultado):
    soma_parcial = sum(range(inicio, fim + 1))
    resultado.put(soma_parcial)

if __name__ == "__main__":
    numero_total = 1000000
    num_processos = 4

    tamanho_intervalo = numero_total // num_processos
    resultados = multiprocessing.Queue()

    processos = []
    for i in range(num_processos):
        inicio = i * tamanho_intervalo + 1
        fim = inicio + tamanho_intervalo - 1
        print("Criando processo", i, inicio, fim)
        if i == num_processos - 1:
            fim = numero_total
        processo = multiprocessing.Process(target=calcular_soma, args=(inicio, fim, resultados))
        processos.append(processo)
        processo.start()

    for processo in processos:
        processo.join()

    soma_total = 0
    while not resultados.empty():
        soma_parcial = resultados.get()
        soma_total += soma_parcial

    print("Soma total:", soma_total)