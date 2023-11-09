#include "../lista/lista.c"

typedef Lista Stack;

void push(Stack*, int);
int pop(Stack*);
int stacktop(Stack*);
int empty(Stack*);
Stack* newStack();

Stack* newStack(){
    return criaLista();
}

void push(Stack *s, int i){
    if (inserir(s, s->tail, i) == NULL)
        printf("Overflow: erro ao alocar memoria para a pilha\n");
}

int pop(Stack *s){
    int removido;
    removido = remover(s, s->tail);

    if (removido < 0)
        trataErro(removido);

    return removido;
}

int stacktop(Stack *s){
    return s->tail->dado;
}

int empty(Stack *s){
    return listaVazia(s);
}

int main(){
    Stack *s;
    printf("aaa");
    s = newStack();
    printf("bbb");

    if (s != NULL)
        printf("ddd");

    // Inverter a sequencia de numeros {5,4,3,2,1,0}
    push(s, 5);
    push(s, 4);
    push(s, 3);
    push(s, 2);
    push(s, 1);
    push(s, 0);

    printf("StackTop: %i\n", stacktop(s));

    escreveListaCaudaCabeca(s);
    printf("StackTop: %i\n", stacktop(s));
    
    printf("%i, ", pop(s));
    printf("%i, ", pop(s));
    printf("%i, ", pop(s));
    printf("%i, ", pop(s));
    printf("%i, ", pop(s));
    printf("%i, ", pop(s));

    printf("StackTop: %i\n", stacktop(s));
    escreveListaCaudaCabeca(s);
}