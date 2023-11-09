import uuid
import random
class Order:
    def __init__(self, valor=None, imposto=.10):
        self.id = uuid.uuid4()
        if valor is None:
            self.valor = random.randfloat(0, 1000)
        else:
            self.valor = valor
        self.imposto = imposto

    def get_id(self):
        return self.id
    
    def get_valor(self):
        return self.valor
    
    def get_imposto(self):
        return self.imposto
    
    def get_json(self):
        return {
            "id": str(self.id),
            "valor": self.valor,
            "imposto": self.imposto
        }