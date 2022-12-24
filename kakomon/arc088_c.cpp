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
#include <atcoder/string>
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
    void add(int index, T v)
    {
        int N = data.size();
        for (int i = index; i < N; i |= i + 1)
        {
            data[i] += v;
        }
    }

    long long sum(int index)
    {
        T retValue = 0;
        for (int i = index; i >= 0; i = (i & (i + 1)) - 1)
        {
            retValue += data[i];
        }
        return retValue;
    }

    void show()
    {
        for (auto v : data)
        {
            cout << v << endl;
        }
    }
};

// 0~N-1に注意,compressするか確認
ll inversion_number(vector<ll> &A)
{
    BIT<ll> bit(A.size() * 2);
    ll ans = 0;
    for (int i = 0; i < A.size(); i++)
    {
        ans += i - bit.sum(A[i]);
        bit.add(A[i], 1);
    }
    return ans;
}

int main()
{
    string S;
    cin >> S;
    ll N = S.size();
    ll ans = 0;
    vector<ll> counts(26);
    for (auto c : S)
    {
        counts[c - 'a']++;
    }
    ll odd_count = 0;
    for (int i = 0; i < 26; i++)
    {
        if (counts[i] % 2 == 1)
        {
            odd_count++;
        }
    }
    if (odd_count > 1)
    {
        cout << -1 << endl;
        return 0;
    }
    vector<ll> a(N);
    vector<ll> current_counts(26);
    string first_half, second_half;
    for (int i = 0; i < N; i++)
    {
        if (counts[S[i] - 'a'] % 2 == 1)
        {
            if (current_counts[S[i] - 'a'] < counts[S[i] - 'a'] / 2)
            {
                a[i] = 0;
                first_half += S[i];
            }
            else if (current_counts[S[i] - 'a'] == counts[S[i] - 'a'] / 2)
            {
                a[i] = 1;
            }
            else
            {
                second_half += S[i];
                a[i] = 2;
            }
        }
        else
        {
            if (current_counts[S[i] - 'a'] < counts[S[i] - 'a'] / 2)
            {
                a[i] = 0;
                first_half += S[i];
            }
            else
            {
                a[i] = 2;
                second_half += S[i];
            }
        }
        current_counts[S[i] - 'a']++;
    }
    // for (auto aa : a)
    // {
    //     cout << aa << endl;
    // }
    ans += inversion_number(a);
    // cout << ans << endl;
    reverse(second_half.begin(), second_half.end());
    vector<vector<ll>> indices(26);
    for (int i = 0; i < first_half.size(); i++)
    {
        indices[first_half[i] - 'a'].push_back(i);
    }
    vector<ll> b(first_half.size());
    for (int i = first_half.size() - 1; i >= 0; i--)
    {
        b[i] = indices[second_half[i] - 'a'].back();
        indices[second_half[i] - 'a'].pop_back();
    }
    ans += inversion_number(b);
    cout << ans << endl;
    return 0;
}
