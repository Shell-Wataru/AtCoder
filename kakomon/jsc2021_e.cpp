#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
#include <climits>
#include <numeric>
using namespace std;
using ll = long long;

int solve()
{
    ll K;
    string S;
    cin >> K >> S;
    ll n = S.size();
    ll base_length = n>>K;
    // cout << n << endl;
    // cout << base_length << endl;
    // cout << (n >> (K -1)) << endl;
    if ( (n >> max(K -1,0ll)) == 0 || base_length == 1){
        cout << "impossible" << endl;
        return 0;
    }
    vector<vector<ll>> counts(K+1,vector<ll>(26,0));
    vector<vector<ll>> base_counts(base_length,vector<ll>(26,0));
    ll i = 0;
    ll block_index = 0;
    while(i < n){
        if (block_index % 2 == 0){
            if (block_index % 4 == 0){
                for(int j = 0;j < base_length;j++){
                    base_counts[j][S[i+j]-'a']++;
                }
            }else{
                for(int j = 0;j < base_length;j++){
                    base_counts[base_length-j-1][S[i+j]-'a']++;
                }
            }
            block_index++;
            i += base_length;
        }else{
            ll k = __builtin_ffsll(block_index+1)-1;
            // cout << k << endl;
            if (n & 1ll<<(K-k)){
                counts[k][S[i]-'a']++;
                block_index++;
                i++;
            }else{
                block_index++;
            }
        }
    }
    ll ans = 0;
    for(int i = 0;i <= K;i++){
        ll total = 0;
        ll maximum  = 0;
        for(auto c:counts[i]){
            total += c;
            maximum = max(maximum,c);
        }
        ans += total - maximum;
    }
    string base_string;
    bool is_palindrome = true;
    for(int i = 0;i < base_length;i++){
        ll total = 0;
        ll maximum = -1;
        ll maximums_index = -1;
        for(int j = 0;j < 26;j++){
            total += base_counts[i][j];
            if (base_counts[i][j] > maximum){
                maximum = base_counts[i][j];
                maximums_index = j;
            }else if (base_counts[i][j] == maximum){
                maximums_index = -1;
            }
        }
        ans += total - maximum;
        if (maximums_index == -1 && (base_length != 2*i+1)){
            is_palindrome = false;
        }else{
            base_string += 'a' + maximums_index;
        }
    }
    string rev_base_string(base_string.rbegin(),base_string.rend());
    if (is_palindrome && rev_base_string == base_string && base_string.size() > 0){
        ll min_diff = numeric_limits<ll>::max();
        for(int i = 0;i < base_length;i++){
            if (base_length == 2*i+1){
                continue;
            }
            ll total = 0;
            sort(base_counts[i].rbegin(),base_counts[i].rend());
            min_diff = min(min_diff,base_counts[i][0]-base_counts[i][1]);
        }
        cout << ans + min_diff << endl;
    }else{
        cout << ans << endl;
    }

    return 0;
}
int main()
{
    // 整数の入力
    // ll t;
    // cin >> t;
    // for (size_t i = 0; i < t; i++)
    // {
    solve();
    // }
    cout << flush;
    return 0;
}
