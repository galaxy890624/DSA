#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    int n, a=1, num=1, k;
    cin >> n;
    for(int row = 1; row <= n; row++)
    {
        num = a;
        a += row;
        k = row + 1;
        for(int col = 1; col <= n-row+1; col++)
        {
            cout << num << " ";
            num+=k;
            k++;
        }
        cout << endl;
    }
    return 0;
}
