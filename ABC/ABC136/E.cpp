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
#include <set>
using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;
ll BASE_NUM = 1000000007;

int distance(vector<ll> &A, ll base)
{
    // cout << base << endl;
    vector<ll> amari;
    ll d = 0;
    ll amari_total = 0;
    for (auto a : A)
    {
        amari_total += a % base;
        amari.push_back(a % base);
    }
    // cout << "amari_total" << amari_total << endl;
    sort(amari.begin(), amari.end(), greater<ll>());
    ll nokori = amari_total;
    if (nokori != 0)
    {
        for (int i = 0; i < amari.size(); i++)
        {
            d += base - amari[i];
            nokori = nokori - amari[i];

            if (d == nokori)
            {
                break;
            }
        }
    }

    return d;
}

int main()
{
    // 整数の入力
    ll N, K, total, ans;
    vector<ll> A;
    total = 0;
    ans = 0;
    cin >> N >> K;
    for (int i = 1; i <= N; i++)
    {
        ll a;
        cin >> a;
        total += a;
        A.push_back(a);
    }
    // cout << total << endl;
    for (ll i = 1; i * i <= total; i++)
    {
        if (total % i == 0)
        {
            ll d1 = distance(A, i);
            if (d1 <= K)
            {
                ans = max(ans, i);
            }
            // cout << i << " " << d1 << endl;

            ll d2 = distance(A, total / i);
            if (d2 <= K)
            {
                ans = max(ans, total / i);
            }

            // cout << total / i << " " << d2 << endl;
        }
    }
    cout << ans << endl;
    return 0;
}