#include<stdio.h>
#include<stdlib.h>

int cont = 0,vizinhos[4][2] = {0,1,
                      0,-1,
                      1,0,
                      -1,0};

void printTab(int *vet){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++)
          printf("%d ",vet[4*i+j]);
        printf("\n");

    }

}

void resolve(int *tabela,int *posVazia){
    for(int i = 0; i < 4;i++){
            if(4*(posVazia[0]+ vizinhos[i][0])+ (posVazia[1] + vizinhos[i][1] < 16)){
                buscaSol(tabela,posVazia,i);
            }

        
    }
       
  

    

}

int main(){
    int tabela[16],tam,posVazia[2];
    scanf("%d",&tam);
    while(tam){
        for(int i = 0; i < 4;i++){
            for(int j = 0; j < 4;j++){
                scanf("%d",&tabela[i*4+j]);
                if(tabela[i*4+j] == 0)
                posVazia[0] = i;
                posVazia[1] = j;
            }
        }
        resolve(tabela,posVazia);
        printTab(tabela);
        printf("\n");
        tam--;
    }

}