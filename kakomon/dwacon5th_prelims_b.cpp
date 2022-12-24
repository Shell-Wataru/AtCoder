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

int main()
{
    // 整数の入力
    ll N,K;
    cin >> N >> K;
    vector<ll> ruisekiWa(N+1);
    for (size_t i = 0; i < N; i++)
    {
        cin >> ruisekiWa[i+1];
    }
    for(int i =0 ;i < N;i++){
        ruisekiWa[i+1] += ruisekiWa[i];
    }
    vector<ll> numbers;
    for(int i =0 ;i < N;i++){
        for(int j = i+1;j<=N;j++)
        numbers.push_back(ruisekiWa[j] - ruisekiWa[i]);
    }
    ll ans = 0;
    for(int i = 60;i >= 0;i--){
        vector<ll> new_numbers;
        for(auto n:numbers){
            if (n & 1ll<<i){
                new_numbers.push_back(n);
            }
        }
        if (new_numbers.size() >= K){
            ans += 1ll<<i;
            numbers = new_numbers;
        }
    }
    cout << ans << endl;
    return 0;
}