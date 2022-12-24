#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <limits>
#include <cmath>
#include <iomanip>
#include <functional>
#include <random>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;

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
vector<int> primes = prime_numbers(75);

int main()
{
    // cout << primes.size();
    // 整数の入力
    ll A,B;
    cin >> A >> B;
    // 最大公約数の数え上げ
    vector<vector<ll>> DP(2,vector<ll>(1ll<<21,0));
    // cout << "111" << endl;
    DP[0][0] = 1;
    for(ll i = A; i <= B;i++){
        // cout << i << endl;
        ll current_index = (i - A) % 2;
        ll next_index = (i + 1- A) % 2;
        ll current = 0;
        DP[next_index] = DP[current_index];
        for(ll j = 0;j < primes.size();j++){
            if (i % primes[j] == 0){
                current += 1ll<<j;
            }
        }
        for(ll j = 0;j < 1ll<<21;j++){
            if (!(j & current)){
                // cout << (j | current) << endl;
                DP[next_index][j | current] += DP[current_index][j];
            }
        }
    }
    ll ans = 0;
    // cout << "!!" << endl;
    for(ll i = 0;i < 1ll<<21;i++){
        ans += DP[(B-A+1)%2][i];
    }
    cout << ans << endl;
    return 0;
}