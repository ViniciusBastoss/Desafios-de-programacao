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
    for(it = lista.begin();it != lista.end(); it++){
        cout <<"Placa:"<< it->placa << endl;
        cout <<"horario:"<< it->horario << endl;
        cout <<"status:"<< it->status << endl;
        cout << "Km:"<< it->km << endl;
        printf("%d",it);
    }
}

int compara(const void *a,const void *b){
    carro carro1 = *(carro*)a;
    carro carro2 = *(carro*)b;
    if(carro1.km > carro2.km)
       return 1;
    return 0;

}

carro* processaRegistro(list<carro> *registros,int *tarifa){
    list<carro>::iterator it = registros->begin();
    qsort(registros,sizeof(carro),registros->size(),compara);
    printList(*registros);

}
int main(){
    
    //advance(it, 5); avança o iterator em 5 elementos
    
    int casos, tarifa[24];
    char linha[300];
    list<carro> registros;

    scanf("%d",&casos);
    for(int i = 0; i < 24; i++)
       scanf("%d",&tarifa[i]);
    scanf("%c");
    
    for(int i = 0; i < casos; i++){
        while(fgets(linha,100,stdin) && strlen(linha) > 1){
            carro dados;
            sscanf(linha,"%s %s %s %d",dados.placa,dados.horario,dados.status,&dados.km);
            registros.push_back(dados);
            printf("\nNN:%s\n",linha);
        }
        //processaRegistro(&registros,tarifa);

        printList(registros);
        registros.clear();
        
 
    }
}