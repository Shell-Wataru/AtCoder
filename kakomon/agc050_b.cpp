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

template <typename T>
struct V : vector<T>
{
    using vector<T>::vector;
};
V()->V<int>;
V(size_t)->V<int>;
template <typename T>
V(size_t, T) -> V<T>;
template <typename T>
vector<T> make_vec(size_t n, T a) { return vector<T>(n, a); }
template <typename... Ts>
auto make_vec(size_t n, Ts... ts) { return vector<decltype(make_vec(ts...))>(n, make_vec(ts...)); }
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v)
{
    for (auto &e : v)
        os << e << ' ';
    return os;
}
struct fast_ios
{
    fast_ios()
    {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(20);
    };
} fast_ios_;

int main()
{
    // 整数の入力
    ll N;
    cin >> N;
    vector<ll> a(N);
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }
    vector<ll> cumSum(N + 1, 0);
    for (int i = 0; i < N; i++)
    {
        cumSum[i + 1] = cumSum[i] + a[i];
    }
    vector<vector<ll>> DPN(N, vector<ll>(N + 1, 0));
    vector<vector<ll>> DPR(N, vector<ll>(N + 1, 0));
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; i + j <= N; j++)
        {
            DPR[j][j+i] = cumSum[j+i] - cumSum[j];
            for (int k = 1; k < i; k++)
            {
                // N
                DPN[j][j + i] = max(DPN[j][j + i], DPN[j][j + k] + DPN[j + k][j + i]);
                // R
                DPR[j][j + i] = max(DPR[j][j + i], DPR[j][j + k] + DPR[j + k][j + i]);
            }
            if (i % 3 == 0)
            {
                ll m = max(DPN[j][j + i],DPR[j][j + i]);
                DPN[j][j + i] = m;
                DPR[j][j + i] = m;
            }
        }
    }
    cout << DPN[0][N] << endl;
    return 0;
}