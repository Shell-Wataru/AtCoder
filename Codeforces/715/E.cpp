#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <numeric>

using namespace std;
using ll = long long;
const ll BASE_NUM = 1000000007;


vector<int> prime_numbers(int n){
    if (n <= 1){
        return vector<int>(0);
    }
    vector<int> ans = {2};
    for(int i = 3;i <= n;i++){
        bool is_prime = true;
        for(int j = 0; ans[j] * ans[j] <= i;j++){
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

vector<int> primes = prime_numbers(10000);
void decomposite(int N, map<int,int> &factors,int p_index = 0){
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

int solve()
{
    ll n, k;
    scanf("%lld", &n);
    scanf("%lld", &k);
    set<set<ll>> segment_numbers;
    ll ans = 0;
    for(int i = 0;i < n;i++){
        ll a;
        scanf("%lld",&a);
        map<int,int> factors;
        decomposite(a,factors);
        set<ll> odd_factors;
        for(auto &p:factors){
            if (p.second % 2 == 1){
                odd_factors.insert(p.first);
            }
        }
        if (segment_numbers.find(odd_factors) != segment_numbers.end()){
            ans++;
            segment_numbers.clear();
            segment_numbers.insert(odd_factors);
        }else{
            segment_numbers.insert(odd_factors);
        }
    }
    ans++;
    cout << ans << endl;
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
