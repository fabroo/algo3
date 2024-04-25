#include <iostream>

using namespace std;
int log_exp(int a, int b)
{
    if (b == 1)
    {
        return a;
    }
    if (b == 2)
    {
        return a * a;
    }

    int b_mid = b / 2;
    return log_exp(a, b_mid) * log_exp(a, b - b_mid);
}

int main()
{
    int a;
    int b;

    cin >> a;
    cin >> b;

    cout << "\na^b = " << log_exp(a, b) << "\n";
    return 0;
}