#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
#include <numeric>

using namespace std;
using ll = long long;

int main()
{
    vector<ll> a = {2,4,0,1,3};
    ll n = a.size();
    cout << 1 << endl;
    cout << n << endl;
    while(true){
        char type;
        cin >> type;
        if (type == '!'){
            ll x,y;
            cin >> x >> y;
            x--;
            y--;
            if ( a[x] == 0 || a[y] == 0){
              cout << 1 << endl;
            }else{
              cout << -1 << endl;
            }
            cerr << x << "," << y << endl;
            break;
        }else{
            ll x,y;
            cin >> x >> y;
            x--;
            y--;
            cout << gcd(a[x],a[y]) << endl;
            // cerr << gcd(a[x],a[y]) << endl;
        }
    }
    return 0;
}
