#include <stdio.h>
#include <stdlib.h>
#include <list>
#include <iostream>
#include <string.h>
//#include <iterator>
using namespace std;

struct carro
{
    char placa[40];
    char horario[20];
    char status[5];
    int km;
};


void printList(list<carro> lista)
{
    //list<carro>::iterator it;
    for (auto it : lista)
    {
        cout << "  Placa:" << it.placa;
        cout << "  horario:" << it.horario;
        cout << "  status:" << it.status;
        cout << "  Km:" << it.km << endl;
    }
    cout << endl;
}

// criterio de comparação para a ordenaçao
bool compara(const carro carro1, const carro carro2)
{
    int result;
    result = strcmp(carro1.placa, carro2.placa);
    if (result > 0)
        return 0;
    else if (result < 0)
        return 1;
    result = strcmp(carro1.horario, carro2.horario);
    if (result > 0)
        return 0;
    else if (result < 0)
        return 1;
    return 0;
}

void validaRegistros(list<carro> *registros)
{
    list<carro>::iterator it2, it = registros->begin();
    it2 = next(it,1);
    //it2 = it++;
    //it--;
    
    while (it != registros->end() && it2 != registros->end())
    {
        if (it->status[1] == 'x' || (it->status[1] == 'n' && it2->status[1] == 'n'))
        {
            registros->erase(it);
            it = next(it2,0);
            if (it2 != registros->end())
                it2++;
        }
        else
        { 
            if (it2 != registros->end())
            {
                if(abs(strcmp(it->placa,it2->placa))){
                    registros->erase(it);
                    it = it2;
                    if (it2 != registros->end())
                    it2++;
                }
                else{
                advance(it, 2);
                advance(it2, 2);
                }
            }
        }
        if(it2 == registros->end()){
            it2--;
            if(it2->status[1] == 'n'){
                registros->erase(it2);
                it2 = registros->end();
            }
        if(it2->km == it->km){
            registros->erase(it);
            it2 = registros->end();
        }

        }
    }
    //printList(*registros);
}

void calculaTarifa(list<carro> registros, int *valoresTarifa){
    char indice[2],*placaAt;
    float total = 2;
    carro veiculo,veiculo2,aux;
    while(registros.size() > 0){
        aux = *registros.begin();
        veiculo = *registros.begin();
        veiculo2 = *next(registros.begin(),1);
        while(!abs(strcmp(veiculo.placa,aux.placa))){
           indice[0] = veiculo.horario[6];
           indice[1] = veiculo.horario[7];
           total +=  1 + (float)abs(veiculo2.km - veiculo.km) * ((valoresTarifa[atoi(indice)]/100.00)); 
           registros.pop_front();
           registros.pop_front();
           veiculo = *registros.begin();
           veiculo2 = *next(registros.begin(),1);
        }
        printf("%s $%.2f\n",aux.placa,total);
        //cout << aux.placa <<" "<< "$" << total << endl;
        total = 2;
    }
}
void processaRegistro(list<carro> *registros, int *tarifa)
{
    
    list<carro>::iterator it = registros->begin();
    registros->sort(compara);
    //printList(*registros);
    // it = registros->begin();
    // registros->erase(it);
    validaRegistros(registros);
   // printf("\nValidado:\n");
    //printList(*registros);
}
int main()
{

    // advance(it, 5); avança o iterator em 5 elementos

    int casos, tarifa[24];
    char linha[300] = "kkk";
    list<carro> registros;
    list<carro>::iterator it;
    carro aux;
    
    scanf("%d", &casos);
    for (int i = 0; i < casos; i++)
    {
        for (int i = 0; i < 24; i++)
        scanf("%d", &tarifa[i]);
        scanf("%d");
        carro dados;
        while (fgets(linha, 100, stdin))
        {
            if(strlen(linha) <= 1) break;
            //printf("\nLinha:%s",linha);
            sscanf(linha, "%s %s %s %d", dados.placa, dados.horario, dados.status, &dados.km);
            //printf("\nLinha:%sm Placa:%s",linha,dados.placa);
            registros.push_back(dados);
        }
        processaRegistro(&registros, tarifa);
        calculaTarifa(registros,tarifa);
        cout << endl;
        //printList(registros);
        registros.clear();
    }
    
   /*
   list<carro> registro;
   char linha[100] = "dbqu 01:26:18:07 exit 687";
   carro dados;
   sscanf(linha, "%s %s %s %d", dados.placa, dados.horario, dados.status, &dados.km);
   registro.push_back(dados);
   registro.push_back(dados);
   registro.push_back(dados);
   printf("\nPlaca:%s",registro.end()->placa);
   */
   /*
  list<int> vet;
  
  vet.push_back(500);
  vet.push_back(100);
  vet.push_back(600);

  //printf("\nValor:%d",vet.begin()->a);
  cout << *next(vet.end(),-1);
  */

}