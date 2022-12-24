#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <numeric>
using namespace std;
using ll = long long;

ll array_to_ll(vector<ll> &numbers)
{
    ll current = 0;
    for (int i = 0; i < numbers.size(); i++)
    {
        current += numbers[i] * (1ll << (3 * i));
    }
    return current;
}

vector<ll> convert(vector<ll> &numbers)
{
    ll current = array_to_ll(numbers);
    // cout << current << endl;
    vector<ll> data;
    while (current > 0)
    {
        ll a = current % 9;
        if (a == 8)
        {
            data.push_back(5);
        }
        else
        {
            data.push_back(a);
        }
        current /= 9;
    }
    return data;
}

int solve()
{
    string N;
    cin >> N;
    ll k;
    scanf("%lld", &k);
    vector<ll> numbers;
    for (int i = N.size() - 1; i >= 0; i--)
    {
        numbers.push_back(N[i] - '0');
    }
    for (int i = 0; i < k; i++)
    {
        numbers = convert(numbers);
    }
    if (numbers.size() == 0){
        cout << 0;
    }else{
        for (int i = numbers.size() - 1; i >= 0; i--)
        {
            cout << numbers[i];
        }
    }
    cout << endl;
    return 0;
}

int main()
{
    // // 整数の入力
    //   ll t;
    //   cin >> t;
    //   for (size_t i = 0; i < t; i++)
    //   {
    solve();
    //   }
    cout << flush;
    return 0;
}
