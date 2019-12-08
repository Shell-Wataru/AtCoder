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
ll BASE_NUM = 1000000007;

long long gcd(long long a, long long b){

    if (a== 0){
        return b;
    }else if (b == 0){
        return a;
    }

    if (a%b == 0){
        return b;
    }else{
        return gcd(b,a%b);
    }
}

bool possible(vector<ll> &total_costs,ll x,ll a,ll y,ll b,ll k,ll n,ll lcm_ab){
    ll xxyy = n/lcm_ab;
    ll xx = n/a - xxyy;
    ll yy = n/b - xxyy;
    ll gathered;
    if (x > y){
        gathered = (total_costs[xxyy] - total_costs[0]) * (x+y)
         + (total_costs[xx+xxyy] - total_costs[xxyy]) * x
         + (total_costs[xx+yy+xxyy] - total_costs[xx+xxyy]) * y;
    }else{
        gathered = (total_costs[xxyy] - total_costs[0]) * (x+y)
         + (total_costs[yy+xxyy] - total_costs[xxyy]) * y
         + (total_costs[xx+yy+xxyy] - total_costs[yy+xxyy]) * x;
    }
    // cout <<  "lcm:"<< lcm_ab << endl;
    // cout << "n:" << n << "xx:" << xx << "yy:" <<yy << "xxyy:" << xxyy  << " gather:"<< gathered << endl;
    return gathered >= k;
}

ll min_n(ll l,ll r,vector<ll> &total_costs,ll x,ll a,ll y,ll b,ll k,ll lcm_ab){
    if (l+1 == r){
        return r;
    }
    ll center = (l+r)/2;
    if (possible(total_costs,x,a,y,b,k,center,lcm_ab)){
        return min_n(l,center,total_costs,x,a,y,b,k,lcm_ab);
    }else{
        return min_n(center,r,total_costs,x,a,y,b,k,lcm_ab);
    }
}

int main()
{
    // 整数の入力
    ll q;
    cin >> q;
    for(int i = 0;i<q;i++){
        ll n;
        vector<ll> tickets;
        vector<ll> total_costs;
        cin >> n;
        for(int i = 0;i<n;i++){
            ll a;
            cin >> a;
            tickets.push_back(a);
        }
        sort(tickets.begin(),tickets.end(),greater<ll>());
        total_costs.push_back(0);
        for(int i = 0;i < n;i++){
            // cout << tickets[i] << endl;
            total_costs.push_back( tickets[i] + total_costs[i]);
        }
        ll x,a;
        cin >> x >> a;
        ll y,b;
        cin >> y >> b;
        ll k;
        cin >> k;

        ll lcm_ab = a*b/gcd(a,b);
        ll min_tickets = min_n(0,n+1,total_costs,x,a,y,b,k*100,lcm_ab);
        if (min_tickets == n+1){
            cout << -1 << endl;
        }else{
            cout << min_tickets << endl;
        }

    }
    return 0;
}
