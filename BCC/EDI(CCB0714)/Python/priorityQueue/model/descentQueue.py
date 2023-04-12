from traditionalQueue.model.queue import Queue

class DescentQueue(Queue):
    def __init__(self) -> None:
        super().__init__()
    
    def priorityMaxRemove(self):
        _max = self.queue.head.data
        _next = self.queue.head

        while(_next is not None):
            if _next.data > _max:
                _max = _next.data
                _nodoMax = _next
                
            _next = _next.next
        
        return self.queue.removeNodo(_nodoMax)