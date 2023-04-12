import sys
sys.path.append(".")
print(sys.path)

from traditionalQueue.model.queue import Queue

def main():
    queue = Queue()
    queue.insertInQueue(10)
    queue.insertInQueue(12)
    queue.insertInQueue(14)
    queue.insertInQueue(16)
    queue.insertInQueue(18)

    queue.showQueue()

    try:
        _data = queue.removeFromQueue()
    except Exception as e:
        print(e)
    else:
        print("Removed data from queue: %s " % _data)

    queue.showQueue()
    

main()
