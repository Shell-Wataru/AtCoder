#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <numeric>
using namespace std;
using ll = long long;

int solve()
{
    ll q;
    scanf("%lld", &q);
    priority_queue<ll> smaller_half;
    priority_queue<ll,vector<ll>,greater<ll>> bigger_half;
    ll smaller_sum = 0;
    ll bigger_sum = 0;
    ll base = 0;
    for (int i = 0; i < q; i++)
    {
        ll t;
        cin >> t;
        if (t == 2)
        {
            if (smaller_half.size() == 0){
                cout << "0 "<< base << "\n";
            }else{
                ll x = smaller_half.top();
                // cout << base << endl;
                // cout << smaller_sum << endl;
                // cout << bigger_sum << endl;
                // cout << - (x * (ll)smaller_half.size()) << endl;
                // cout << - (x * (ll)bigger_half.size()) << endl;
                cout << x << " " << abs(smaller_sum - x * (ll)smaller_half.size()) + abs(bigger_sum - x * (ll)bigger_half.size()) + base << "\n";
            }
        }
        else
        {
            ll a, b;
            cin >> a >> b;
            base += b;
            if (smaller_half.empty() || a <= smaller_half.top()){
                smaller_half.push(a);
                smaller_sum += a;
                if (smaller_half.size() > bigger_half.size() + 1){
                    bigger_half.push(smaller_half.top());
                    smaller_sum -= smaller_half.top();
                    bigger_sum += smaller_half.top();
                    smaller_half.pop();
                }
            }else {
                bigger_half.push(a);
                bigger_sum += a;
                if (bigger_half.size() > smaller_half.size()){
                    smaller_half.push(bigger_half.top());
                    smaller_sum += bigger_half.top();
                    bigger_sum -= bigger_half.top();
                    bigger_half.pop();
                }
            }
        }
    }
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
    cout << flush;
    return 0;
}