#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <iomanip>
#include <cmath>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

ll BASE_NUM = 1000000007;

int main()
{
    // 整数の入力
    ll N, K;
    cin >> N;
    vector<ll> leaf_nodes(N + 1);
    vector<ll> min_root_nodes(N + 1);
    vector<ll> max_root_nodes(N + 1);
    for (int i = 0; i <= N; i++)
    {
        cin >> leaf_nodes[i];
    }
    if (N == 0){
        if (leaf_nodes[0] == 1){
            cout << 1 << endl;
        }else{
            cout << -1 << endl;
        }
        return 0;
    }
    min_root_nodes[N] = 0;
    max_root_nodes[N] = 0;
    for (int i = N - 1; i >= 0; i--)
    {
        min_root_nodes[i] = (min_root_nodes[i + 1] + leaf_nodes[i + 1] + 1) / 2;
        max_root_nodes[i] = max_root_nodes[i + 1] + leaf_nodes[i + 1];
    }

    ll nodes_count = 0;
    ll current_root = 0;
    bool can_make = true;
    for (int i = 0; i <= N; i++)
    {
        if (i == 0)
        {
            if (leaf_nodes[0] > 0)
            {
                can_make = false;
                break;
            }
            current_root = 1;
            nodes_count += 1;
        }
        else
        {
            if (current_root * 2 < min_root_nodes[i])
            {
                can_make = false;
                break;
            }
            current_root = min(max_root_nodes[i], 2 * current_root - leaf_nodes[i]);
            nodes_count += current_root + leaf_nodes[i];
        }
        // cout << current_root << " " << leaf_nodes[i] << endl;
    }
    if (can_make)
    {
        cout << nodes_count << endl;
    }
    else
    {

        cout << -1 << endl;
    }
    return 0;
}