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

int main()
{
    // 整数の入力
    ll N;
    cin >> N;
    vector<ll> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    vector<ll> DP1(N, numeric_limits<ll>::max() / 2);
    vector<ll> DP2(N, numeric_limits<ll>::max() / 2);
    DP1[0] = A[0];
    DP1[1] = A[0];
    for (int i = 2; i < N; i++)
    {
        DP1[i] = min(DP1[i], DP1[i - 1] + A[i - 1]);
        DP1[i] = min(DP1[i], DP1[i - 2] + A[i - 1]);
    }
    DP1[N-1] = min(DP1[N-1],DP1[N-2] + A[N-1]);
    DP2[0] = A[N - 1];
    DP2[N - 1] = A[N - 1];
    for (int i = 1; i < N - 1; i++)
    {
        DP2[i] = min(DP2[i], DP2[i - 1] + A[i - 1]);
        DP2[i] = min(DP2[i], DP2[(i - 2 + N) % N] + A[i - 1]);
    }
    DP2[N-2] = min(DP2[N-2],DP2[(N+N-3) % N] + A[N-2]);
    cout << min(DP1[N - 1], DP2[N - 2]) << endl;
    return 0;
}