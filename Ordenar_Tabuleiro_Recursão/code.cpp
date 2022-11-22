#include <stdio.h>
#include <stdlib.h>

struct direcao
{
    int x;
    int y;
};

struct no_
{
    char direc;
    // no_ *dir = NULL;
    // no_ *esq = NULL;
    // no_ *acima = NULL;
    // no_ *baixo = NULL;
    no_ *lados[4] = {NULL, NULL, NULL, NULL};
} no;

direcao vizinhos[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

char letras[4] = {'R', 'L', 'U', 'D'};

no_ *primeiroNo;

bool parar = 0;

void printArv()
{
    no_ *filho;
    for (int i = 0; i < 4; i++)
    {
        filho = primeiroNo->lados[i];
        if (filho != NULL)
        {
            printf("%c  ", filho->direc);
        }
    }
}

void printTab(int *vet)
{
    printf("\nPercorrendo Arvore\n");
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
            printf("%d ", vet[4 * i + j]);
        printf("\n");
    }
}

void resolve(int posVazia[2], no_ *noAnterior, int cont)
{
    if (cont >= 10)
    {
        parar = 1;
        
        printArv();
        //printf("Arvore");
    }
    else
    {
        int novaPvazia[2];
        for (int i = 0; i < 4; i++)
        {
            novaPvazia[0] = posVazia[0] + vizinhos[i].x;
            novaPvazia[1] = posVazia[1] + vizinhos[i].y;
            if ((4 * novaPvazia[0] + novaPvazia[1]) < 16 && !parar)
            {
                // printf("Teste");
                no_ *novo;
                novo = (no_ *)calloc(1, sizeof(no_));
                novo->direc = letras[i];
                noAnterior->lados[i] = novo;
                //printf("%c ",novo->direc);
                cont++;
                resolve(novaPvazia, novo, cont);
                cont--;

                // buscaSol(tabela,posVazia,i);
            }
        }
    }
}

int main()
{
    int tabela[16], tam, posVazia[2], cont = 0;
    primeiroNo = (no_ *)calloc(1, sizeof(no_));
    scanf("%d", &tam);
    while (tam)
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                scanf("%d", &tabela[i * 4 + j]);
                if (tabela[i * 4 + j] == 0)
                    posVazia[0] = i;
                posVazia[1] = j;
            }
        }
        resolve(posVazia, primeiroNo, cont);
        //printTab(tabela);
        printf("\n");
        tam--;
    }
}