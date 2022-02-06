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
    for(int i = 0;i < N;i++){
        cin >> a[i];
    }

    return 0;
}