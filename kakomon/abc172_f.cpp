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
#include <set>
#include <atcoder/mincostflow>
using namespace std;
using ll = long long;
using namespace atcoder;

int main()
{
    ll N;
    cin >> N;
    vector<ll> A(N);
    ll x = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    for (int i = 2; i < N; i++)
    {
        x ^= A[i];
    }
    ll a = A[1] + A[0];
    ll b = 0;
    for (int i = 60; i >= 0; i--)
    {
        if (x & 1ll << i)
        {
            if ((x & 1ll << i) == ((a ^ b) & 1ll << i))
            {
                continue;
            }
            else if (a & 1ll << i)
            {
                b -= 1ll << i;
                bool added = false;
                for(int j = i-1;j>= 0;j--){
                    if (!(a&1ll<<j) && !(b&1ll<<j)){
                        added = true;
                        a += 1ll<<j;
                        b += 1ll<<j;
                        break;
                    }else if (!(a&1ll<<j)){
                        a += 1ll<<j;
                    }else if (!(b&1ll<<j)){
                        b += 1ll<<j;
                    }else{
                        break;
                    }
                }
                if (!added){
                    cout << -1 << endl;
                    return 0;
                }
            }
            else
            {
                cout << -1 << endl;
                return 0;
            }
        }
        else
        {
            if ((x & 1ll << i) == ((a ^ b) & 1ll << i))
            {
                continue;
            }
            else if (a & 1ll << i)
            {
                a -= 1ll << i;
                bool added = false;
                for(int j = i-1;j>= 0;j--){
                    if (!(a&1ll<<j) && !(b&1ll<<j)){
                        added = true;
                        a += 1ll<<j;
                        b += 1ll<<j;
                        break;
                    }else if (!(a&1ll<<j)){
                        a += 1ll<<j;
                    }else if (!(b&1ll<<j)){
                        b += 1ll<<j;
                    }else{
                        break;
                    }
                }
                if (!added){
                    cout << -1 << endl;
                    return 0;
                }
            }
            else
            {
                b -= 1ll << i;
                bool added = false;
                for(int j = i-1;j>= 0;j--){
                    if (!(a&1ll<<j) && !(b&1ll<<j)){
                        added = true;
                        a += 1ll<<j;
                        b += 1ll<<j;
                        break;
                    }else if (!(a&1ll<<j)){
                        a += 1ll<<j;
                    }else if (!(b&1ll<<j)){
                        b += 1ll<<j;
                    }else{
                        break;
                    }
                }
                if (!added){
                    cout << -1 << endl;
                    return 0;
                }
            }
        }
    }
    for (int i = 60; i >= 0; i--)
    {
        if ( (a & 1ll << i) && !(b & 1ll << i))
        {
            ll new_a = a-(1ll<<i);
            ll new_b = b+(1ll<<i);
            if (new_a != 0 && new_a >= A[1]){
                a = new_a;
                b = new_b;
            }
        }
    }
    if (b != 0 && a >= A[1])
    {
        cout << a - A[1] << endl;
    }
    else
    {
        cout << -1 << endl;
    }
    // cout << x << endl;
    // cout << (a ^ b) << endl;
    return 0;
}