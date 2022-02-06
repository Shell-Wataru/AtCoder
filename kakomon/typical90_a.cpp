#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <numeric>
#include <cmath>
#include <climits>
using namespace std;
using ll = long long;

int answer(ll l, ll r, vector<ll> &A, ll K)
{
    if (l + 1 == r)
    {
        return l;
    }
    ll center = (l + r) / 2;
    ll last = 0;
    ll count = 0;
    for (auto a : A)
    {
        if (a - last >= center)
        {
            count++;
            last = a;
        }
    }
    if (count >= K+1)
    {
        return answer(center, r, A, K);
    }
    else
    {
        return answer(l, center, A, K);
    }
}
int solve()
{
    ll N, L, K;
    cin >> N >> L >> K;
    vector<ll> A(N + 1, 0);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    A[N] = L;
    cout << answer(1, L+1, A, K) << endl;
    return 0;
}

int main()
{
    // // 整数の入力
    //   ll t;
    //   cin >> t;
    //   for (size_t i = 0; i < t; i++)
    //   {
    solve();
    //   }
    //   cout << flush;
    return 0;
}
