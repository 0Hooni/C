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
        int student, word;
        cin >> student >> word;

        queue<string> sentence; //교수님이 말씀하진 문장
        for (int i = 0; i < word; i++)
        {
            string str;
            cin >> str;
            sentence.push(str);
        }

        queue<string> listen[21]; //학생들이 들은 문장
        for (int i = 0; i < student; i++)
        {
            int how_much;
            cin >> how_much;
            while (how_much--)
            {
                string str;
                cin >> str;
                listen[i].push(str);
            }
        }

        int res = 1;
        for (int i = 0; i < word; i++)
        {
            for (int j = 0; j < student; j++)
            {
                if (sentence.front() == listen[j].front())
                {
                    sentence.pop();
                    listen[j].pop();
                    break;
                }

                if (j == student - 1)
                {
                    res = 0;
                    break;
                }
            }
        }
        cout << res << "\n";
    }
}

/*
 * 각각의 학생들이 들은 단어들(queue)을 주어진 문장(queue)의 맨 앞(.front())과 비교
 * 만일 각각 학생들의 단어목록에 첫번째(.front)에 해당하면 pop(단어, 문장 둘 다)
 * 학생들을 한바퀴 돌동안 문장과 일치하는 단어가 없었다면 fail이며 반복 마무리(res = 0)
 * 다 비교하여 끝나면 그것도 마무리(res = 1, 초기값으로 설정)
 */