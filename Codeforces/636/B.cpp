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

int solve()
{
    ll n;
    cin >> n;
    if(n % 4 != 0){
        cout << "NO"<< endl;
    }else{
        cout << "YES" << endl;
        vector<ll> a(n);
        for(int i = 0;i < n/2;i++){
            a[i] = 2 * i + 2;
        }
        for(int i = 0;i < n/2;i++){
            a[n/2 + i] = 2 * i + 3;
        }
        a[n/2-1] += n/2;
        for(int i = 0;i< n;i++){
            if(i != 0){
                cout << " ";
            }
            cout << a[i];
        }
        cout << endl;
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
    return 0;
}
