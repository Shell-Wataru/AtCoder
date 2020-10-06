#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <iomanip>
#include <cmath>
#include <set>
#include <numeric>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

int main()
{
    // 整数の入力
    ll N;
    cin >> N;
    vector<ll> Answer(N);
    iota(Answer.begin(), Answer.end(), 1);
    map<ll, set<ll>> cannot_connecteds;
    map<ll, ll> points;
    for (int i = 0; i < N; i++)
    {
        ll a;
        cin >> a;
        cannot_connecteds[a].insert(i + 1);
    }

    for (int i = 1; i <= N; i++)
    {
        ll start = N;
        if (cannot_connecteds.find(i) == cannot_connecteds.end())
        {
        }
        else
        {
            set<ll> cannots = cannot_connecteds[i];
            while (cannots.find(start) != cannots.end())
            {
                start--;
            }
        }
        cout << i << " " <<start << endl;
        points[i] = start;
    }
    sort(Answer.begin(), Answer.end(), [&](ll &l, ll &r) {
        if (points[l] == points[r])
        {
            return l > r;
        }
        else
        {
            return points[l] < points[r];
        }
    });
    for (int i = 0; i < N; i++)
    {
        if (i == 0)
        {
            cout << Answer[i];
        }
        else
        {
            cout << " " << Answer[i];
        }
    }
    cout << endl;
    return 0;
}