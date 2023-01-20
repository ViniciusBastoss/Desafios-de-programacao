#include <stdio.h>
#include <stdlib.h>


int achaPosicao(int numero, int *linha, int *coluna){
    int  mult = 1, valorSup = 0, caminho;

    while(valorSup < numero){
        valorSup = mult * mult;
        mult += 2;
    }

    *linha = mult - 2;
    caminho = (*linha) - 1;

    if(valorSup == numero)
       return 1;
    //direita
    for(int i = 0; i < caminho; i++){
        (*coluna)++;
        valorSup--;
        if(valorSup == numero)
          return 1;
    }
    //baixo
    for(int i = 0; i < caminho; i++){
       (*linha)--;
       valorSup--;
       if(valorSup == numero)
         return 1;
    }
    //giro
    (*coluna)--;
    valorSup--;
    caminho--;
    if(valorSup == numero)
        return 1;
    //cima

    for(int i = 0; i < caminho; i++){
      (*linha)++;;
      valorSup--;
      if(valorSup == numero)
         return 1;
    }

    //esquerda
    for(int i = 0; i < caminho; i++){
      (*coluna)--;;
      valorSup--;
       if(valorSup == numero)
         return 1;
    }

    //giro
    (*linha)++;
    valorSup--;
    caminho--;
    if(valorSup == numero)
       return 1;

}

int main(){
    int numero, linha = 0, coluna = 1;
    scanf("%d", &numero);
    while(numero > 0){
        achaPosicao(numero, &linha, &coluna);
        printf("%d %d\n", coluna, linha);
        scanf("%d", &numero);
        coluna = 1;
        linha = 0;
    };
}