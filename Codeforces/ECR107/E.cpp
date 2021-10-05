#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>

using namespace std;
using ll = long long;

const long long BASE_NUM = 998244353;

int solve()
{

    ll n1,n2,n3,n4;
    cin >> n1 >> n2 >> n3 >> n4;
    vector<ll> a(n1);
    vector<ll> b(n2);
    vector<ll> c(n3);
    vector<ll> d(n4);
    for (size_t i = 0; i < n1; i++)
    {
        scanf("%lld",&a[i]);
    }
    for (size_t i = 0; i < n2; i++)
    {
        scanf("%lld",&b[i]);
    }
    for (size_t i = 0; i < n3; i++)
    {
        scanf("%lld",&c[i]);
    }
    for (size_t i = 0; i < n4; i++)
    {
        scanf("%lld",&d[i]);
    }
    ll m1;
    scanf("%lld",&m1);
    set<pair<ll,ll>> bad_pairs1;
    for (size_t i = 0; i < m1; i++)
    {
        ll x,y;
        scanf("%lld",&x);
        scanf("%lld",&y);
        x--;
        y--;
        bad_pairs1.emplace(x,y);
    }

    ll m2;
    scanf("%lld",&m2);
    set<pair<ll,ll>> bad_pairs2;
    for (size_t i = 0; i < m2; i++)
    {
        ll x,y;
        scanf("%lld",&x);
        scanf("%lld",&y);
        x--;
        y--;
        bad_pairs2.emplace(x,y);
    }

    ll m3;
    scanf("%lld",&m3);
    set<pair<ll,ll>> bad_pairs3;
    for (size_t i = 0; i < m3; i++)
    {
        ll x,y;
        scanf("%lld",&x);
        scanf("%lld",&y);
        x--;
        y--;
        bad_pairs3.emplace(x,y);
    }
    vector<pair<ll,ll>> first_candidates(n1);
    for(int i = 0;i < n1;i++){
        first_candidates[i] = {a[i],i};
    }
    sort(first_candidates.begin(),first_candidates.end());
    vector<pair<ll,ll>> second_candidates = next_candidats(first_candidates,bad_pairs1,b);
    vector<pair<ll,ll>> third_candidates = next_candidats(second_candidates,bad_pairs2,c);
    vector<pair<ll,ll>> forth_candidates = next_candidats(third_candidates,bad_pairs3,d);
    if (forth_candidates[0].first >= numeric_limits<ll>::max()/2 ){
        cout << -1 << endl;
    }else{
        cout << forth_candidates[0].first << endl;
    }
    return 0;
}
int main()
{
    // int t;
    // cin >> t;
    // for (size_t i = 0; i < t; i++)
    // {
    solve();
    // }
    return 0;
}