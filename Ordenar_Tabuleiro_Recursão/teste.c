#include <stdio.h>
#include <stdlib.h>

void testa(int vet[2]){
    printf("%d",vet[1]);
    vet[1] = 4;
}

int main(){
    int vet[2] = {2,3};  

    testa(vet);
    printf("%d",vet[1]);

}