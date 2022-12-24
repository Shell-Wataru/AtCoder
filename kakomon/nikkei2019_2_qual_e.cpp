#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <map>
#include <numeric>

using namespace std;
using ll = long long;

int solve()
{
    ll N,K;
    scanf("%lld", &N);
    scanf("%lld", &K);
    vector<vector<ll>> answers(N);
    map<ll,ll> mapping;
    ll odd = (N+1)/4;
    ll even = (N-1)/4;
    for(int i = 0;i < odd;i++){
        mapping[i] = odd*2-1-i;
        mapping[odd*2-1-i] = i;
    }
    for(int i = 0;i <= even;i++){
        mapping[2*odd + even - i] = 2*odd + even + i;
        mapping[2*odd + even + i] = 2*odd + even - i;
    }
    // for(int i = 0;i < N;i++){
    //     if (mapping.count(i) == 1){
    //         cout << i << ":" << mapping[i] << endl;
    //     }else{
    //         cout << i << ":" << i << endl;
    //     }
    // }
    for(int i = 0;i < N;i++){
        if (mapping.count(i) == 1){
            answers[i] = {mapping[i]+2*N-1-i+2*K,mapping[i]+K,2*N-1-i+K};
        }else{
            answers[i] = {2*N-1+2*K,i+K,2*N-1-i+K};
        }

    }
    sort(answers.begin(),answers.end());
    if (answers[0][1] + answers[0][2] <= K+2*N){
        for(int i = 0;i < N;i++){
            cout << answers[i][1] << " " << answers[i][2] << " " <<  K+2*N+i << "\n";
        }
        cout << flush;
    }else{
        cout << -1 << endl;
    }
    return 0;
}

int main()
{
    //   ll t;
    //   cin >> t;
    //   for (int i = 1; i <= t; i++)
    //   {
    solve();
    //   }
    cout << flush;
    return 0;
}