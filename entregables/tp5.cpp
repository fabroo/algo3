#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
using namespace std;

long long cantidadMinima(vector<long long> &inhabitants, long long n)
{
    long long workUnits = 0;
    for (long long i = 0 ; i < n - 1;  i++){
        workUnits += abs(inhabitants[i]);
        inhabitants[i + 1] = inhabitants[i + 1] + inhabitants[i];
    }
    return workUnits;
}

int main()
{
    while (true){
        long long N;
        cin >> N;
        if (N == 0){
            break;
        }
        vector<long long> inhabitants(N);
        for (long long inh = 0; inh < N ; inh++){
            cin >> inhabitants[inh];
        }

        long long minWorkUnits = cantidadMinima(inhabitants, N);
        printf("%lld\n", minWorkUnits);
    }

    return 0;
}
