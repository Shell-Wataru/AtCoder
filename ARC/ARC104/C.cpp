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

namespace mp = boost::multiprecision;
using namespace std;

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

using ll = long long;

bool is_valid(ll current_from, ll current_to, vector<ll> &to, vector<ll> &from)
{
    // cout << "is_valid" << current_from << "~" << current_to << endl;
    if (current_to <= current_from )
    {
        return false;
    }
    for (int i = 0; i < current_to - current_from; i++)
    {
        if (to[current_from + i] == -2){
            return false;
        }
        if (from[current_to + i] == -2){
            return false;
        }
        if (to[current_from + i] != -1 && to[current_from + i] != current_to + i)
        {
            return false;
        }
        if (from[current_to + i] != -1 && from[current_to + i] != current_from + i)
        {
            return false;
        }
    }
    return true;
}

bool can_make(ll current_from, vector<ll> &to, vector<ll> &from)
{
    // cout << current_from << endl;
    if (current_from >= to.size())
    {
        return true;
    }
    ll current_to = to[current_from];
    if (current_to == -1)
    {
        bool can = false;
        for (int i = current_from + 1; i < to.size(); i++)
        {
            can = can || (is_valid(current_from, i, to, from) && can_make(i + 1, to, from));
        }
        return can;
    }
    else
    {
        return is_valid(current_from, current_to, to, from) && can_make(current_to + 1, to, from);
    }
}
const long long BASE_NUM = 1000000007;

int main()
{
    ll N;
    cin >> N;
    vector<pair<ll, ll>> A(N);
    vector<ll> to(2 * N, -1);
    vector<ll> from(2 * N, -1);
    vector<bool> used(2 * N, false);
    bool valid_data = true;
    for (size_t i = 0; i < N; i++)
    {
        cin >> A[i].first >> A[i].second;
        if (A[i].first != -1)
            A[i].first--;
        if (A[i].second != -1)
            A[i].second--;

        if (A[i].first != -1 ){
            if (used[A[i].first]){
                cout << "No" << endl;
                return 0;
            }
            used[A[i].first] = true;
            to[A[i].first] = A[i].second;
            from[A[i].first] = -2;
        }
        if (A[i].second != -1 && to[A[i].second] == -1){
            if (used[A[i].second]){
                cout << "No" << endl;
                return 0;
            }
            used[A[i].second] = true;
            from[A[i].second] = A[i].first;
            to[A[i].second] = -2;
        }
    }
    // for(int i = 0;i< 2* N;i++){
    //     cout << from[i] << endl;
    // }
    if (can_make(0, to, from))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}