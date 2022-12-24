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
#include <unordered_set>
using namespace std;
using ll = long long;

ll mod(ll x,ll base){
    return x >= 0 ? x % base : (base - (-x) % base) % base;
}

int solve()
{
    ll N,M;
    cin >> N >> M;
    if (N == 1){
        cout << M << endl;
    }else if (N == 2){
        cout << 0 << " " << M << endl;
    }else{
        vector<ll> answer = {0};
        unordered_set<ll> used;
        ll total = 0;
        vector<ll> count(N);;
        for(int i = 0;i < N-2;i++){
            ll add = 1;
            while(used.count(answer.back()+add)){
                add++;
            }
            answer.push_back(answer.back()+add);
            total += answer.back();
            count[answer.back()%N]++;
            for(int j = 0;j <= i;j++){
                used.insert(answer.back()  + answer.back()-answer[j]);
            }
        }

        for(int j = (answer.back()+N-1)/N;true;j++){
            ll target = j*N + mod(M-total,N);
            if (target > answer.back() && !used.count(target)){
                answer.push_back(target);
                total += target;
                break;
            }
        }
        // cout << total << endl;
        // cout << M - total << endl;
        for(int j = 0;j < N;j++){
            if (j != 0){
                cout << " ";
            }
            cout << answer[j] + (M - total)/N;
        }
        cout << endl;
    }
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
  //   cout << flush;
  return 0;
}
