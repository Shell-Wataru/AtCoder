#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <numeric>
#include <unordered_set>
#include <climits>
#include <cmath>

using namespace std;
using ll = long long;

#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int solve()
{
    ll N;
    cin >> N;
    vector<vector<ll>> lines(N);
    for(int i = 0;i < N;i++){
        ll x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >>y2;
        if (atan2(y1,x1) < atan2(y2,x2)){
            if (atan2(y2,x2) - atan2(y1,x1) > M_PI ){
                lines[i] = {x2,y2,x1,y1};
            }else{
                lines[i] = {x1,y1,x2,y2};
            }

        }else{
            if (atan2(y1,x1) - atan2(y2,x2) > M_PI ){
                lines[i] = {x1,y1,x2,y2};
            }else{
                lines[i] = {x2,y2,x1,y1};
            }
        }
    }
    sort(lines.begin(),lines.end(),[](vector<ll> &l,vector<ll> &r){
        return atan2(l[1],l[0]) < atan2(r[1],r[0]);
    });
    ll ans = numeric_limits<ll>::max();
    double eps = 1e-10;
    for(int i = 0;i < N;i++){
        ll current = 1;
        priority_queue<double,vector<double>,greater<double>> q;
        double start_angle = atan2(lines[i][1],lines[i][0]);
        // cout << start_angle << endl;
        for(int j = 0;j < N;j++){
            auto l = lines[(i+j)%N];
            double start = atan2(l[1],l[0]);
            double end = atan2(l[3],l[2]);
            while (start + eps < start_angle){
                start += M_PI * 2;
            }

            while(end +eps < start_angle || end < start){
                end += M_PI * 2;
            }
            // cout << start << "~" << end << endl;
            if ((start - eps <=  start_angle && start_angle <= end + eps) || (start - eps <=  start_angle + M_PI * 2 && start_angle + M_PI * 2 <= end + eps)){
                continue;
            }
            if (q.empty()){
                q.push(end);
            }else if(q.top()+eps < start){
                current++;
                // cout << q.top() << endl;
                // cout << "==" << endl;
                q = priority_queue<double,vector<double>,greater<double>>();
                q.push(end);
            }else{
                q.push(end);
            }
        }
        if (!q.empty()){
            current++;
        }
        // cout << current << endl;
        ans = min(ans,current);
    }
    cout << ans << endl;
    return 0;
}

int main()
{
    // // 整数の入力
    //   ll t;
    //   cin >> t;
    //   for (size_t i = 0; i < t; i++)
    //   {
    solve();
    //   }
    //   cout << flush;
    return 0;
}
