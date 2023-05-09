/*
    Q2: (4 pontos) Faça um programa em JS que leia dois vetores (vetores “a” e “b”) de números inteiros com 10 números cada. Na sequência carregue um terceiro vetor (vetor “c”) que será formado pela diferença dos dois vetores lidos (elemento a elemento) e calcule também a média do vetor “c”. Por fim, escreva o vetor “c” na ordem inversa e a média calculada.
*/
Algoritmo Q2
inicio
    constante TAM 10
    inteiro a[TAM], b[TAM], c[TAM], i;
    real media;
    media =0;

    // Procedimento para carregar os vetores 'a' e 'b'
    para i de 0 até TAM-1 passo 1 faça
    inicio
        escreva("Informe um valor para a[%i]" % i);
        leia(a[i]);
        escreva("Informe um valor para b[%i]" % i);
        leia(b[i]);
    fimPara

    // Procedimento para carregar o vetor 'c' com a diferença de 'a' e 'b'
    para i de 0 até TAM-1 passo 1 faça
    inicio
        c[i] = a[i] - b[i];
        media = media + c[i];
    fimPara

    // Procedimento para escrever o vetor 'c' na ordem inversa
    para i de TAM-1 até 0 passo 1 faça
    inicio
        escreva(c[i]);        
    fimPara
    
    //Calcula e escreve a média
    media = media / TAM;
    escreva(media);
fim