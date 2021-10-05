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
vector<int> primes = prime_numbers(100000);

int main(){
    ll Q;
    cin >> Q;
    vector<ll> counts(100001,0);
    vector<ll> is_prime(100001);
    for(auto p:primes){
        is_prime[p] = true;
    }
    for(int i = 1;i<=100000;i++){
        if(i % 2 == 1 && is_prime[i] && is_prime[(i+1)/2]){
            counts[i] = counts[i-1] + 1;
        }else{
            counts[i] = counts[i-1];
        }
    }

    for(int i = 0;i < Q;i++){
        ll l,r;
        cin >> l >> r;
        l--;
        cout << counts[r] - counts[l] << endl;
    }
    return 0;

}