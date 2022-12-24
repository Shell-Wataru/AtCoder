#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <map>
#include <numeric>

using namespace std;
using ll = long long;

int solve()
{
    ll Q;
    scanf("%lld", &Q);
    multiset<ll> s;
    multiset<ll,greater<ll>> rev_s;
    for (int i = 0; i < Q; i++)
    {
        // cout << "i:" << i << endl;
        ll t;
        cin >> t;
        if (t == 1)
        {
            ll x;
            cin >> x;
            s.insert(x);
            rev_s.insert(x);
        }
        else if (t == 2)
        {
            ll x, k;
            cin >> x >> k;
            auto iter = rev_s.lower_bound(x);
            while(iter != rev_s.end()){
                k-= 1;
                if (k <= 0){
                    break;
                }else{
                    // cout << "!" << *iter << endl;
                    iter++;
                }
            }
            if (iter == rev_s.end()){
                cout << -1 << endl;
            }else{
                cout << *iter << endl;
            }
        }
        else
        {
            ll x, k;
            cin >> x >> k;
            auto iter = s.lower_bound(x);
            while(iter != s.end()){
                k-= 1;
                if (k <= 0){
                    break;
                }else{
                    // cout << "!" << *iter << endl;
                    iter++;
                }
            }
            if (iter == s.end()){
                cout << -1 << endl;
            }else{
                cout << *iter << endl;
            }
        }
    }
    return 0;
}

int main()
{
    //   ll t;
    //   cin >> t;

    //   for (int i = 1; i <= t; i++)
    //   {
    solve();
    //   }
    cout << flush;
    return 0;
}