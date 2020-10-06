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



ll grundy(ll n,ll last_type,ll x, ll y , ll z,vector<ll> &grundies_x,vector<ll> &grundies_y,vector<ll> &grundies_z){
    if (n == 0){
        return 0;
    }else{
        ll a = grundies_x[max(n - x, 0LL)];
        ll b = grundies_y[max(n - y, 0LL)];
        ll c = grundies_z[max(n - z, 0LL)];
        if(last_type == 0){
            set<ll> grundies = {a,b,c};
            for(int i = 0;i < 4;i++){
                if(grundies.find(i) == grundies.end()){
                    return i;
                }
            }
        }else if(last_type == 1){
            set<ll> grundies = {a,c};
            for(int i = 0;i < 4;i++){
                if(grundies.find(i) == grundies.end()){
                    return i;
                }
            }
        }else{
            set<ll> grundies = {a,b};
            for(int i = 0;i < 4;i++){
                if(grundies.find(i) == grundies.end()){
                    return i;
                }
            }
        }
    }
    return 0;
}

int solve(){
    cout << "++" << endl;
    ll n,x,y,z;
    cin >> n >> x >> y >> z;
    vector<ll> A(n);
    for(int i = 0;i < n;i++){
        cin >> A[i];
    }
    vector<ll> grundies_x(100,0);
    vector<ll> grundies_y(100,0);
    vector<ll> grundies_z(100,0);
    for(int i = 0;i< 100;i++){
        grundies_x[i] =  grundy(i,0,x, y ,z,grundies_x,grundies_y,grundies_z);
        grundies_y[i] =  grundy(i,1,x, y ,z,grundies_x,grundies_y,grundies_z);
        grundies_z[i] =  grundy(i,2,x, y ,z,grundies_x,grundies_y,grundies_z);
    }
    for(int i = 0 ; i< 100;i++){
        cout << grundies_x[i] << grundies_y[i] << grundies_z[i] << endl;
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