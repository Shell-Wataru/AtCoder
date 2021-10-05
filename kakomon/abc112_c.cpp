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

int height(vector<vector<ll>> &data,ll x, ll y){
    ll h = -1;
    ll lte_h = numeric_limits<ll>::max();
    for (auto d:data)
    {
        if (d[2] > 0){
            ll h_from_d = abs(d[0] - x) + abs(d[1] - y) + d[2];
            if (h == -1){
                h = h_from_d;
            }else if (h != h_from_d){
                return -1;
            }
        }else{
            lte_h = min(lte_h,abs(d[0] - x) + abs(d[1] - y));
        }
    }
    if (h <= lte_h){
        return h;
    }else{
        return -1;
    }
}
int main()
{
    // 整数の入力
    ll N;
    cin >> N;
    vector<vector<ll>> data(N,vector<ll>(3));
    for(int i =0;i < N;i++){
        cin >> data[i][0];
        cin >> data[i][1];
        cin >> data[i][2];
    }
    for(int i =0;i <= 100;i++){
        for(int j = 0;j <= 100;j++){
            ll h = height(data,i,j);
            if (h != -1){
                cout << i << " " << j << " " << h << endl;
                return 0;
            }
        }
    }
    return 0;
}