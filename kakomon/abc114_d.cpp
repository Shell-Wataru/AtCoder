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
namespace mp = boost::multiprecision;

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
vector<int> primes = prime_numbers(100);
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


int main()
{
    // 整数の入力
    ll N;
    cin >> N;
    vector<ll> factor_counts(101,0);
    for(int i = 2;i<=N;i++){
        map<int,int> factors;
        decomposite(i,factors);
        for(auto p:factors){
            factor_counts[p.first] += p.second;
        }
    }
    ll ans = 0;
    // 75
    for(int i = 0;i<=100;i++){
        if (factor_counts[i] >= 74){
            ans++;
        }
    }

    // 25*3
    for(int i = 0;i<=100;i++){
        if (factor_counts[i] >= 24){
            for(int j = 0;j <= 100;j++){
                if (i != j && factor_counts[j] >= 2){
                    ans++;
                }
            }
        }
    }
    // 15*5
    for(int i = 0;i<=100;i++){
        if (factor_counts[i] >= 14){
            for(int j = 0;j <= 100;j++){
                if (i != j && factor_counts[j] >= 4){
                    ans++;
                }
            }
        }
    }

    // 5*5*3
    for(int i = 0;i<=100;i++){
        if (factor_counts[i] >= 4){
            for(int j = i+1;j <= 100;j++){
                if (factor_counts[j] >= 4){
                    for(int k = 0;k <= 100;k++){
                        if (k != i && k != j && factor_counts[k] >= 2){
                            ans++;
                        }
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}