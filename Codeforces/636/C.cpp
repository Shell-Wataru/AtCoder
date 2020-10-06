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
ll BASE_NUM = 1000000007;

int set_childrens(ll from, ll parent, ll depth, vector<vector<ll>> &G, vector<ll> &children, vector<ll> &depths)
{
    depths[from] =depth;
    ll sum = 1;
    for (auto to : G[from])
    {
        if (to != parent)
        {
            sum += set_childrens(to, from, depth + 1, G, children, depths);
        }
    }
    children[from] = sum;
    return sum;
}

int solve()
{
    ll n, k;
    cin >> n;
    vector<ll> a;
    for(int i = 0;i< n;i++){
        ll c;
        scanf("%lld", &c);
        if (i == 0){
            a.push_back(c);
        }else if (a.back() > 0 && c > 0 && c > a.back()){
            a.back() = c;
        }else if (a.back() < 0 && c < 0 && c > a.back()){
            a.back() = c;
        }else if (a.back() * c < 0){
            a.push_back(c);
        }
    }
    ll total = 0;
    for(auto c:a){
        // cout << c << endl;
        total += c;
    }
    cout << total << endl;
    // cout << "===" << endl;
    return 0;
}
int main()
{
    // 整数の入力
    ll t;
    cin >> t;
    for (size_t i = 0; i < t; i++)
    {
    solve();
    }
    return 0;
}
