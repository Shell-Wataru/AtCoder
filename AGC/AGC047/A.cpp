#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;
ll BASE_NUM = 1000000007;

long long gcd(long long a, long long b)
{

    if (a == 0)
    {
        return b;
    }
    else if (b == 0)
    {
        return a;
    }

    if (a % b == 0)
    {
        return b;
    }
    else
    {
        return gcd(b, a % b);
    }
}

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

void decomposite(int N, map<int,int> & factors, vector<int> &primes,int p_index = 0){
    if (N == 1){
        return;
    }

    while (primes[p_index] * primes[p_index] <= N ) {
        if (N % primes[p_index] == 0) {
            factors[primes[p_index]] += 1;
            decomposite(N/primes[p_index],factors,primes,p_index);
            return;
        } else {
            p_index++;
        }
    }
    factors[N] += 1;
}

int main()
{
    ll N;
    cin >> N;
    vector<int> primes = prime_numbers(5000000);
    vector<pair<ll,ll>> bunbo_data;
    vector<vector<ll>> factors25(100,vector<ll>(100));
    ll center = 50;
    ll integer_count = 0;
    for(int i = 0;i < N;i++){
        string a;
        cin >> a;
        ll bunbo = 1;
        ll bunshi = 0;
        bool after_dot = false;
        for(int j = 0;j < a.size();j++){
            if (a[j] == '.'){
                after_dot = true;
                continue;
            }else if (after_dot){
                bunbo *= 10;
                bunshi *= 10;
                bunshi += a[j] - '0';
            }else{
                bunshi *= 10;
                bunshi += a[j] - '0';
            }
        }
        ll c = gcd(bunbo,bunshi);
        bunbo /= c;
        bunshi /= c;
        ll twos = 0;
        ll fives = 0;
        while(bunbo % 2 == 0){
            twos--;
            bunbo /= 2;
        }
        while(bunbo % 5 == 0){
            fives--;
            bunbo /= 5;
        }
        while(bunshi % 2 == 0){
            twos++;
            bunshi /= 2;
        }
        while(bunshi % 5 == 0){
            fives++;
            bunshi /= 5;
        }
        bunbo_data.push_back({twos,fives});
        factors25[twos+center][fives+center]++;
    }
    for(int i = factors25.size()-1;i >= 0;i--){
        for(int j = factors25[i].size()-1;j >= 0;j--){
            if (i+1 < factors25.size()){
                factors25[i][j] += factors25[i+1][j];
            }
            if (j+1 < factors25[i].size()){
                factors25[i][j] += factors25[i][j+1];
            }
            if (i+1 < factors25.size() && j+1 < factors25[i].size()){
                factors25[i][j] -= factors25[i+1][j+1];
            }
        }
    }
    ll ans = 0;
    for(auto b:bunbo_data){
        // cout << b.first << " " << b.second << endl;
        // cout << "!" <<factors25[center - b.first][center - b.second] << endl;
        if (b.second >= 0 && b.first >= 0){
            ans += factors25[center - b.first][center - b.second] - 1;
        }else{
            ans += factors25[center - b.first][center - b.second];
        }
    }
    cout << ans/2 << endl;
    return 0;
}