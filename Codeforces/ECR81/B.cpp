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

int solve(){
    ll n,x;
    cin >> n >> x;
    string s;
    map<ll,ll> balance_counts;
    ll total_balance = 0;
    cin >> s;
    balance_counts[0] = 1;
    for(int i = 0;i < n;i++){
        if (s[i] == '0'){
            total_balance++;
        }else{
            total_balance--;
        }
        if (i < n - 1){
            balance_counts[total_balance] = balance_counts[total_balance] + 1;
        }
    }
    if (total_balance == 0){
        if (balance_counts[x] != 0){
            cout << -1 << endl;
        }else{
            cout << balance_counts[x] << endl;
        }
    }else{
        ll value = 0;
        for(auto p:balance_counts){
            if ((x - p.first)/ total_balance >= 0 && (x - p.first) % total_balance == 0){
                value += p.second;
            }
        }
        cout << value << endl;
    }
    return 0;
}
int main()
{
    // 整数の入力
    long long T;
    cin >> T;
    for(int i = 0;i< T;i++){
        solve();
    }

    return 0;
}