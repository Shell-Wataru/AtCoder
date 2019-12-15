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


pair<ll,ll> current(ll n){
    pair<ll,ll> p;
    p.first = n/10;
    if (p.first % 2 == 0){
        p.second = n % 10;
    }else{
        p.second = 9 - (n % 10);
    }
    return p;
}

ll remain(pair<ll,ll> &p){
    if (p.first % 2 == 0){
        return p.first * 10 + p.second;
    }else{
        return p.first * 10 + 9 - p.second;
    }
}

ll climb(ll n,ll above){
    pair<ll,ll> c = current(n);
    c.first = c.first - above;
    return remain(c);
}

int main()
{
    vector<vector<ll>> sugoroku(10, vector<ll>(10, 0));
    vector<double> kitaiti(100,0);
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            ll a;
            cin >> a;
            sugoroku[i][j] = a;
        }
    }
    for (int i = 1; i < 100; i++)
    {
        ll e = 0;
        for(int j = 1;j<6;j++){
            if (i - j >= 0){
                e += 1.0/6 *
            }else{
                e += 1.0/6 * 1
            }
        }
    }
    return 0;
}