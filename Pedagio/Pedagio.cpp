#include <stdio.h>
#include <stdlib.h>

struct carro{
    char placa[20];
    char horario[20];
    char status[5];
    int km;
};

carro* leitura(){

}
int main(){
    
    int casos, valoresH[24];
    char linha[300];

    scanf("%d",&casos);
    for(int i = 0; i < 24; i++)
       scanf("%d",&valoresH[i]);
    
    
    while(fgets(linha,100,stdin)){
        printf("\nLinha: %s\n",linha);
        carro* dados = new carro;
        sscanf(linha,"%s %s %s %d",dados->placa,dados->horario,dados->status,&dados->km);
        printf("%s %s %s %d",dados->placa,dados->horario,dados->status,dados->km);
        
        /*
        carro test;
        *(test.placa) = "caiu";
        printf("%s",test.placa);

        /*
        char *a = "caiu";
        a = "caiu";
        */
    }



/*
 char a[20];

 printf("%d",fgets(a,20,stdin));
 printf("%s",a);
 */

    

}