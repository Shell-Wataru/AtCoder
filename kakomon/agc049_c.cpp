#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <numeric>
#include <unordered_map>
using namespace std;
using ll = long long;

int solve()
{
    ll N;
    cin >> N;
    vector<vector<ll>> AB(N,{0,0});
    for (int i = 0; i < N; i++)
    {
        cin >> AB[i][0];
    }
    for (int i = 0; i < N; i++)
    {
        cin >> AB[i][1];
    }
    ll ans = numeric_limits<ll>::max();
    ll changes = 0;
    ll min_index = numeric_limits<ll>::max();
    sort(AB.rbegin(),AB.rend());
    for(int i = 0;i < N;i++){
        ll index = AB[i][0] - AB[i][1];
        if (index <= 0){
            ans = min(ans,max(1-index-changes,0ll)+changes);
            if (AB[i][0] < min_index ){
                changes++;
            }
        }else{
            min_index = min(min_index,index);
        }
    }
    cout << min(ans,changes) << endl;
    return 0;
}

int main()
{
    // int t;
    // cin >> t;
    // for (size_t i = 0; i < t; i++)
    // {
    solve();
    // }
    cout << flush;
    return 0;
}