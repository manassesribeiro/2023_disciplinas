from list.model.doubleLinkedList import DoubleLinkedList

class Stack:
    def __init__(self):
        self.stack = DoubleLinkedList()

    def push(self, item):
        self.stack.insertNewNodo(self.stack.tail, item)

    def pop(self) -> None:
        if self.isEmpty() is False:
            return self.stack.removeNodo(self.stack.tail)
        else:
            raise Exception("Stack is empty!")

    def isEmpty(self) -> bool:
        return True if self.stack.size == 0 else False
    
    def size(self) -> int:
        return self.stack.size
    
    def showStack(self):
        self.stack.visitNodesFromTailToHead()

    def stackTop(self):
        return self.stack.tail
