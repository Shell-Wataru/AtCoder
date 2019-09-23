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

int main()
{
    // 整数の入力
    long long N,M;
    map<ll,ll,greater<ll>> take_times;
    cin >> N >> M;
    for(int i = 0;i< N;i++){
        if (i!=0){
            cout << " ";
        }
        ll t;
        cin >> t;

        M -= t;
        ll u = 0;
        ll missed_total = 0;
        if (M >= 0){
            cout << 0;
        }else{
            for(auto p:take_times) {
                if (M + missed_total + p.first*p.second >= 0){
                    cout << u - (M + missed_total - p.first + 1)/p.first;
                    break;
                }else{
                    missed_total += p.first*p.second;
                    u += p.second;
                }
            }
        }
        take_times[t]++;
    }
    cout << endl;
    return 0;
}