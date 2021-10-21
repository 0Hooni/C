#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <string.h>
#include <queue>
#include <math.h>

using namespace std;
typedef long long ll;
void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int gcd(int num1, int num2){
    if(num1<num2) swap(num1, num2);

    int rest;
    while (num2 != 0){
        rest = num1 % num2;
        num1 = num2;
        num2 = rest;
    }
    return num1;
}

int main(){
    init();
    int t; cin >> t;
    while (t--){
        int A, B, x, y; //A, B : 숙련도, x : up_cost, y : down_cost
        cin >> A >> B >> x >> y;
        int _GCD = abs(A-B);
        int up_count = 0;
        ll up_cost = 0;
        while (1){
            A++; B++; up_count++;
            if(gcd(A, B) == _GCD) {
                up_cost = up_count * x;
                break;
            }
        }
        A -= up_count;
        B -= up_count;

        int down_count = 0;
        ll down_cost = 0;
        bool down_error = false;
        while (1){
            A--; B--; down_count++;
            if(A == 0 || B == 0) break;

            else if(gcd(A, B) == _GCD) {
                down_cost = down_count * y;
                break;
            }
        }
        if(down_cost == 0) cout << _GCD << " " << up_cost << "\n";
        else cout << _GCD << " " << min(up_cost, down_cost) << "\n";

    }
    return 0;
}

/*
 * 둘 사이에 차이는 항상 일정하다
 * 그래서 호흥도가 최대가 되는경우는 둘 사이의 차이가 일정할때 말고는 안된다.
 * 둘 사이의 간격이 최대공약수가 되는 경우의 수를 찾아서 계산해준다
 *
 * GCD 구현이 핵심
 *  1. 뒤에 파라미터가 큰 경우 swap
 *  2. rest = x%y, x=y, y=rest 를 반복해준다(y!=0일때까지)
 *  3. 탈출 한 이후 x가 최소공배수이므로 x를 리턴한다
 *
 * Error case : INT_MAX같은거 사용하지 말자
 * 다 내려가서 둘 중 하나가 0인 case가 발생하는경우 예외처리 해줘야됨
 */
