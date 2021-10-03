#include <iostream>
#include <string.h>
#include <queue>
#include <stack>

using namespace std;
void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int gcd(int a, int b) {
    int c;
    while (b != 0) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int main(){
    init();
    int t; cin >> t;
    while (t--){
        int A, B, x, y;
        cin >> A >> B >> x >> y;
        int goal = abs(A-B);

        int up_count = 0;
        int _A = A, _B = B;
        while (gcd(_A, _B) != goal){
            _A++; _B++; up_count++;
        }

        int cant_down = 0;
        int down_count = 0;
        _A = A; _B = B;
        while (gcd(_A, _B) != goal){
            if(_A <= 0 || _B <= 0){
                cant_down = 1;
                break;
            }
            _A--; _B--; down_count++;
        }
        int min_cost = 0;
        if(up_count*x < down_count*y || cant_down) {
            A = A + up_count;
            B = B + up_count;
            min_cost = up_count*x;
        }
        else{
            A = A - down_count;
            B = B - down_count;
            min_cost = down_count*y;
        }

        cout << gcd(A, B) << " " << min_cost << "\n";
    }

    return 0;
}
