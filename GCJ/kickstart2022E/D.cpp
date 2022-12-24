#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <map>
#include <set>
#include <queue>

using namespace std;
using ll = long long;

template <typename T>
struct V : vector<T>
{
    using vector<T>::vector;
};
V()->V<int>;
V(size_t)->V<int>;
template <typename T>
V(size_t, T) -> V<T>;
template <typename T>
vector<T> make_vec(size_t n, T a) { return vector<T>(n, a); }
template <typename... Ts>
auto make_vec(size_t n, Ts... ts) { return vector<decltype(make_vec(ts...))>(n, make_vec(ts...)); }
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v)
{
    for (auto &e : v)
        os << e << ' ';
    return os;
}
// struct fast_ios
// {
//     fast_ios()
//     {
//         cin.tie(nullptr);
//         ios::sync_with_stdio(false);
//         cout << fixed << setprecision(20);
//     };
// } fast_ios_;

string solve()
{
    ll N,P,M,Ar,Ac;
    cin >> N >> P >> M >> Ar >> Ac;
    Ar--;
    Ac--;
    vector<pair<char,ll>> ops(4);
    for(int i = 0;i < 4;i++){
      cin >> ops[i].first;
      cin >> ops[i].second;
    }
    vector<vector<ll>> Ps(P,vector<ll>(3));
    for(int i = 0;i < P;i++){
      cin >> Ps[i][0];
      cin >> Ps[i][1];
      cin >> Ps[i][2];
      Ps[i][0]--;
      Ps[i][1]--;
    }
    auto DP = make_vec(N,N,1ll<<P,make_pair(numeric_limits<ll>::max(),numeric_limits<ll>::min()));
    DP[Ar][Ac][0] = {0,0};
    vector<pair<ll,ll>> directions = {
      {-1,0},
      {0,1},
      {0,-1},
      {1,0}
    };
    for(int i = 0;i < M;i++){
      auto nextDP = make_vec(N,N,1ll<<P,make_pair(numeric_limits<ll>::max(),numeric_limits<ll>::min()));
      for(int j = 0;j < N;j++){
        for(int k = 0;k < N;k++){
          for(int l = 0;l < 1ll<<P;l++){
            if (DP[j][k][l] == make_pair(numeric_limits<ll>::max(),numeric_limits<ll>::min())){
              continue;
            }
            // 移動しない
            nextDP[j][k][l].first = min(nextDP[j][k][l].first,DP[j][k][l].first);
            nextDP[j][k][l].second = max(nextDP[j][k][l].second,DP[j][k][l].second);
            for(int m = 0;m < 4;m++){
              ll next_j = j+directions[m].first;
              ll next_k = k+directions[m].second;
              if (0 <= next_j && next_j < N && 0 <= next_k && next_k < N){
                // ピザ届けない
                ll new_value1;
                ll new_value2;
                if (ops[m].first == '+'){
                  new_value1 = DP[j][k][l].first + ops[m].second;
                  new_value2 = DP[j][k][l].second + ops[m].second;
                }else if (ops[m].first == '-'){
                  new_value1 = DP[j][k][l].first - ops[m].second;
                  new_value2 = DP[j][k][l].second - ops[m].second;
                }else if (ops[m].first == '*'){
                  new_value1 = DP[j][k][l].first * ops[m].second;
                  new_value2 = DP[j][k][l].second * ops[m].second;
                }else if (ops[m].first == '/'){
                  if (DP[j][k][l].first >= 0){
                    new_value1 = DP[j][k][l].first / ops[m].second;

                  }else{
                    new_value1 = (DP[j][k][l].first - ops[m].second + 1 ) / ops[m].second;
                  }
                  if (DP[j][k][l].second >= 0){
                    new_value2 = DP[j][k][l].second / ops[m].second;
                  }else{
                    new_value2 = (DP[j][k][l].second - ops[m].second + 1 ) / ops[m].second;
                  }
                }
                nextDP[next_j][next_k][l].first = min(nextDP[next_j][next_k][l].first,min(new_value1,new_value2));
                nextDP[next_j][next_k][l].second = max(nextDP[next_j][next_k][l].second,max(new_value1,new_value2));

                // ピザ届ける
                for(int n = 0;n < P;n++){
                  if (Ps[n][0] == next_j && Ps[n][1] == next_k && !(l & 1ll<<n)){
                    if (ops[m].first == '+'){
                      new_value1 = DP[j][k][l].first + ops[m].second + Ps[n][2];
                      new_value2 = DP[j][k][l].second + ops[m].second + Ps[n][2];
                    }else if (ops[m].first == '-'){
                      new_value1 = DP[j][k][l].first - ops[m].second + Ps[n][2];
                      new_value2 = DP[j][k][l].second - ops[m].second + Ps[n][2];
                    }else if (ops[m].first == '*'){
                      new_value1 = DP[j][k][l].first * ops[m].second + Ps[n][2];
                      new_value2 = DP[j][k][l].second * ops[m].second + Ps[n][2];
                    }else if (ops[m].first == '/'){
                      if (DP[j][k][l].first >= 0){
                        new_value1 = DP[j][k][l].first / ops[m].second + Ps[n][2];
                      }else{
                        new_value1 = (DP[j][k][l].first - ops[m].second + 1 ) / ops[m].second + Ps[n][2];
                      }
                      if (DP[j][k][l].second >= 0){
                        new_value2 = DP[j][k][l].second / ops[m].second + Ps[n][2];
                      }else{
                        new_value2 = (DP[j][k][l].second - ops[m].second + 1) / ops[m].second + Ps[n][2];
                      }
                    }
                    nextDP[next_j][next_k][l | 1ll<<n].first = min(nextDP[next_j][next_k][l | 1ll<<n].first,min(new_value1,new_value2));
                    nextDP[next_j][next_k][l | 1ll<<n].second = max(nextDP[next_j][next_k][l | 1ll<<n].second,max(new_value1,new_value2));
                  }
                }
              }
            }
          }
        }
      }
      swap(nextDP,DP);
    }
    ll ans = numeric_limits<ll>::min();
    // for(int i = 0;i < N;i++){
    //   for(int j = 0;j < N;j++){
    //     cout <<"(" << DP[i][j][0].second << "," << DP[i][j][0].second << "),";
    //   }
    //   cout << endl;
    // }
    // for(int i = 0;i < N;i++){
    //   for(int j = 0;j < N;j++){
    //     cout <<"(" << DP[i][j][(1ll<<P) -1].second << "," << DP[i][j][(1ll<<P) -1].second << "),";
    //   }
    //   cout << endl;
    // }
    for(int i = 0;i < N;i++){
      for(int j = 0;j < N;j++){
        ans = max(ans,DP[i][j][(1ll<<P) -1].second);
      }
    }
    if (ans == numeric_limits<ll>::min()){
      return "IMPOSSIBLE";
    }else{
      return to_string(ans);
    }

}
int main()
{
    // 整数の入力
    ll T;
    cin >> T;

    for (int i = 1; i <= T; i++)
    {
        string ans = solve();
        cout << "Case #" << i << ": " << ans << endl;
    }

    return 0;
}