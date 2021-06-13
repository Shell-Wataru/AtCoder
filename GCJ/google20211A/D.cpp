#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <map>
#include <set>
using namespace std;
using ll = long long;

void reverse(vector<ll> &answer)
{
    reverse(answer.begin(), answer.end());
}

void complement(vector<ll> &answer)
{
    for (int i = 0; i < answer.size(); i++)
    {
        if (answer[i] == -1)
        {
            answer[i] = -1;
        }
        else if (answer[i] == 1)
        {
            answer[i] = 0;
        }
        else
        {
            answer[i] = 1;
        }
    };
}

ll update(vector<ll> &answer)
{
    ll different_index = -1;
    ll same_index = -1;
    for (int i = 0; i < answer.size() / 2; i++)
    {
        if (answer[i] == answer[answer.size() - 1 - i] && answer[i] != -1)
        {
            same_index = i;
        }
        else if ((answer[i] == 1 && answer[answer.size() - 1 - i] == 0) || (answer[i] == 0 && answer[answer.size() - 1 - i] == 1))
        {
            different_index = i;
        }
    }

    ll lower_confirmed = -1;
    ll upper_confirmed = answer.size();
    for (int i = 0; i < answer.size() / 2; i++)
    {
        if (answer[i] != -1)
        {
            lower_confirmed = i;
        }
    }

    for (int i = 0; i < answer.size() / 2; i++)
    {
        if (answer[answer.size() - 1 - i] != -1)
        {
            upper_confirmed = answer.size() - 1 - i;
        }
    }

    if (different_index == -1 && same_index == -1)
    {
        for (int i = 0; i < 5; i++)
        {
            cout << i + 1 << endl;
            cin >> answer[i];
        }
        for (int i = 0; i < 5; i++)
        {
            cout << answer.size() - i << endl;
            cin >> answer[answer.size() - i - 1];
        }
    }
    else if (different_index == -1 && same_index != -1)
    {
        ll a;
        cout << 1 << endl;
        cin >> a;
        cout << 1 << endl;
        cin >> a;
        if (answer[0] != a)
        {
            complement(answer);
        }

        for (int i = 0; i < 4; i++)
        {
            cout << lower_confirmed + 1 + i + 1 << endl;
            cin >> answer[lower_confirmed + i + 1];
        }

        for (int i = 0; i < 4; i++)
        {
            cout << upper_confirmed - i << endl;
            cin >> answer[upper_confirmed - i - 1];
        }
    }
    else if (different_index != -1 && same_index == -1)
    {
        ll a;
        cout << 1 << endl;
        cin >> a;
        cout << 1 << endl;
        cin >> a;
        if (answer[0] != a)
        {
            complement(answer);
        }

        for (int i = 0; i < 4; i++)
        {
            cout << lower_confirmed + 1 + i + 1 << endl;
            cin >> answer[lower_confirmed + i + 1];
        }

        for (int i = 0; i < 4; i++)
        {
            cout << upper_confirmed - i << endl;
            cin >> answer[upper_confirmed - i - 1];
        }
    }
    else
    {
        ll a;
        cout << same_index + 1 << endl;
        // cerr << same_index + 1 << endl;
        cin >> a;
        ll b;
        cout << different_index + 1 << endl;
        // cerr << different_index + 1 << endl;
        cin >> b;
        if (answer[same_index] == a)
        {
            if (answer[different_index] == b)
            {
            }
            else
            {
                reverse(answer);
            }
        }
        else
        {
            if (answer[different_index] == b)
            {
                reverse(answer);
                complement(answer);
            }
            else
            {
                complement(answer);
            }
        }

        // cerr << lower_confirmed << " " << upper_confirmed << endl;
        for (int i = 0; i < 4; i++)
        {
            cout << lower_confirmed + 1 + i + 1 << endl;
            cin >> answer[lower_confirmed + i + 1];
        }

        for (int i = 0; i < 4; i++)
        {
            cout << upper_confirmed - i << endl;
            cin >> answer[upper_confirmed - i - 1];
        }
    }
    return 0;
}

ll solve(ll b)
{
    vector<ll> answer(b, -1);
    for (int i = 0; i < 15; i++)
    {
        update(answer);
        // for (int i = 0; i < b; i++)
        // {
        //     cerr << answer[i];
        // }
        // cerr << endl;
    }
    for (int i = 0; i < b; i++)
    {
        cout << answer[i];
    }
    cout << endl;
    string result;
    cin >> result;
    // cerr << result << endl;
    return 0;
}
int main()
{
    // 整数の入力
    ll T, b;
    cin >> T >> b;
    // cerr << T << " " << b << endl;
    for (int i = 1; i <= T; i++)
    {
        solve(b);
    }
    return 0;
}