from list.model.doubleLinkedList import DoubleLinkedList

class Queue:
    def __init__(self):
        self.queue = DoubleLinkedList()

    def insertInQueue(self, item):
        self.queue.insertNewNodo(self.queue.tail, item)

    def removeFromQueue(self) -> None:
        return self.queue.removeNodo(self.queue.head)

    def isEmpty(self) -> bool:
        return True if self.queue.size == 0 else False
    
    def size(self) -> int:
        return self.queue.size
    
    def showQueue(self):
        self.queue.visitNodesFromHeadToTail()
