import concurrent.futures

def calcular_soma(inicio, fim):
    print("processing: ", inicio, " - ", fim)
    return sum(range(inicio, fim + 1))

if __name__ == "__main__":
    numero_total = 1000000
    num_threads = 4

    tamanho_intervalo = numero_total // num_threads

    with concurrent.futures.ThreadPoolExecutor(max_workers=num_threads) as executor:
        intervalos = [(i * tamanho_intervalo + 1, (i + 1) * tamanho_intervalo) for i in range(num_threads)]
        intervalos[-1] = (intervalos[-1][0], numero_total)

        resultados = list(executor.map(lambda intervalo: calcular_soma(*intervalo), intervalos))

    soma_total = sum(resultados)
    print("Soma total:", soma_total)
