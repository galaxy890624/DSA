#include <iostream>
#include <cstdlib>

using namespace std;

// C(n, k)
int C(int n, int k)
{
    // Boundary condition
    if(k == 0)
    {
        return 1;
    }
    if(n == 0 || n == k)
    {
        return 1;
    }
    // General form of recursion
    return C(n-1, k-1) + C(n-1, k);
}

int main()
{
    // Test case
    cout << C(6, 3) << endl;

    return 0;
}
