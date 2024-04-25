#include <vector>
#include <iostream>

using namespace std;

bool izquierdaDominante(vector<int> v)
{
    if (v.size() == 4)
    {
        return v[0] + v[1] > v[2] + v[3];
    }

    if (v.size() == 2)
    {
        return v[0] > v[1];
    }

    int mid = v.size() / 2;

    vector<int> left(v.begin(), v.begin() + mid);
    vector<int> right(v.begin() + mid, v.end());

    return izquierdaDominante(left) && izquierdaDominante(right);
}

int main()
{
    vector<int> v = {8, 4, 7, 6, 5, 1, 3, 2};

    bool esIzqDom = izquierdaDominante(v);
    cout << (esIzqDom ? "The vector is left dominant" : "The vector is not left dominant") << endl;

    v = {8, 6, 7, 4, 5, 1, 3, 2};
    esIzqDom = izquierdaDominante(v);
    cout << (esIzqDom ? "The vector is left dominant" : "The vector is not left dominant") << endl;

    return 0;
}