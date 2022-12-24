#include <iostream>
#include <vector>
using namespace std;

using ll = long long;

int solve()
{
  ll n;
  cin >> n;
  string S;
  cin >> S;
  string S1;
  for(int i = 0;i < n;i++){
    if (S[i] == '1'){
      S1 = S.substr(i);
      break;
    }
  }
  if (S1.empty()){
    cout << 0 << endl;
    return 0;
  }
  vector<ll> zero_indices;
  for(int i = 0;i < S1.size();i++){
    if (S1[i] == '0'){
      zero_indices.push_back(i);
    }
  }

  if (zero_indices.size() == 0){
    cout << S1 << endl;
  }else{
    vector<ll> maximum;
    ll maximum_index = -1;

    for(int i = 0;i < zero_indices[0];i++){
      vector<ll> count;
      for(int j = 0;j < min((int)zero_indices.size(),30);j++){
        if (S1[i +zero_indices[j] - zero_indices[0]] == '1'){
          count.push_back(1);
        }else{
          count.push_back(0);
        }
      }
      if (count > maximum){
        maximum = count;
        maximum_index = i;
      }
    }
    // cout << maximum_index << endl;
    for(int j = zero_indices.size()-1;j >= 0;j--){
      // cout << zero_indices[j] << endl;
      // cout << maximum_index +zero_indices[j] - zero_indices[0] << endl;
      // cout << S1[zero_indices[j]] << "," << S1[maximum_index +zero_indices[j] - zero_indices[0]] << endl;
      S1[zero_indices[j]] = max(S1[zero_indices[j]],S1[maximum_index +zero_indices[j] - zero_indices[0]]);
    }
    cout << S1 << endl;
  }

  return 0;
}
int main()
{
  // 整数の入力
  // int t;
  // cin >> t;
  // for (size_t i = 0; i < t; i++)
  // {
    solve();
  // }
  cout << flush;
  return 0;
}
