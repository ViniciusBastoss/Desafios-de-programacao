#include <stdio.h>
#include <math.h>

static double menor = INFINITY;

double minimo(double a, double b)
{
    return a < b ? a : b;
}

void process_solution(double a[], int k)
{
    int i;
    printf("{");
    for (int i = 0; i < k; i++)
    {
        printf("%lf ", a[i]);
    }
    printf("} -> ");

    double base_caixa = a[0], y1, y2, y_direto;
    for (i = 0; i < k - 1; i++)
    {
        y1 = sqrt(pow(a[i] + a[i + 1], 2) - pow(a[i] - a[i + 1], 2));
        y2 = sqrt(pow(a[i + 1] + a[i + 2], 2) - pow(a[i + 1] - a[i + 2], 2));
        y_direto = sqrt(pow(a[i] + a[i + 2], 2) - pow(a[i] - a[i + 2], 2));
        if (y1 + y2 > y_direto)
        {
            base_caixa += y1;
        }
        else
        {
            base_caixa += y_direto;
            i += 1;
        }
    }
    base_caixa += a[k - 1];
    if (base_caixa < menor)
        menor = base_caixa;
    printf("%lf \n", base_caixa);
}

void permuta(double *V, int inicio, int fim)
{
    if (inicio == fim - 1)
    {
        process_solution(V, fim);
        return;
    }
    else
    {
        int i;
        double tmp;
        for (i = inicio; i < fim; i++)
        {
            tmp = V[i];
            V[i] = V[inicio];
            V[inicio] = tmp;
            permuta(V, inicio + 1, fim);
            V[inicio] = V[i];
            V[i] = tmp;
        }
    }
}

int main()
{
    double vetor[3] = {2.0, 1.0, 2.0};
    permuta(vetor, 0, 3);
    printf("menor: %lf", menor);
}
