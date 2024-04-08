#include <iostream>
#include <vector>
#include <numeric>
#include <limits>

using namespace std;

vector<int> lis;
int best_increasing_sum = 0;

vector<int> longestIncreasingSequence(int i, int last, vector<int> &temp, vector<int> h, vector<int> w, vector<int> &M)
{
    if (i == h.size())
    {
        int sum = accumulate(temp.begin(), temp.end(), 0);
        if (temp.size() >= lis.size() && sum > best_increasing_sum)
        {
            lis = temp;
            best_increasing_sum = sum;
        }
        return lis;

        if (h[i] >= last)
        {
            if (M[i + 1] == numeric_limits<int>::min())
            {
                vector<int> newVec = temp;
                newVec.push_back(w[i]);

                
                M[i + 1] = 
            }
        }
    }
}
int main()
{
    vector<int> h = {1, 2, 3};
    cout << "cant tests \n";
    return 0;
}
