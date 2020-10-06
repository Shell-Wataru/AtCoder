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

struct plain
{
    char direction;
    ll x, y;
};

ll ud_colision(vector<pair<ll, ll>> &U, vector<pair<ll, ll>> &D)
{
    ll min_colision = numeric_limits<ll>::max();
    vector<plain> ud_data;
    for (auto &u : U)
    {
        ud_data.push_back({'U', u.first, u.second});
    }
    for (auto &d : D)
    {
        ud_data.push_back({'D', d.first, d.second});
    }
    sort(ud_data.begin(), ud_data.end(), [](plain &l, plain &r) {
        if (l.x == r.x)
        {
            return l.y < r.y;
        }
        else
        {
            return l.x < r.x;
        }
    });
    for (int i = 1; i < ud_data.size(); i++)
    {
        if (ud_data[i - 1].x == ud_data[i].x &&
            ud_data[i - 1].y < ud_data[i].y &&
            ud_data[i - 1].direction == 'U' && ud_data[i].direction == 'D')
        {
            min_colision = min(min_colision,(ud_data[i].y - ud_data[i-1].y) * 5);
        }
    }
    return min_colision;
}


int solve()
{
    ll N;
    scanf("%lld", &N);
    vector<pair<ll, ll>> U;
    vector<pair<ll, ll>> R;
    vector<pair<ll, ll>> D;
    vector<pair<ll, ll>> L;
    for (size_t i = 0; i < N; i++)
    {
        ll x, y;
        char direction;
        scanf("%lld", &x);
        scanf("%lld", &y);
        scanf("%s", &direction);
        if (direction == 'U')
        {
            U.push_back({x, y});
        }
        else if (direction == 'R')
        {
            R.push_back({x, y});
        }
        else if (direction == 'D')
        {
            D.push_back({x, y});
        }
        else if (direction == 'L')
        {
            L.push_back({x, y});
        }
    }

    ll min_colision = numeric_limits<ll>::max();
    min_colision = min(min_colision,ud_colision(U,D));
    min_colision = min(min_colision,rl_colision(R,L));
    min_colision = min(min_colision,ur_colision(U,R));
    min_colision = min(min_colision,ul_colision(U,L));
    min_colision = min(min_colision,ur_colision(D,L));
    min_colision = min(min_colision,ul_colision(D,R));

    if (min_colision == numeric_limits<ll>::max())
    {
        cout << "SAFE" << endl;
    }
    else
    {
        cout << min_colision << endl;
    }

    return 0;
}
int main()
{
    // 整数の入力
    // ll N;
    // cin >> N;
    // for (int i = 0; i < N; i++)
    // {
        solve();
    // }
    // cout << flush;
    return 0;
}