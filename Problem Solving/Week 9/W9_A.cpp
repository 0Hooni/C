#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <string.h>
#include <queue>
#include <math.h>
using namespace std;
typedef long long ll;

ll count(ll r, ll n){
    return ((pow(r, n+1) - 1)/(r-1)) - 1;
}

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
int main() {
    init();
    int t; cin >> t;
    while (t--){
        ll x, n, m; cin >> x >> n >> m;
        cout << count(x, n)%m << "\n";
    }
    return 0;
}

/*
 *
 */
