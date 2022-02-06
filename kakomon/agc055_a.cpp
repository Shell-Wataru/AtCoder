#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
#include <boost/multiprecision/cpp_int.hpp>
#include <random>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;
ll BASE_NUM = 1000000007;

vector<vector<ll>> orders = {
    {0, 1, 2},
    {1, 2, 0},
    {2, 0, 1},
    {0, 2, 1},
    {1, 0, 2},
    {2, 1, 0}};

pair<ll,ll> maximum_take1(vector<vector<ll>> &Sum, ll order_index)
{
    ll n = Sum[0].size();
    ll max_a = 0;
    ll max_a_c_index = 0;
    for (int i = 0; i < n; i++)
    {
        ll a = Sum[orders[order_index][0]][i];
        if (a == max_a)
        {
            continue;
        }
        ll b_index = lower_bound(Sum[orders[order_index][1]].begin() + i, Sum[orders[order_index][1]].end(), Sum[orders[order_index][1]][i] + a) - Sum[orders[order_index][1]].begin();
        if (b_index == n)
        {
            break;
        }
        ll c_index = lower_bound(Sum[orders[order_index][2]].begin() + b_index, Sum[orders[order_index][2]].end(), Sum[orders[order_index][2]][b_index] + a) - Sum[orders[order_index][2]].begin();
        if (c_index == n)
        {
            break;
        }
        max_a = max(max_a, a);
        max_a_c_index = c_index;
    }
    ll max_a_a_index =  lower_bound(Sum[orders[order_index][0]].begin(),Sum[orders[order_index][0]].end(),1) - Sum[orders[order_index][0]].begin();
    // cout << max_a_a_index << "~" << max_a_c_index << endl;
    return {max_a, max_a_a_index - max_a_c_index};
}

vector<vector<ll>> GetSum(string &S, vector<ll> &ans)
{
    ll N = S.size();
    vector<vector<ll>> Sum(3, vector<ll>(N, 0));
    string remain;
    for (int j = 0; j < N; j++)
    {
        if (j != 0)
        {
            for (int k = 0; k < 3; k++)
            {
                Sum[k][j] += Sum[k][j - 1];
            }
        }
        if (ans[j] == 0)
        {
            Sum[S[j] - 'A'][j]++;
            remain += S[j];
        }
    }
    // cout << remain.size() << endl;
    // cout << remain << endl;
    return Sum;
}

int main()
{
    ll N;
    string S;
    cin >> N;
    cin >> S;
    std::random_device seed_gen;
    std::mt19937 engine(seed_gen());
    shuffle(S.begin(),S.end(),engine);
    N = S.size()/3;
    vector<ll> ans(3 * N);
    for (int i = 0; i < 6; i++)
    {
        // reverse(orders.begin(),orders.end());
        vector<vector<ll>> Sum = GetSum(S, ans);
        ll max_take_order = -1;
        pair<ll,ll> max_take = {0,0};
        for (int j = 0; j < 6; j++)
        {
            pair<ll,ll> take = maximum_take1(Sum, j);
            // cout << take.first << ",";
            if (take > max_take)
            {
                max_take = take;
                max_take_order = j;
            }
        }
        // cout << endl;
        if (max_take_order == -1)
        {
            break;
        }
        ll index = 0;
        ll count = 0;
        for (int j = 0; j < 3 * N; j++)
        {
            if (ans[j] == 0 && S[j] - 'A' == orders[max_take_order][index])
            {
                count++;
                ans[j] = i + 1;
            }
            if (count == max_take.first)
            {
                index++;
                count = 0;
            }
            if (index == 2)
            {
                break;
            }
        }
        for (int j = 3*N-1; j >= 0; j--)
        {
            if (ans[j] == 0 && S[j] - 'A' == orders[max_take_order][index])
            {
                count++;
                ans[j] = i + 1;
            }
            if (count == max_take.first)
            {
                break;
            }
        }
    }

    for (int i = 0; i < 3 * N; i++)
    {
        cout << ans[i];
    }
    cout << endl;
    cout << *max_element(ans.begin(),ans.end()) << endl;
    if (*min_element(ans.begin(),ans.end()) == 0){
        cout << S << endl;
    }
    return 0;
}