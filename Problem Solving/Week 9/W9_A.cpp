#include <iostream>
#include <math.h>

typedef long long ll;
using namespace std;
void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

ll large_X, large_N, mod;    // large_X: X large_N: N mod: 나누는 수(M)

ll myPow(ll x, ll n) {
    // x^n 연산하는 방법
    if(n == 0) return 1;    // 0인 경우
    if(n % 2 == 1){    // 홀수일 때
        // x^x = x * x^(n-1), 차수를 낮춰서 오버플로우를 방지
        return (x * myPow(x, n - 1)) % mod;
    }
    else{   // 짝수일 때
        // x^n = (x^2) * x^_(n/2)
        // 연속해서 짝수가 돼서 x^2이 너무 커져서 오버플로우가 일어날 수 있기에 mod
        return myPow((x * x) % mod, n / 2) % mod;
    }
}

// 분할정복(Divide And Conquer)
ll div_conq(ll start, ll end, ll size){
    // X^start + ... + X^end, end - start + 1 = size
    // 덧셈들을 잘게 나눠서 1개씩으로 만들음. 만들고 나서는 pow 연산을 해준다.
    if(size == 1)
        return myPow(large_X, start) % mod;

    // 반으로 나누는 지점을 정하는 것에 중점으로
    if(size % 2 == 0)  { // 덧셈의 길이가 짝수일 때(N이 짝수)
        // ex: 2^1 + 2^2 + ... 2^8 -> start: 1 end: 8 size: 8
        // => (1 + 2^4)(2^1 + 2^2 + ... 2^4) -> s:1 e:1+4-1 s:4
        return
        (1 + (myPow(large_X, (size / 2)))
        * div_conq(start, start + (size / 2) - 1, size / 2))
        % mod;
    }
    else {    // 덧셈의 길이가 홀수일 때(N이 홀수)
        // ex: 2^1 + 2^2 + ... 2^9 -> start: 1 end: 9 size: 9
        // => (1 + 2^4)*(2^1 + 2^2 + ... + 2^4) + 2^9 -> s:1 e:1+4-1 s:4
        return
        ((1 + myPow(large_X, (size / 2)))
        * div_conq(start, start + (size / 2) - 1, size / 2))
        % mod
        + (div_conq(end, end, 1));
    }
}

int main(){
    init();
    int T; cin >> T;
    while (T--){
        cin >> large_X >> large_N >> mod;
        // large_X^1 + large_X^2 + ... + large_X^n
        cout << div_conq(1, large_N, large_N) << "\n";
    }
    return 0;
}

/*
 */
