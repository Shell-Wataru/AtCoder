#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <map>
#include <bitset>
#include <numeric>
using namespace std;
using ll = long long;
ll BASE_NUM = 1000000007;

int solve()
{
    ll n;
    scanf("%lld", &n);
    vector<ll> p(n);
    vector<ll> goods,bads;
    map<ll,ll> good_numbers,bad_numbers;
    for(int i = 0;i < n;i++){
        scanf("%lld",&p[i]);
    }
    string S;
    cin >> S;
    ll bad_count = 0;
    for(int i = 0;i < n;i++){
        if (S[i] == '0'){
            bad_count++;
            bads.push_back(p[i]);
        }else{
            goods.push_back(p[i]);
        }
    }
    sort(goods.begin(),goods.end());
    sort(bads.begin(),bads.end());
    for(int i = 0;i < bads.size();i++){
        bad_numbers[bads[i]] = i+1;
    }
    for(int i = 0;i < goods.size();i++){
        good_numbers[goods[i]] = bad_count+i+1;
    }
    for(int i = 0;i < n;i++){
        if (S[i] =='1'){
            cout << good_numbers[p[i]] << " ";
        }else{
            cout << bad_numbers[p[i]] << " ";
        }
    }
    cout << "\n";
    return 0;
}
int main()
{
    ll t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        solve();
    }
    cout << flush;
    return 0;
}
