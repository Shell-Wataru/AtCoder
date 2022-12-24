#include <iostream>
#include <vector>
using namespace std;

using ll = long long;

int solve()
{
  string S;
  cin >> S;
  ll n = S.size();
  ll m = n/2;
  vector<vector<ll>> DP(n+1,vector<ll>(n+1,0));
  for(int j =  2;j <= n;j+=2){
    for(int i = 0; i+ j<= n;i++){
      if (j == 2){
        if (S[i] != S[i+1]){
          DP[i][i+j] = 1;
        }else{
          DP[i][i+j] = 0;
        }
      }else{
        // 前前
        ll ff;
        if (DP[i+2][i+j] == 1){
          ff = 1;
        }else if(DP[i+2][i+j] == 0){
          if (S[i] < S[i+1]){
            ff = 1;
          }else if (S[i] > S[i+1]){
            ff = -1;
          }else{
            ff = 0;
          }
        }else{
          ff = -1;
        }
        // 前後
        ll fb;
        if (DP[i+1][i+j-1] == 1){
          fb = 1;
        }else if(DP[i+1][i+j-1] == 0){
          if (S[i] < S[i+j-1]){
            fb = 1;
          }else if (S[i] > S[i+j-1]){
            fb = -1;
          }else{
            fb = 0;
          }
        }else{
          fb = -1;
        }
        // 後前
        ll bf;
        if (DP[i+1][i+j-1] == 1){
          bf = 1;
        }else if(DP[i+1][i+j-1] == 0){
          if (S[i] > S[i+j-1]){
            bf = 1;
          }else if (S[i] < S[i+j-1]){
            bf = -1;
          }else{
            bf = 0;
          }
        }else{
          bf = -1;
        }
        // 後後
        ll bb;
        if (DP[i][i+j-2] == 1){
          bb = 1;
        }else if(DP[i+1][i+j-2] == 0){
          if (S[i+j-1] < S[i+j-2]){
            bb = 1;
          }else if (S[i+j-1] > S[i+j-2]){
            bb = -1;
          }else{
            bb = 0;
          }
        }else{
          bb = -1;
        }
        DP[i][i+j] = max(min(ff,fb),min(bf,bb));
      }
    }
  }
  if (DP[0][n] == 1){
    cout << "Alice\n";
  }else if (DP[0][n] == 0){
    cout << "Draw\n";
  }else{
    cout << "Bob\n";
  }
  return 0;
}
int main()
{
  // 整数の入力
  int t;
  cin >> t;
  for (size_t i = 0; i < t; i++)
  {
    solve();
  }
  cout << flush;
  return 0;
}
