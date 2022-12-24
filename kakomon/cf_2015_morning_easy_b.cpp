#define _USE_MATH_DEFINES
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

using namespace std;
using ll = long long;

int main()
{
    ll N;
    cin >> N;
    string S;
    cin >> S;
    if (N % 2 == 1)
    {
        cout << -1 << endl;
    }
    else
    {
        ll ans = 0;
        for (int i = 0; i < N / 2; i++)
        {
            if (S[i] != S[i + N / 2])
            {
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}