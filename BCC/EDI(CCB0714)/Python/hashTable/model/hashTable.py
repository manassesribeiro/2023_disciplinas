from list.model.doubleLinkedList import DoubleLinkedList as List

class HashTable():
    def __init__(self, size) -> None:
        self.keys, self.size = self.__initializeKeys(size)
    
    def __initializeKeys(self, size):
        _keys = []
        for i in range(size):
            _keys[i] = List()
        
        return _keys, size

    def resizeKeys(self, newSize):
        _newKeys, _ = self.__initializeKeys(newSize)
        for i in range(self.size):
            while(self.keys[i].size() > 0):
                _data = self.keys[i].removeNodo(None)
                _newKeys[hash(_data, newSize)] = _data
        
        return _newKeys, newSize
    
    def hash(self, value, size):
        return (value % size)
    
    def insert(self, key, value):
        pass

    def remove(self):
        pass

    def keyDistribution(self):
        _keyDistribution

