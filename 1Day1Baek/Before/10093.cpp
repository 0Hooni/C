#include <iostream>

using namespace std;

int main()
{
    long long a, b;

    cin >> a >> b;
    if(a > b) swap(a,b);

    if(a != b){
        cout << b - a - 1 << "\n";
        for(long long i = a + 1; i < b; i ++)
            cout << i << " ";
    }
    else cout << 0 << "\n";

    return 0;
}