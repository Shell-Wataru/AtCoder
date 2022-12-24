#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <map>
#include <set>
using namespace std;
using ll = long long;

string solve(){
    ll N,K;
    cin >> N >> K;
    map<ll,ll> counts;
    for(int i = 0;i < N;i++){
        ll s;
        cin >> s;
        counts[s]++;
    }
    if (N > 2*K){
        return "NO";
    }else{
        for(auto p:counts){
            if (p.second > 2){
                return "NO";
            }
        }
        return "YES";
    }
}
int main()
{
    // 整数の入力
    ll T;
    cin >> T;
    // cerr << T << endl;
    for (int i = 1; i <= T; i++)
    {
        cout << "Case #" << i << ": " << solve() << endl;
    }
    return 0;
}