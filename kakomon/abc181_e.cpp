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
    // 整数の入力
    ll N, M;
    cin >> N >> M;
    vector<ll> H(N);
    vector<ll> W(M);
    for (size_t i = 0; i < N; i++)
    {
        cin >> H[i];
    }

    for (size_t i = 0; i < M; i++)
    {
        cin >> W[i];
    }
    sort(H.begin(), H.end());
    sort(W.begin(), W.end());
    vector<ll> diff_even_sum(N + 1, 0);
    vector<ll> diff_odd_sum(N + 1, 0);
    for (int i = 0; i <= N; i += 2)
    {
        diff_even_sum[i + 2] = diff_even_sum[i] + H[i + 1] - H[i];
    }
    for (int i = 1; i < N; i += 2)
    {
        diff_odd_sum[i + 2] = diff_odd_sum[i] + H[i + 1] - H[i];
    }
    // cout << "even" << endl;
    // for (int i = 0; i <= N; i++)
    // {
    //     cout << diff_even_sum[i] << endl;
    // }
    // cout << "odd" << endl;
    // for (int i = 0; i <= N; i++)
    // {
    //     cout << diff_odd_sum[i] << endl;
    // }
    ll j = 0;
    ll ans = numeric_limits<ll>::max();
    for(int i = 0;i < M;i++){
        while(j < N && W[i] > H[j]){
            j++;
        }
        // cout << j << endl;
        if (j % 2 == 0){
            ans = min(ans,diff_even_sum[j] + diff_odd_sum[N] - diff_odd_sum[j+1] + H[j] - W[i]);
        }else{
            ans = min(ans,diff_even_sum[j-1] + diff_odd_sum[N] - diff_odd_sum[j] + W[i] - H[j-1]);
        }
    }
    cout << ans << endl;
    return 0;
}