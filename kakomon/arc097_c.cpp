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
#include <set>
#include <stack>
#include <atcoder/mincostflow>
#include <unordered_map>
using namespace std;
using ll = long long;
using namespace atcoder;

// zero indexed and vector
template <typename T>
class BIT
{
public:
    vector<T> data;
    BIT(long long n) : data(n) {}
    // 　indexに足す
    void add(int index, T v)
    {
        int N = data.size();
        for (int i = index; i < N; i |= i + 1)
        {
            data[i] += v;
        }
    }

    // [0,index)の和
    T sum(int index)
    {
        T retValue = 0;
        for (int i = index - 1; i >= 0; i = (i & (i + 1)) - 1)
        {
            retValue += data[i];
        }
        return retValue;
    }

    // [l,r)の和
    T sum(int l, int r)
    {
        return sum(r) - sum(l);
    }

    void show()
    {
        for (auto v : data)
        {
            cout << v << endl;
        }
    }
};

int solve()
{
    ll N;
    cin >> N;
    vector<pair<char, ll>> balls(2*N);
    vector<pair<ll, ll>> white_balls;
    vector<pair<ll, ll>> black_balls;
    for (int i = 0; i < 2*N; i++)
    {
        cin >> balls[i].first >> balls[i].second;
        balls[i].second--;
        if (balls[i].first == 'W')
        {
            white_balls.push_back({balls[i].second, i});
        }
        else
        {
            black_balls.push_back({balls[i].second, i});
        }
    }
    ll W = white_balls.size();
    ll B = black_balls.size();
    vector<ll> whites_bigger_left(N, 0);
    vector<ll> blacks_bigger_left(N, 0);
    BIT<ll> white_bit(N);
    for (int i = 0; i < W; i++)
    {
        whites_bigger_left[white_balls[i].first] = i - white_bit.sum(white_balls[i].first);
        white_bit.add(white_balls[i].first, 1);
    }
    BIT<ll> black_bit(N);
    for (int i = 0; i < B; i++)
    {
        blacks_bigger_left[black_balls[i].first] = i - black_bit.sum(black_balls[i].first);
        black_bit.add(black_balls[i].first, 1);
    }
    sort(white_balls.begin(), white_balls.end());
    sort(black_balls.begin(), black_balls.end());
    vector<vector<ll>> left_black_counts(W, vector<ll>(B + 1));
    vector<vector<ll>> left_white_counts(B, vector<ll>(W + 1));
    for (int i = 0; i < W; i++)
    {
        for (int j = B - 1; j >= 0; j--)
        {
            if (black_balls[j].second < white_balls[i].second)
            {
                left_black_counts[i][j] = left_black_counts[i][j + 1] + 1;
            }
            else
            {
                left_black_counts[i][j] = left_black_counts[i][j + 1];
            }
        }
    }
    for (int i = 0; i < B; i++)
    {
        for (int j = W - 1; j >= 0; j--)
        {
            if (white_balls[j].second < black_balls[i].second)
            {
                left_white_counts[i][j] = left_white_counts[i][j + 1] + 1;
            }
            else
            {
                left_white_counts[i][j] = left_white_counts[i][j + 1];
            }
        }
    }
    // cout << "W" << endl;
    // for(int i = 0;i < N;i++){
    //     cout << i << ":" << whites_bigger_left[i] << endl;
    // }
    // cout << "B" << endl;
    // for(int i = 0;i < N;i++){
    //     cout << i << ":" << blacks_bigger_left[i] << endl;
    // }
    vector<vector<ll>> DP(W + 1, vector<ll>(B + 1, numeric_limits<ll>::max()));
    DP[0][0] = 0;
    for (int i = 0; i <= W; i++)
    {
        for (int j = 0; j <= B; j++)
        {
            ll current = numeric_limits<ll>::max();
            if (i > 0)
            {
                current = min(
                    current,
                    DP[i - 1][j] + whites_bigger_left[white_balls[i - 1].first] + left_black_counts[i-1][j]);
            }
            if (j > 0)
            {
                current = min(
                    current,
                    DP[i][j-1] + blacks_bigger_left[black_balls[j - 1].first] + left_white_counts[j-1][i]);
            }
            DP[i][j] = min(DP[i][j],current);
        }
    }
    cout << DP[W][B] << endl;
    return 0;
}
int main()
{
    // ll t;
    // cin >> t;
    // while (t--)
    // {
        solve();
    // }
    cout << flush;
    return 0;
}
