#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <limits>
#include <cmath>
#include <iomanip>
#include <functional>
#include <random>
#include <unordered_map>

using namespace std;
using ll = long long;

int main()
{
    ll n;
    cin >> n;
    if (n >= 3 && n % 2 == 1)
    {
        cout << "Yes" << endl;
        ll base = 1ll<<(63 - __builtin_clzll(n+1));
        // cout << base << endl;
        for (int i = 1; i <= base-2; i++)
        {
            cout << i << " " << i + 1 << endl;
        }
        cout << base -1  << " " << n + 1 << endl;
        for (int i = 1; i <= base-2; i++)
        {
            cout << n+i << " " << n+ i + 1 << endl;
        }
        for (int i = base; i <= n; i += 2)
        {
            ll x = i ^ (i + 1);
            cout << x << " " << i << endl;
            cout << x << " " << i + 1 << endl;
            cout << i << " " << n + i + 1 << endl;
            cout << i + 1 << " " << n + i << endl;
        }
    }else if (__builtin_popcountll(n) >  1){
        ll base = 1ll<<(63 - __builtin_clzll(n));
        ll x = (base+1)^1^n;
        vector<ll> lines;
        lines.push_back(x);
        // cout << "x" << x << endl;
        for(int i = 1;i < base;i++){
            if (i != x){
                lines.push_back(i);
            }
        }
        cout << "Yes" << endl;
        for(int i = 0;i < lines.size()-1;i++){
            cout << lines[i] << " " << lines[i+1] << endl;
        }
        cout << lines.back() << " " << lines.front()+n << endl;
        for(int i = 0;i < lines.size()-1;i++){
            cout << lines[i]+n << " " << lines[i+1]+n << endl;
        }
        for(int i = base;i < n;i+=2){
            ll y = i ^ (i + 1);
            cout << y << " " << i << endl;
            cout << y << " " << i + 1 << endl;
            cout << i << " " << n + i + 1 << endl;
            cout << i + 1 << " " << n + i << endl;
        }
        cout << base+1 << " " << n << endl;
        cout << x << " " << 2*n << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}
