#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;

bool checkEquivalent(string a, string b)
{
    int n_a = a.length();
    int n_b = b.length();

    if (a == b)
    {
        return true;
    }

    if (n_a % 2 != 0)
    {
        return false;
    }

    int mid_point = n_a / 2;

    string a1 = a.substr(0, mid_point);
    string a2 = a.substr(mid_point, a.length());
    string b1 = b.substr(0, mid_point);
    string b2 = b.substr(mid_point, b.length());

    return (checkEquivalent(a1, b2) && checkEquivalent(a2, b1)) || (checkEquivalent(a1, b1) && checkEquivalent(a2, b2));
}

int main()
{
    std::string a;
    std::string b;

    cin >> a;
    cin >> b;

    if (checkEquivalent(a, b))
    {
        cout << "YES"
             << endl;
    }
    else
    {
        cout << "NO"
             << endl;
    }

    return 0;
}
