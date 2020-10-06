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

ll value(ll h,ll A,ll R,ll M, vector<ll> &H){
    ll adds = 0;
    ll removes = 0;
    ll moves = 0;
    for(int i = 0;i < H.size();i++){
        if (h > H[i]){
            adds += h - H[i];
        }else{
            removes += H[i] - h;
        }
    }
    if (A + R >= M){
        moves = min(adds,removes);
        adds -= moves;
        removes -= moves;
    }
    return adds * A + removes * R + moves * M;
}
ll three_search(ll l,ll r,ll A,ll R,ll M, vector<ll> &H){
    if (l + 2 == r){
        ll t1 = (2*l + r)/3;
        ll t2 = (l + 2 *r)/3;
        ll t1_value = value(t1,A,R,M,H);
        ll t2_value = value(t2,A,R,M,H);
        if(t1_value <= t2_value){
            return t1;
        }else{
            return t2;
        }
    }else{
        ll t1 = (2*l + r)/3;
        ll t2 = (l + 2 *r)/3;
        ll t1_value = value(t1,A,R,M,H);
        ll t2_value = value(t2,A,R,M,H);
        // cout << l << " " << t1 <<" "<< t2 << " " << r << endl;
        // cout << t1_value << "," << t2_value << endl;
        if(t1_value <= t2_value){
            return three_search(l,t2,A,R,M,H);
        }else{
            return three_search(t1,r,A,R,M,H);
        }
    }
}
int solve()
{

    ll N,A,R,M;
    cin >>  N >> A >> R >> M;
    vector<ll> H(N);
    for(int i = 0;i < N;i++){
        scanf("%lld",&H[i]);
    }
    ll h = three_search(0,1e9+1,A,R,M,H);
    // cout << h << endl;
    cout << value(h,A,R,M,H) << endl;
    // for(int i = 0;i < 10;i++){
    //     cout << i << ":"<< value(i,A,R,M,H) << endl;
    // }
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
    return 0;
}