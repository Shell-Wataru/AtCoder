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
#include <cmath>
#include <climits>
using namespace std;
using ll = long long;

int solve()
{
    ll N;
    cin >> N;
    vector<pair<ll,ll>> P(N);
    for(int i = 0;i < N;i++){
        cin >> P[i].first >> P[i].second;
    }
    double eps = 1e-10;
    ll donkaku = 0;
    ll tyokkaku = 0;
    ll other = 0;
    for(int i = 0;i < N;i++){
        vector<double> angles;
        for(int j = 0;j < N;j++){
            if (i != j){
                angles.push_back(atan2(P[j].second - P[i].second,P[j].first - P[i].first));
            }
        }
        sort(angles.begin(),angles.end());
        vector<double> angles2(angles);
        for(auto a:angles2){
            angles.push_back(M_PI*2 +a);
        }
        ll from_index = 0;
        ll to_index = 0;
        for(int j = 0;j < N-1;j++){
            while(angles[from_index] - angles[j] < M_PI/2 - eps){
                from_index++;
            }
            while(angles[to_index] - angles[j] < M_PI - eps){
                to_index++;
            }
            if (M_PI/2 - eps <  angles[from_index] - angles[j] &&  angles[from_index] - angles[j] < M_PI/2+eps){
                tyokkaku++;
                donkaku += to_index - from_index - 1;
            }else{
                donkaku += to_index - from_index;
            }

        }
    }
    cout << N*(N-1)*(N-2)/6 - donkaku - tyokkaku << " " << tyokkaku << " " << donkaku << endl;
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
