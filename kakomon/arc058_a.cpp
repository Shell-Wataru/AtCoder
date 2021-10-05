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
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;

int main()
{
    // 整数の入力
    ll N, K;
    cin >> N >> K;
    vector<ll> D(K);
    for (int i = 0; i < K; i++)
    {
        cin >> D[i];
    }
    for (int i = N; i < 100 * N; i++)
    {
        string s = to_string(i);
        bool is_ok = true;
        for (auto &c : s)
        {
            for (auto &d : D)
            {
                if (c - '0' == d)
                {
                    is_ok = false;
                    break;
                }
            }
            if (!is_ok)
            {
                break;
            }
        }
        if (is_ok)
        {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}