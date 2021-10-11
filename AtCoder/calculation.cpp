#include <iostream>
#include <vector>


using namespace std;

// x^n‚ÌŒvZ
int powXN_(int x, int n)
{
    int ans = 1;
    for (int i = 0; i < n; i++)
    {
        ans *= x;
    }
    return ans;
}

