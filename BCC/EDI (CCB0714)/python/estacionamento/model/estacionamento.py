from fila.model.fila import Fila

class Estacionamento():
    def __init__(self, tamanhoPrincipal=10):
        self.principal = Fila(); # Estacionamento principal
        self.espera = Fila() # Estacionamento de espera
        self.tamanhoPrincipal = tamanhoPrincipal

    def colocaCarro(self, placa):
        if (self.principal.size() < self.tamanhoPrincipal):
            self.principal.insereNaFila(placa)
        else:
            self.espera.insereNaFila(placa)

    def retiraCarro(self):
        if (self.principal.size() >= self.tamanhoPrincipal):
            if (self.espera.isEmpty is not False):
                _retiradoEspera = self.__retiraCarroEspera()
                self.principal.insereNaFila(_retiradoEspera)
            return self.principal.removeDaFila()
        else:
            return self.principal.removeDaFila()

    def __retiraCarroEspera(self):
        return self.espera.removeDaFila()
    
    def listaPrincipal(self):
        self.principal.mostraFila()

    def listaEspera(self):
        self.espera.mostraFila()