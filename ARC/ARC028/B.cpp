#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <ctime>
#include <map>
#include <boost/multiprecision/cpp_int.hpp>
#include <string>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

int main()
{
    // 整数の入力
    ll n, k;
    priority_queue<ll> q;
    vector<ll> X;
    map<ll, ll> x_indexes;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        X.push_back(x);
        x_indexes[x] = i + 1;
    }

    for (int i = 0; i < n; i++)
    {
        if (q.size() < k)
        {
            q.push(X[i]);
        }
        else if (q.size() == k && X[i] < q.top())
        {
            q.pop();
            q.push(X[i]);
        }
        if (q.size() == k){
            // cout << q.top();
            cout << x_indexes[q.top()] << "\n";
        }
    }

    cout << flush;
    return 0;
}