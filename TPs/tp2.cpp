#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n;
    scanf("%d", &t);
    for (int k = 1; k <= t; k++)
    {
        scanf("%d", &n);
        int h[n], w[n], lis[n], lds[n];

        // completo las heights y widths
        for (int i = 0; i < n; i++)
            scanf("%d", &h[i]);
        for (int i = 0; i < n; i++)
            scanf("%d", &w[i]);

        // vamos a calcular la LIS que termina en i (subproblema optimo)
        for (int i = 0; i < n; i++)
        {
            // sabemos que el minimo valor mas grande para cada i, es el width del edificio i solo
            lis[i] = w[i];
            for (int j = 0; j < i; j++)
            {
                if (h[i] > h[j])
                    lis[i] = max(lis[i], lis[j] + w[i]);
            }
        }

        // vamos a calcular la LDS que termina en i (subproblema optimo)
        for (int i = 0; i < n; i++)
        {
            // sabemos que el minimo valor mas grande para cada i, es el width del edificio i solo
            lds[i] = w[i];
            for (int j = 0; j < i; j++)
            {
                if (h[i] < h[j])
                    lds[i] = max(lds[i], lds[j] + w[i]);
            }
        }

        int suma_creciente = 0;
        int suma_decreciente = 0;
        // tanto para LIS como LDS buscamos cuales son la maxima suma que obtenemos = maxima subsec.
        for (int i = 0; i < n; i++)
        {
            suma_creciente = max(suma_creciente, lis[i]);
            suma_decreciente = max(suma_decreciente, lds[i]);
        }
        if (suma_creciente >= suma_decreciente)
        {
            printf("Case %d. Increasing (%d). Decreasing (%d).\n", k, suma_creciente, suma_decreciente);
        }
        else
        {
            printf("Case %d. Decreasing (%d). Increasing (%d).\n", k, suma_decreciente, suma_creciente);
        }
    }
    return 0;
}