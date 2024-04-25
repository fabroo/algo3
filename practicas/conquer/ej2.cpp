#include <vector>
#include <iostream>

using namespace std;

int indiceEspejo(vector<int> a, int l, int r)
{ // print a
    cout << "l:" << l << " r:" << r << "\n";

    int mid = l + r / 2;

    if (l == r)
    {
        return -1;
    }
    if (a[mid] == mid + 1)
    {
        return mid;
    }
    if (a[mid] > mid + 1)
    {
        return indiceEspejo(a, l, mid);
    }
    if (a[mid] < mid + 1)
    {
        return indiceEspejo(a, mid, r);
    }
    return -1;
}

int main()
{
    int index = -1;

    vector<int> a = {-4, -1, 2, 4, 7};

    index = indiceEspejo(a, 0, a.size() - 1);
    cout << index << "\n";
    return 0;
}