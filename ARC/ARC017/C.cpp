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

ll BASE_NUM = 1000000007;

int main()
{
    // 整数の入力
    ll N,X;
    cin >> N >> X;
    vector<ll> W;
    map<ll,ll> first_counts;
    map<ll,ll> second_counts;
    for(int i = 0;i < N;i++){
        ll w;
        cin >> w;
        W.push_back(w);
    }

    ll first_size = N/2;
    for(int i = 0;i < (1<<first_size) ;i++){
        ll total = 0;
        for(int j = 0;j < first_size;j++){
            if (i & (1<<j)){
                total += W[j];
            }
        }
        first_counts[total]++;
    }

    ll second_size = N - N/2;
    for(int i = 0;i < (1<<second_size) ;i++){
        ll total = 0;
        for(int j = 0;j < second_size;j++){
            if (i & (1<<j)){
                total += W[first_size + j];
            }
        }
        second_counts[total]++;
    }

    ll patterns = 0;
    for(auto p:first_counts){
        patterns += p.second * second_counts[X - p.first];
    }
    cout << patterns << endl;
    return 0;
}