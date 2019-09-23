#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>

using namespace std;
using ll = long long;
ll BASE_NUM = 998244353;

int main()
{
    // 整数の入力
    long long N, first_questions, second_questions, diff;
    diff = 0;
    first_questions = 0;
    second_questions = 0;
    string s;
    cin >> N;
    cin >> s;
    for (int i = 0; i < N / 2; i++)
    {
        if (s[i] == '?')
        {
            first_questions++;
        }
        else
        {
            diff += s[i] - '0';
        }
    }

    for (int i = N / 2; i < N; i++)
    {
        if (s[i] == '?')
        {
            second_questions++;
        }
        else
        {
            diff -= s[i] - '0';
        }
    }

    ll questions_diff = first_questions - second_questions;
    if (questions_diff == 0)
    {
        if (diff == 0)
        {
            cout << "Bicarp" << endl;
        }
        else
        {
            cout << "Monocarp" << endl;
        }
    }
    else
    {
        if (questions_diff % 2 == 1)
        {
            cout << "Monocarp" << endl;
        }
        else
        {
            if (questions_diff > 0 && diff == -9 * questions_diff / 2)
            {
                cout << "Bicarp" << endl;
            }
            else if (questions_diff < 0 && diff == -9 * questions_diff / 2)
            {
                cout << "Bicarp" << endl;
            }
            else
            {
                cout << "Monocarp" << endl;
            }
        }
    }
    return 0;
}