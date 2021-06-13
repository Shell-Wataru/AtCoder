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
    ll N,M;
    cin >> N >> M;
    vector<ll> A(N);
    for (size_t i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    vector<pair<ll,ll>> bonuses;
    for (size_t i = 0; i < M; i++)
    {
        ll bonus_member = 0;
        ll B,C;
        cin >> B >> C;
        for (size_t j = 0; j < C; j++)
        {
            ll I;
            cin >> I;
            bonus_member |= 1ll<<(I-1);
        }
        bonuses.emplace_back( bonus_member,B);
    }
    ll ans = 0;
    for(ll i = 0;i < (1ll<<N);i++){
        if (__builtin_popcount(i) != 9){
            continue;
        }
        ll value = 0;
        for(ll j = 0;j < N;j++){
            if (i & 1ll<<j){
                value += A[j];
            }
        }
        for(auto &p:bonuses){
            if (__builtin_popcount(p.first & i) >= 3){
                value += p.second;
            }
        }
        ans = max(ans,value);
    }
    cout << ans << endl;
   return 0;
}