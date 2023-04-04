import sys
sys.path.append(".")

from model.lista_dupla import ListaDupla

def main():
    lista = ListaDupla()
    lista.insereElementoNaLista(None, 10)
    lista.insereElementoNaLista(lista.head, 5)
    lista.insereElementoNaLista(lista.tail, 7)
    lista.insereElementoNaLista(None, 19)
    lista.insereElementoNaLista(lista.head, 22)

    lista.percorreListaHeadTail()

    
    try:
        _dado = lista.removeElementoDaLista(None)
    except Exception as e:
        print(e)
    else:
        print("Removido o dado: %s " % _dado)

    lista.percorreListaHeadTail()
    
    _nodo = lista.encontraElementoNaLista(10)
    try:
        _dado = lista.removeElementoDaLista(_nodo)
    except Exception as e:
        print(e)
    else:
        print("Removido o dado: %s " % _dado)


main()
