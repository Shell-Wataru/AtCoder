#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
#include <numeric>

using namespace std;
using ll = long long;

struct line
{
    ll x1, y1, x2, y2;
};

int solve()
{
    ll n,d;
    cin >> n >> d;
    ll max_sum = n * (n - 1)/2;
    ll min_sum = 0;
    ll remain_n = n - 1;
    for(int i = 1;i < 15;i++){
        ll this_depth = min(remain_n, (1LL<<i));
        min_sum += this_depth * i;
        remain_n -= this_depth;
    }
    cout << max_sum << " " << min_sum << endl;
    if (d < min_sum || d > max_sum){
        cout << "NO" << endl;
    }else{
        cout << "YES" << endl;
        vector<ll> answer(n,1);
        ll current = max_sum;
        while(current > d){
            ll connectable_min_depth;
            for(int i = 0;i < n;i++){
                if (answer[i+1] < 2 *  answer[i]){
                    connectable_min_depth = i;
                    break;
                }
            }

            ll unconnect_depth;
            for(int i = n - 1;i >= 0;i--){
                if (answer[i] > 0){
                    unconnect_depth = i;
                    break;
                }
            }
            cout << current << endl;
            cout << connectable_min_depth << " " << unconnect_depth << endl;
            ll diff = current - d;
            if (diff < unconnect_depth - connectable_min_depth -  1 ){
                answer[unconnect_depth]--;
                answer[unconnect_depth - diff]++;
                current = current - diff;
            }else{
                answer[unconnect_depth]--;
                answer[connectable_min_depth + 1]++;
                current = current - (unconnect_depth - connectable_min_depth - 1);
            }
        }
        for(int i = 0;i < n;i++){
            cout << "," <<answer[i];
        }
        cout << endl;
        vector<ll> answer2(n-1);
        ll index = 1;
        ll before_star
        for(int i = 0; i < n;i++){
            for(int j = 0;j < answer[i];j++){
                answer2[index] = 1;
            }
        }
    }
    return 0;
}
int main()
{
    ll t;
    cin >> t;
    for (size_t i = 0; i < t; i++)
    {
        solve();
    }
    return 0;
}