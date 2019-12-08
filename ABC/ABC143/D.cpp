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


int main()
{
    // 整数の入力
    ll N;
    vector<ll> lines;
    cin >> N;
    for(int i = 0;i<N;i++){
        ll a;
        cin >> a;
        lines.push_back(a);
    }
    lines.push_back(10000);

    sort(lines.begin(),lines.end());
    ll total = 0;
    for(int i = 0;i<N;i++){
        for(int j = i+1;j<N;j++){
            ll sum_ab = lines[i] + lines[j];
            ll min_ba = lines[j] - lines[i];
            auto from = upper_bound(lines.begin() + j + 1,lines.end(),min_ba);
            auto to = lower_bound(lines.begin() + j + 1,lines.end(),sum_ab);
            // cout << "a:" << lines[i] << "b:" << lines[j] << "from:" << *from << " to:" << *to << endl;
            // cout << to - from << endl;
            if (to - from > 0){
                total += to - from;
            }
            // if (a < N){
            //     total += N - a;
            //     if (lines[a] <= lines[i]){
            //         total--;
            //     }

            //     if (lines[a] <= lines[j]){
            //         total--;
            //     }
            // }
        }
    }

    cout << total << endl;

    return 0;
}