#include <iostream>
#include <vector>

using namespace std;

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
        string str;
        cin >> str;
        int n;
        cin >> n;
        if (n == 1)
            cout << str << "\n";
        else if (n >= str.size())
            cout << str << "\n";
        else
        {
            for (int i = 0; i < n; i++)
            {
                int now_idx = i;
                int now_mul = 0, now_row = 0;
                while (now_idx < str.size())
                {
                    if (now_row % 2 == 0)
                    {
                        now_mul = now_row;
                        now_idx = now_mul * n + i;
                        if (now_idx < str.size())
                            cout << str[now_idx];
                    }
                    else
                    {
                        now_mul = now_row + 1;
                        now_idx = now_mul * n - (i + 1);
                        if (now_idx < str.size())
                            cout << str[now_idx];
                    }
                    now_row++;
                }
            }
            cout << "\n";
        }
    }
}

/*
 * 주어진 n값에 따라 호출되는 한줄에 대한 공식이 있을것이다.
 * 2n단위로 계산을 생각.
 * 첫번째줄 : 0, 2n-1, 2n+0, 4n-1
 * 두번째줄 : 1, 2n-2, 2n+1, 4n-2
 * 세번째줄 : 2, 2n-3, 2n+2, 4n-3
 * i번째줄 : i, 2n-(i+1), 2n+i, 4n - (i+1)
 */