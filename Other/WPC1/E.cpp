#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <iomanip>
#include <cmath>
#include <set>
#include <numeric>

using namespace std;
using ll = long long;

int main()
{
    // 整数の入力
    ll N;
    cin >> N;
    vector<ll> A(N);
    for (size_t i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    for (int i = 0; i < N; i++)
    {
        A[i] -= i;
    }
    sort(A.begin(), A.end());
    ll median = A[N / 2];
    ll ans = 0;
    for (int i = 0; i < N; i++)
    {
        ans += abs(A[i] - median);
    }
    cout << ans << endl;
    return 0;
}