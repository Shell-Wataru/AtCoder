#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <map>
#include <set>
using namespace std;
using ll = long long;

ll dfs(map<ll,ll> &remain_primes,ll last_choose,ll total, ll product){
    if (total < product){
        return 0;
    }else if (total == product){
        return total;
    }
    ll ans = 0;
    for(auto p: remain_primes){
        if (p.first > last_choose){
            for(int i = 1;i <= p.second;i++){
                ll next_total = total - p.first * i;
                ll next_product = product;
                for(int j = 0;j < i;j++){
                    next_product *= p.first;
                    if (next_product > next_total){
                        break;
                    }
                }
                if (next_product > next_total){
                    break;
                }
                remain_primes[p.first] -= i;
                ans = max(ans,dfs(remain_primes,p.first, next_total,next_product ));
                remain_primes[p.first] += i;
            }
        }
    }
    return ans;
}
string solve(){
    string ans = "";
    ll N;
    cin >> N;
    map<ll,ll> remain_primes;
    ll total = 0;
    for(int i = 0;i < N;i++){
        ll a,b;
        cin >> a >> b;
        remain_primes[a] += b;
        total += a*b;
    }
    return to_string(dfs(remain_primes,0,total,1));
}
int main()
{
    // 整数の入力
    ll T;
    cin >> T;

    for (int i = 1; i <= T; i++)
    {
        string ans = solve();
        cout << "Case #" << i  << ": "<< ans <<  endl;
    }

    return 0;
}