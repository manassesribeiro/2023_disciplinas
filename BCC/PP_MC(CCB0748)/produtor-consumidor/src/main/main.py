from src.produtor.order import Order
import threading

class OrderFactory(threading.Thread):
    def __init__(self):
        pass
    
    def create_order(self, valor=None, imposto=.10):
        return Order(valor, imposto)
    
    def run(self):
        pass