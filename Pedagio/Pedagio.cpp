#include <stdio.h>
#include <stdlib.h>
#include <list>
#include <iostream>
#include <string.h>
//#include <iterator>
using namespace std;

struct carro{
    char placa[20];
    char horario[20];
    char status[5];
    int km;
};

void printList(list<carro> lista){
    list<carro>::iterator it;
    cout << "TTTT" << endl;
    for(it = lista.begin();it != lista.end(); it++){
        cout <<"Placa:"<< it->placa << endl;
        cout <<"horario:"<< it->horario << endl;
        cout <<"status:"<< it->status << endl;
        cout << "Km:"<< it->km << endl;
    }
}

carro* leitura(){

}
int main(){
    
    //advance(it, 5); avança o iterator em 5 elementos
    
    int casos, valoresH[24];
    char linha[300] = "kk";
    list<carro> registros;

    scanf("%d",&casos);
    for(int i = 0; i < 24; i++)
       scanf("%d",&valoresH[i]);
    scanf("%c");
    
    for(int i = 0; i < casos; i++){
        while(strlen(linha) > 1 && fgets(linha,100,stdin)){
            carro dados;
            registros.clear();
            sscanf(linha,"%s %s %s %d",dados.placa,dados.horario,dados.status,&dados.km);
            registros.push_back(dados);
            printf("\n%s\n",linha);

        }
        printList(registros);
        //printf("%d", casos);
        //printf("\n%d", strlen(linha));
    }
    //printf("\nLinha: %s\n",linha);

        
        /*
        carro test;
        *(test.placa) = "caiu";
        printf("%s",test.placa);

        /*
        char *a = "caiu";
        a = "caiu";
        */
       /*
       char linha[10];
    fgets(linha,10,stdin);
    printf("%d", strlen(linha));
    */




/*
 char a[20];

 printf("%d",fgets(a,20,stdin));
 printf("%s",a);
 */

    

}