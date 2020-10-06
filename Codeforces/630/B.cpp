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

long long gcd(long long a, long long b){
    if (a%b == 0){
        return b;
    }else{
        return gcd(b,a%b);
    }
}

int solve()
{
    ll n;
    cin >> n;
    vector<ll> A(n);
    for(int i = 0;i < n;i++){
        cin >> A[i];
    }
    map<ll,ll> color_wheel = {
        {2,1},
        {3,2},
        {5,3},
        {7,4},
        {11,5},
        {13,6},
        {17,7},
        {19,8},
        {23,9},
        {29,10},
        {31,11},
    };

    map<ll,ll> real_colors;
    ll color = 0;
    for(int i = 0;i< n;i++){
        for(auto p:color_wheel){
            // cout << p.first << " " << p.second << endl;
            if (gcd(A[i],p.first) > 1){
                if(real_colors.find(p.first) == real_colors.end()){
                    real_colors[p.first] = color;
                    color++;
                }
                break;
            }
        }
    }

    cout << real_colors.size() << endl;
    for(int i = 0;i< n;i++){
        if (i != 0){
            cout << " ";
        }
        for(auto p:color_wheel){
            // cout << p.first << " " << p.second << endl;
            if (gcd(A[i],p.first) > 1){
                cout << real_colors[p.first] + 1;
                break;
            }
        }
    }
    cout << endl;
    return 0;
}
int main()
{
    ll t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        solve();
    }
    return 0;
}
