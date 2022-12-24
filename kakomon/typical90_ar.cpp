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
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;

int main()
{
    ll N, Q;
    cin >> N >> Q;
    deque<ll> q;
    for (int i = 0; i < N; i++)
    {
        ll a;
        cin >> a;
        q.push_back(a);
    }
    for (int i = 0; i < Q; i++)
    {
        ll t, x, y;
        cin >> t >> x >> y;
        if (t == 1)
        {
            x--;
            y--;
            ll a = q[0];
            swap(q[x], q[y]);
        }
        else if (t == 2)
        {
            ll a = q.back();
            q.pop_back();
            q.push_front(a);
        }
        else
        {
            x--;
            cout << q[x] << "\n";
        }
    }
    cout << flush;
    return 0;
}