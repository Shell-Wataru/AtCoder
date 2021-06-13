#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <map>
#include <bitset>
#include <numeric>

using namespace std;
using ll = long long;

struct UnionFind
{
    vector<int> data;

    UnionFind(int sz)
    {
        data.assign(sz, -1);
    }

    bool unite(int x, int y)
    {
        x = find(x), y = find(y);
        if (x == y)
            return (false);
        if (data[x] > data[y])
            swap(x, y);
        data[x] += data[y];
        data[y] = x;
        return (true);
    }

    bool same(int x, int y)
    {
        x = find(x), y = find(y);
        return x == y;
    }
    int find(int k)
    {
        if (data[k] < 0)
            return (k);
        return (data[k] = find(data[k]));
    }

    int size(int k)
    {
        return (-data[find(k)]);
    }
};

int main()
{
    ll N;
    cin >> N;
    vector<ll> A(N);
    vector<ll> B(N);
    vector<ll> P(N);

    for (size_t i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    for (size_t i = 0; i < N; i++)
    {
        cin >> B[i];
    }

    priority_queue<ll> odd_plus;
    priority_queue<ll> odd_minus;
    ll odds = 0;
    ll ans = 0;
    for(int i = 0;i < N;i++){
        if (A[i] > B[i]){
            ans += A[i];
            if (i % 2 == 0){
                odds--;
                odd_plus.push(B[i]-A[i]);
            }else{
                odds++;
                odd_minus.push(B[i]-A[i]);
            }
        }else{
            ans += B[i];
            if (i % 2 == 0){
                odd_minus.push(A[i]-B[i]);
            }else{
                odd_plus.push(A[i]-B[i]);
            }
        }
    }
    while(odds > 0){
        ans += odd_minus.top();
        odd_minus.pop();
        odds--;
    }

    while(odds < 0){
        ans += odd_plus.top();
        odd_plus.pop();
        odds++;
    }
    cout << ans << endl;
    return 0;
}