#produtor-consumidor para somar de 1 a 1000000 usando 4 processos
#usando o módulo multiprocessing
#usando o módulo Queue

import multiprocessing
import time
import queue

def produtor(queue):
    for i in range(1,1000001):
#        print (i)
        queue.put(i)
    queue.put(None)
    
def consumidor(process, queue, lock, soma):
    while True:
        item = queue.get()
        if item is None:
            break
        lock.acquire()
        print ("Processo: ", process, " - Item: ", item)
        soma.value += item
        lock.release()
    queue.put(None)

if __name__ == '__main__':
    q = multiprocessing.Queue()
    lock = multiprocessing.Lock()
    soma = multiprocessing.Value('i', 0)
    p1 = multiprocessing.Process(target=produtor, args=(q,))
    p2 = multiprocessing.Process(target=consumidor, args=("1", q,lock,soma))
    p3 = multiprocessing.Process(target=consumidor, args=("2",q,lock,soma))
    p4 = multiprocessing.Process(target=consumidor, args=("3",q,lock,soma))
    p1.start()
    p2.start()
    p3.start()
    p4.start()
    p1.join()
    p2.join()
    p3.join()
    p4.join()
    print(soma.value)
