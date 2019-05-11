#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <map>
using namespace std;
using ll = long long;

struct casher
{
    ll m, s, p;
};

bool is_clear(ll T, ll R, ll C, ll B, vector<casher> cashers){
    sort(cashers.begin(), cashers.end(), [T](casher a, casher b) -> bool {
        return min(a.m,max(0LL,(T - a.p)/a.s)) > min(b.m,max(0LL,(T - b.p)/b.s));
    });

    ll total = 0;
    for (int i = 0; i < R ; i++){
        casher a = cashers[i];
        total += min(a.m,max(0LL,(T - a.p)/a.s));
    }
    // cout << total << endl;
    return B <= total;
}

ll optimal_time(ll R, ll C, ll B, vector<casher> cashers)
{
    ll low = 0;
    ll high = 9000000000000000000LL;

    while (high != low + 1)
    {
        ll center = (low + high) / 2;
        // cout << center << endl;
        if (is_clear(center, R, C, B, cashers))
        {
            high = center;
        }
        else
        {
            low = center;
        }
    }
    return high;
}

int main()
{
    // 整数の入力
    ll T;
    cin >> T;

    for (int i = 1; i <= T; i++)
    {
        ll R, C, B;
        vector<casher> cashers;
        cin >> R >> B >> C;
        for (int j = 0; j < C; j++)
        {
            casher c;
            cin >> c.m >> c.s >> c.p;
            cashers.push_back(c);
        };

        cout << "Case #" << i << ": " << optimal_time(R, C, B, cashers) << endl;
    }

    return 0;
}