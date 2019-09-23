#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <math.h>
using namespace std;
using ll = long long;

int main()
{
    // 整数の入力
    ll N;
    cin >> N;
    vector<pair<ll, ll>> dots;
    map<pair<ll, ll>, ll> counter;
    for (int i = 0; i < N; i++)
    {
        ll x, y;
        cin >> x >> y;
        dots.push_back(make_pair(x, y));
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i == j){
                continue;
            }
            ll diff_x = dots[i].first - dots[j].first;
            ll diff_y = dots[i].second - dots[j].second;
            counter[make_pair(diff_x, diff_y)]++;
        }
    }

    ll max_count = 0;
    pair<ll, ll> ma_p;
    for (auto a : counter)
    {
        if (max_count < a.second)
        {
            max_count = a.second;
            ma_p = a.first;
        }
        // cout << a.first.first << a.first.second << a.second << endl;
    }
    // cout << counter[ma_p] << endl;
    cout << N - counter[ma_p] << endl;

    return 0;
}