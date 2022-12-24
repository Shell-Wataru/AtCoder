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

vector<ll> prime_numbers(ll n){
    if (n <= 1){
        return vector<ll>(0);
    }
    vector<ll> ans = {2};
    for(ll i = 3;i <= n;i++){
        bool is_prime = true;
        for(ll j = 0; ans[j] * ans[j] <= i;j++){
            if (i % ans[j] == 0){
                is_prime = false;
                break;
            }
        }
        if (is_prime){
            ans.push_back(i);
        }
    }
    return ans;
}
vector<ll> primes = prime_numbers(32000);
void decomposite(ll N, map<ll,ll> &factors,ll p_index = 0){
    if (N == 1){
        return;
    }

    while (primes[p_index] * primes[p_index] <= N ) {
        if (N % primes[p_index] == 0) {
            factors[primes[p_index]] += 1;
            decomposite(N/primes[p_index],factors,p_index);
            return;
        } else {
            p_index++;
        }
    }
    factors[N] += 1;
}


ll main(){
    cout << primes.size() << endl;
    map<ll,ll> factors;
    decomposite(998244353 - 1,factors);
    for(auto f:factors){
        cout << f.first << " " << f.second << endl;
    }
    // for(auto p: primes){
    //     cout << p << "\n";
    // }
    // cout << flush;
    return 0;
}