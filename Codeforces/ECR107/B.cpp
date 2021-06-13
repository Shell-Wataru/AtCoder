#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <map>
#include <bitset>
#include <numeric>
using namespace std;
using ll = long long;
ll BASE_NUM = 1000000007;

int solve()
{
    ll a,b,c;
    cin >> a >> b >> c;
    ll x = 1;
    ll y = 1;
    if (a == b){
        y = 2;
    }
    for(int i = 0;i < a - c;i++){
        x *= 10;
        x += 9;
    }
    for(int i = 0;i < c - 1;i++){
        x *= 10;
    }
    for(int i = 0;i < b - c;i++){
        y *= 10;
        y += 9;
    }
    for(int i = 0;i < c - 1;i++){
        y*= 10;
    }

    if (to_string(gcd(x,y)).size() == c){
        cout << x << " " << y << "\n";
    }else{
        cout << "!!!!" << "\n";
        cout << a << b << c << "\n";
        cout << x << " " << y << "\n";
    }
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
    cout << flush;
    return 0;
}
