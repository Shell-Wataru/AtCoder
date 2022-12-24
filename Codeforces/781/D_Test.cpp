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
    ll x = 1;
    cout << 1 << endl;
    while(true){
        char type;
        cin >> type;
        if (type == '!'){
            ll a;
            cin >> a;
            cerr << a << endl;
            break;
        }else{
            ll l,r;
            cin >> l >> r;
            cerr << x + l << " " << x + r << endl;
            cout << gcd(x+l,x+r) << endl;
        }
    }
    return 0;
}
