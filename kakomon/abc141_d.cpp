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
    ll N,M;
    cin >> N >> M;
    priority_queue<ll> q;
    for (size_t i = 0; i < N; i++)
    {
        ll a;
        cin >> a;
        q.push(a);
    }

    for (size_t i = 0; i < M; i++)
    {
        ll maximum = q.top();
        q.pop();
        q.push(maximum/2);
    }
    ll total = 0;
    while(!q.empty()){
        total += q.top();
        q.pop();
    }
    cout << total << endl;
    return 0;
}