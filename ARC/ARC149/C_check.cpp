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

using namespace std;
using ll = long long;

vector<ll> answer(ll N, ll K)
{
    vector<ll> A(N);
    ll current = 0;
    while (current < N)
    {
        if (N - current < 2 * K)
        {
            cout << -1 << endl;
            return A;
        }
        else if (N - current - 2 * K < 2 * K)
        {
            ll remain = N - current;
            if (remain  > 3*K){
                ll a = remain - 3*K;
                ll b = K;
                ll c = K;
                ll d = K-a;
                ll e = a;
                for (int i = 0; i < b; i++)
                {
                    A[current + i] = current + K + i;
                }
                for (int i = 0; i < a; i++)
                {
                    A[current + b + i] = current + i;
                }
                for (int i = 0; i < c; i++)
                {
                    A[current + a + b + i] = current + remain - K + i;
                }
                for (int i = 0; i < d; i++)
                {
                    A[current + a + b + c + i] = current + i + a;
                }
                for (int i = 0; i < e; i++)
                {
                    A[current + a + b + c + d + i] = current + i + 2*K;
                }
                current += a + b + c + d + e;
            }else{
                ll a = K;
                ll b = N - current - K;
                for (int i = 0; i < b; i++)
                {
                    A[current + i] = current + a + i;
                }
                for (int i = 0; i < a; i++)
                {
                    A[current + b + i] = current + i;
                }
                current += a + b;
            }
        }
        else
        {
            ll a = K;
            ll b = K;
            for (int i = 0; i < b; i++)
            {
                A[current + i] = current + a + i;
            }
            for (int i = 0; i < a; i++)
            {
                A[current + b + i] = current + i;
            }
            current += a + b;
        }
    }
    return A;
}

vector<ll> naive(ll N,ll K){
    vector<ll> A(N);
    iota(A.begin(), A.end(), 0);
    vector<ll> ans;
    do
    {
        bool is_ok = true;
        for (int i = 0; i < N; i++)
        {
            if (abs(A[i] - i) < K)
            {
                is_ok = false;
                break;
            }
        }

        if (is_ok && (ans.empty() || A < ans))
        {
            ans = A;
        }
    } while (next_permutation(A.begin(), A.end()));
    return ans;
}
int main()
{
    for(int n = 2;n <= 11;n++){
        cout << "n" << n << endl;
        for(int k = 1;k <= n/2;k++){
            if (answer(n,k) != naive(n,k)){
                cout << n << "," << k << endl;
                for(auto a:answer(n,k)){
                    cout << a + 1<<  ",";
                }
                cout << endl;
                for(auto a:naive(n,k)){
                    cout << a + 1<<  ",";
                }
                cout << endl;
            }
        }
    }
    return 0;
}
