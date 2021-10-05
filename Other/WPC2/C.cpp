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
    ll N,K;
    cin >> N >> K;
    vector<vector<ll>> A(2,vector<ll>(N,0));
    for (int i = 0; i < N; i++)
    {
        cin >> A[0][i];
    }
    ll last_index =-1;
    for(ll i = 0;i < K ;i++){
        ll current = i% 2;
        ll next = (i+1)% 2;
        last_index = next;
        for (ll j = 0; j < N; j++)
        {
            A[next][j] = 0;
        }

        for(ll j = 0;j < N;j++){
            ll from = max(0ll,j - A[current][j]);
            ll to = min(N-1,j + A[current][j]) + 1;
            A[next][from]++;
            if (to != N){
                A[next][to]--;
            }
        }
        ll next_min = A[next][0];
        for(int j = 1; j < N;j++){
            A[next][j] += A[next][j-1];
            next_min = min(next_min,A[next][j]);
        }

        if (next_min == N){
            // cout << "break" << i << endl;
            break;
        }
    }
    for(int i = 0;i < N;i++){
        if(i != 0){
            cout << " ";
        }
        cout << A[last_index][i];
    }
    cout << endl;
   return 0;
}