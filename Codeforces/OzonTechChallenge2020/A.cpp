#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <iterator> // std::rbegin, std::rend

using namespace std;
using ll = long long;

int solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> b(n);
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }

    for(int i = 0;i < n;i++){
        cin >> b[i];
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    for(int i = 0;i< n;i++){
        if (i != 0){
            cout << " ";
        }
        cout << a[i];
    }
    cout << endl;
    for(int i = 0;i< n;i++){
        if (i != 0){
            cout << " ";
        }
        cout << b[i];
    }
    cout << endl;
    return 0;
}

int main()
{
    // 整数の入力
    ll t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        solve();
    }


    return 0;
}