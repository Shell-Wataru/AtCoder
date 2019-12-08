#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <map>

using namespace std;
using ll = long long;
ll BASE_NUM = 1000000007;
int solve(){
    ll n,k,d;
    vector<ll> shows;
    cin >> n >> k >> d;
    for(int i = 0;i<n;i++){
        ll a;
        cin >> a;
        shows.push_back(a);
    }
    ll min_shows = d+1;
    for(int i = 0;i< n-d+1;i++){
        set<ll> episodes;
        for(int j = 0;j<d;j++){
            episodes.insert(shows[i+j]);
        }
        min_shows = min(min_shows,(ll)(episodes.size()));
    }
    cout << min_shows << endl;
    return 0;
}
int main()
{
    ll t;
    cin >> t;
    for(int i=0;i<t;i++){
        solve();
    }
   return 0;
}
