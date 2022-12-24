#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <iomanip>
#include <cmath>
#include <set>
#include <numeric>
#include <unordered_map>
using namespace std;
using ll = long long;

int main()
{
    // 整数の入力
    string S;
    cin >> S;
    string target = "AKIHABARA";
    ll current = 0;
    for (int i = 0; i < target.size(); i++)
    {
        if (current < S.size() && target[i] == S[current])
        {
            current++;
        }
        else if (target[i] == 'A')
        {
        }
        else
        {
            cout << "NO" << endl;
            return 0;
        }
    }
    if (current == S.size())
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}
