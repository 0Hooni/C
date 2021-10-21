#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

using namespace std;
typedef long long ll;
void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main()
{
    init();
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> price_x;
        vector<ll> price_y;
        vector<pair<ll, ll>> sum;
        for (int i = 0; i < n; i++)
        {
            ll x, y;
            cin >> x >> y;
            price_x.push_back(x);
            price_y.push_back(y);
            sum.push_back(make_pair(x + y, i));
        }
        sort(sum.begin(), sum.end(), greater<>());
        ll total_price_x = 0;
        ll total_price_y = 0;

        for (int i = 0; i < n; i++)
        {
            ll now_index = sum[i].second;

            if (i % 2 == 0)
                total_price_x += price_x[now_index];
            else
                total_price_y += price_y[now_index];
        }
        cout << total_price_x - total_price_y << "\n";
    }
    return 0;
}

/*
 * 자원을 더한 값이 최대인 자원 우선 선점
 * 1. 입력받은 값들을 각각의 원소들의 list에 넣어놓는다
 * 2. 각 차례마다 입력받은 두 값의 합과 그때의 인덱스를 저장하는 vector<pair>에 push해준다
 * 3. vector을 sort하여 가장 큰 index에 해댕하는 자원들을 선점하게 만든다.
 * 4. 턴은 번갈아가며 쓰기에 i가 짝수며 인하, 홀수면 비룡이 갖게 한다
 * 5. 전부 배분을 마쳤다면 값을 출력하고 프로그램을 끝낸다.
 *
 * Error case : Sort 할 때 역순(greather<>())을 넣지 않은 경우
 */