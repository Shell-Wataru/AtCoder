#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <limits>
#include <cmath>
#include <iomanip>
#include <functional>
#include <random>
#include <set>
using namespace std;
using ll = long long;

ll BASE_NUM = 1000000007;

int main()
{
    // 整数の入力
    ll N;
    cin >> N;
    vector<pair<ll, ll>> SS(N);
    ll total = 0;
    for (int i = 0; i < N; i++)
    {
        string S;
        cin >> S;
        ll counter = 0;
        ll min_couner = 0;
        for (auto c : S)
        {
            if (c == '(')
            {
                counter++;
            }
            else
            {
                counter--;
            }
            min_couner = min(min_couner, counter);
        }
        SS[i] = {min_couner, counter};
    }
    sort(SS.begin(), SS.end(), greater<pair<ll, ll>>());
    ll current = 0;
    bool can_make = true;
    for (int i = 0; i < N; i++)
    {
        auto p = SS[i];
        if (current + p.first < 0)
        {
            can_make = 0;
        }
        current += p.second;
    }
    if (current == 0 && can_make)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}