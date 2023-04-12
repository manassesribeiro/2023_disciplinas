import sys
sys.path.append(".")

from priorityQueue.model.descentQueue import DescentQueue

def main():
    queue = DescentQueue()
    queue.insertInQueue(10)
    queue.insertInQueue(12)
    queue.insertInQueue(14)
    queue.insertInQueue(16)
    queue.insertInQueue(18)

    queue.showQueue()


    for i in range(3):
        try:
            _dado = queue.priorityMaxRemove()
        except Exception as e:
            print(e)
        else:
            print("Removido o maior dado da fila: %s " % _dado)

    queue.showQueue()



main()
