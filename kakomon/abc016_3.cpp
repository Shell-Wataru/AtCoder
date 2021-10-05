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

int my_friend_freind_count(vector<pair<ll, ll>> &relation_ships,ll N, ll me)
{
    vector<bool> my_friend_friend(N, false);
    vector<bool> my_friend(N, false);
    for (auto r : relation_ships)
    {
        if (r.first == me)
        {
            my_friend[r.second] = true;
        }
        else if (r.second == me)
        {
            my_friend[r.first] = true;
        }
    }

    for (auto r : relation_ships)
    {
        if (r.first != me && r.second != me)
        {
            if (my_friend[r.first] && !my_friend[r.second])
            {
                my_friend_friend[r.second] = true;
            }
            else if (!my_friend[r.first] && my_friend[r.second])
            {
                my_friend_friend[r.first] = true;
            }
        }
    }
    ll ans = 0;
    for(auto b:my_friend_friend){
        if (b){
            ans++;
        }
    }
    return ans;
}
int main()
{
    // 整数の入力
    ll N, M;
    cin >> N;
    cin >> M;
    vector<pair<ll, ll>> relation_ships(M);
    for (int i = 0; i < M; i++)
    {
        ll u, v;
        cin >> u >> v;
        u--;
        v--;
        relation_ships[i].first = u;
        relation_ships[i].second = v;
    }
    for(int i =0;i < N;i++){
        cout << my_friend_freind_count(relation_ships,N,i) << endl;
    }
    return 0;
}