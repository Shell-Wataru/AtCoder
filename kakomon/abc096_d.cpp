#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <iomanip>
#include <cmath>
#include <set>
#include <numeric>
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
vector<int> primes = prime_numbers(55555);

int main()
{
    // 整数の入力
    ll N;
    cin >> N;
    vector<vector<ll>> remains(5,vector<ll>());
    for(auto p:primes){
        remains[p%5].push_back(p);
    }
    ll max_count = 0;
    ll max_remain = -1;
    for(int i = 0;i <5;i++){
        if (remains[i].size() > max_count){
            max_count = remains[i].size();
            max_remain = i;
        }
    }
    for(int i = 0;i < N;i++){
        if(i != 0){
            cout << " ";
        }
        cout << remains[max_remain][i];
    }
    cout << endl;
    return 0;
}