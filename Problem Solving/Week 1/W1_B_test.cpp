#include <iostream>
#include <vector>
#include <stack>
#include <queue>

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
        int n;
        cin >> n;
        stack<int> _min;
        stack<int> _max;
        stack<int> block;
        while (n--)
        {
            int task;
            cin >> task;
            if (task == 1)
            {
                int tmp;
                cin >> tmp;
                block.push(tmp);

                if (_min.empty())
                    _min.push(tmp);
                else if (_min.top() >= tmp)
                    _min.push(tmp);

                if (_max.empty())
                    _max.push(tmp);
                else if (_max.top() <= tmp)
                    _max.push(tmp);

                cout << _min.top() << " " << _max.top() << "\n";
            }
            else if (task == 2 && !block.empty())
            {
                int now = block.top();
                block.pop();

                if (now == _min.top())
                    _min.pop();
                if (now == _max.top())
                    _max.pop();
            }
        }
    }
}

/*
 * 입력받은 값을 블록탑(Stack)에 push해준다
 * 이 때 만일 초기값이라면 최대(Stack) 최소(Stack) 또한 현재값으로 push해준다.
 * 다음 입력값 부터는 최대는 같거나 클때, 최소는 크거나 같을때 push해준다.
 * 2번 연산(pop)이 되면 블록탑에서 top과 같은 원소들을 pop해준다.
 * 이 때 최대 혹은 최소가 같을때 Push 연산을 미리 하지 않았다면 pop이 진행될때
 * 동일한 최대 혹은 최소가 있다해도 다르게 최대 최소가 잡힐 수 있다.
 *
 * RUN ERROR : 2번 질의가 진행될때 empty에 대한 case를 예외처리 하지 않은 경우우 */