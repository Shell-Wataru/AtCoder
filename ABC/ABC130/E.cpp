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
namespace mp = boost::multiprecision;
ll BASE_NUM = 1000000007;


int main()
{
    // 整数の入力
    ll N,M;
    vector<ll> S,T;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        ll s;
        cin >> s;
        S.push_back(s);
    }

    for (int i = 0; i < M; i++)
    {
        ll t;
        cin >> t;
        T.push_back(t);
    }

    ll **data = new ll*[N+1];
    for (int i = 0;i<=N;i++){
        data[i] = new ll[M+1];
        for(int j = 0;j<=M;j++){
            data[i][j] = 1;
        }
    }
    for (int i = 1;i<=N;i++){
        for(int j = 1;j<=M;j++){
            if(S[i-1] == T[j-1]){
                data[i][j] = (data[i-1][j] + data[i][j-1]) % BASE_NUM;
            }else{
                data[i][j] = (BASE_NUM + data[i-1][j] + data[i][j-1] - data[i-1][j-1]) % BASE_NUM;
            }
        }
    }

    cout << data[N][M] << endl;
    return 0;
}