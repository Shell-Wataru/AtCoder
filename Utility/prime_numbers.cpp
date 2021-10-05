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
vector<int> primes = prime_numbers(3400);
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


int main(){
    cout << primes.size() << endl;
    map<int,int> factors;
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