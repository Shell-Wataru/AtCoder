#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>

using namespace std;
using ll = long long;

int main()
{
    // 整数の入力
    string s;
    ll k;
    cin >> s;
    if (s == "0")
    {
        cout << 0 << endl;
    }
    else if (s == "1")
    {
        cout << 1 << endl;
    }
    else
    {
        k = (s.length() - 1) / 2 + 1;
        bool has_one = false;
        for (int i = 1; i < s.length(); i++)
        {
            if (s[i] == '1')
            {
                has_one = true;
                break;
            }
        }
        if ((s.length() - 1) % 2 == 0 && has_one == false)
        {
            k--;
        }
        cout << k << endl;
    }
    return 0;
}