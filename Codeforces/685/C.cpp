#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
#include <numeric>

using namespace std;
using ll = long long;
const ll BASE_NUM = 1000000007;

int solve()
{
    ll n, k;
    cin >> n >> k;
    string a,b;
    cin >> a >> b;
    map<ll,ll> a_counts,b_counts;
    for(auto c: a){
        a_counts[c-'a'] += 1;
    }
    for(auto c: b){
        b_counts[c-'a'] += 1;
    }

    ll can = true;
    for (int i = 0; i < 26; i++)
    {
        // cout << "i:" << i << " " << a_counts[i] << "," << b_counts[i] << endl;
        if (a_counts[i] < b_counts[i] ){
            can = false;
            break;
        }else if ((a_counts[i] - b_counts[i]) % k != 0){
            can = false;
            break;
        }else{
            a_counts[i+1] += a_counts[i] - b_counts[i];
        }
    }

    if (can ){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

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
    cout << flush;
    return 0;
}
