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
    map<ll,ll> episodes;
    for(int i = 0;i< n;i++){
        episodes[shows[i]]++;
        if (i >= d){
            episodes[shows[i-d]]--;
            if (episodes[shows[i-d]] == 0){
                episodes.erase(shows[i-d]);
            }
        }

        if (i + 1 >= d){
            min_shows = min(min_shows,(ll)(episodes.size()));
        }
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
