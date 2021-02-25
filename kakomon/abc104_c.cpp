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

int main()
{
    // 整数の入力
    ll D,G;
    cin >> D >> G;
    vector<pair<ll,ll>> P(D);
    for (size_t i = 0; i < D; i++)
    {
        cin >> P[i].first;
        cin >> P[i].second;
    }
    ll ans = numeric_limits<ll>::max();
    for(int i = 0; i < 1<<D;i++){
        ll points = 0;
        ll solved = 0;
        for(int j = 0;j < D;j++){
            if (i & 1<<j){
                points += (j+1)*100 * P[j].first + P[j].second;
                solved += P[j].first;
            }
        }
        // cout << points << endl;
        if (points >= G){
            ans = min(ans,solved);
        }else{
            ll remain = G - points;
            for(int j = D-1;j>=0;j--){
                if (!(i & 1<<j)){
                    if (remain > (j+1)*100 *(P[j].first - 1)){
                        remain = remain - (j+1)*100 *(P[j].first - 1);
                        solved += (P[j].first - 1);
                    }else{
                        solved += (remain + (j+1)*100 - 1)/((j+1)*100);
                        remain = 0;
                    }
                }
            }
            if (remain == 0){
                ans = min(ans,solved);
            }
        }
    }
    cout << ans << endl;
    return 0;
}