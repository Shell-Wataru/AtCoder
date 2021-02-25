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
    vector<ll> A(N);
    vector<ll> B(M);
    for (int i = 0; i < N; i++)
    {
        scanf("%lld", &A[i]);
    }
    for (int i = 0; i < M; i++)
    {
        scanf("%lld", &B[i]);
    }
    vector<vector<ll>> DP(N + 1, vector<ll>(M + 1, numeric_limits<ll>::max()));
    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j <= M; j++)
        {
            if (i == 0 && j == 0){
                DP[0][0] = 0;
            }else if (i == 0){
                DP[i][j] = min(DP[i][j],DP[i][j-1]+1);
            }else if (j == 0){
                DP[i][j] = min(DP[i][j],DP[i-1][j]+1);
            }else{
                if (A[i-1] == B[j-1])
                {
                    DP[i][j] = min(DP[i][j], DP[i-1][j-1]);
                }else{
                    DP[i][j] = min(DP[i][j], DP[i-1][j-1]+1);
                }
                DP[i][j] = min(DP[i][j],DP[i][j-1]+1);
                DP[i][j] = min(DP[i][j],DP[i-1][j]+1);
            }
        }
    }
    cout << DP[N][M] << endl;
    return 0;
}