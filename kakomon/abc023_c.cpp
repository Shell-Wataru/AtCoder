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
#include <stack>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;

int main()
{
    // 整数の入力
    ll R,C,K,N;
    cin >> R >> C >> K >> N;
    vector<vector<ll>> G(R);
    vector<ll> column_sum(C,0);
    vector<ll> row_sum(R,0);
    for(int i = 0;i < N;i++){
        ll r,c;
        cin >> r >> c;
        r--;c--;
        G[r].emplace_back(c);
        column_sum[c]++;
        row_sum[r]++;
    }
    vector<ll> column_sum_count(R+1,0);
    for(auto c:column_sum){
        column_sum_count[c]++;
    }
    // cout << "!!" << endl;
    ll total = 0;
    for(int i = 0;i < R;i++){
        ll rs = row_sum[i];
        ll cs = K - rs;
        // cout << rs << " " << cs << endl;
        if (0 <= cs && cs <= R){
            total += column_sum_count[cs];
        }
        for(auto c:G[i]){
            if (column_sum[c] == cs){
                total--;
            }
            if (column_sum[c] == cs + 1){
                total++;
            }
        }
    }
    cout << total << endl;
    return 0;
}