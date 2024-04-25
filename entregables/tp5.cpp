#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;

int minAmount(vector<int> inhabitants, int n)
{
    int available = 0;
    int need = 0;
    int work = 0;

    for (int i = 0; i < n - 1; i++)
    {
        if (inhabitants[i] > 0)
        {
            need += inhabitants[i];
        }
        if (inhabitants[i] <= 0)
        {
            available += 1;
        }
        int d = need - available;
        // print d
        cout << "D: " << d << "\n";
        work += d;
    }
    return work;
}

int main()
{
    int n = 5;
    vector<int> inhabitants = {5, -4, 1, -3, 1};

    int min = minAmount(inhabitants, n);

    cout << "la menor cantidad es: " << min << "\n";
    return 0;
}