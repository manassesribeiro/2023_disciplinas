import sys
sys.path.append(".")

from stack.model.stack import Stack

def main():
    stack = Stack()
    print("Empilhando valores de 0 a 9")
    for i in range(10):
        print(i)
        stack.push(i)

    print("Valores empilhados (em ordem de desempilhamento)")
    stack.showStack()

    print("Desempinhamento")
    for i in range(12):
        try:
            print(stack.pop())
        except Exception as e:
            print(e)

        
main()
