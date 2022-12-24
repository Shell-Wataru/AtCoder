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
#include <unordered_set>

using namespace std;
using ll = long long;

int main()
{

    vector<pair<ll,ll>> looks = {
        {1,2},
        {2,1}
    };
    ll n = looks.size()+1;
    cout << n << endl;
    while(true){
        char type;
        cin >> type;
        if (type == '!'){
            ll x ,y;
            cin >> x;
            cin >> y;
            cerr << x << " " << y << endl;
            break;
        }else{
            ll a,b,c,d;
            cin >> a >> b >> c >> d;
            ll ans = 0;
            for(auto l:looks){
                if (a <= l.first && l.first <= b &&  c <= l.second && l.second <= d){
                    ans++;
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}
