#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <iomanip>
#include <cmath>
#include <set>
#include <numeric>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;
ll BASE_NUM = 1000000007;

int main()
{
  // 整数の入力
  ll N;
  cin >> N;
  vector<string> answer(N);
  for (int i = 0; i < N; i++)
  {
    cin >> answer[i];
  }

  for(int i = 0; i< N;i++){
    for(int j = i+1; j<N;j++){
      for(int k = 0; k < N;k++){
        for(int l = k+1; l < N;l++){
          if (answer[i][k] == 'o' && answer[i][l] == 'o' && answer[j][k] == 'o' && answer[j][l] == 'o'){
            cout << "found!!" << "(" << i << "," << k << ")" << "(" << j << "," << l << ")" << endl;
            answer[i][k] = '!';
            answer[i][l] = '!';
            answer[j][k] = '!';
            answer[j][l] = '!';
            for(auto s: answer){
              cout << s << endl;
            }
            return 0;
          }
        }
      }
    }
  }

  for(int i = 0; i< N;i++){
    for(int j = 0; j<N;j++){
      bool can_put = true;
      int max_reach = 0;
      if (answer[i][j] == 'o'){
        continue;
      }
      for(int k = 0; k< N;k++){
        if (i == k){
          continue;
        }
        for(int l = 0; l<N;l++){
          if (j == l){
            continue;
          }
          if(answer[i][l] == 'o' && answer[k][j] == 'o' && answer[k][l] == 'o'){
            can_put = false;
          }
        }
      }
      if (can_put){
        answer[i][j] = '*';
      }
    }
  }

  cout << N << endl;
  // sort(answer.begin(),answer.end(),greater<string>());
  for(auto s: answer){
    cout << s << endl;
  }
  ll counter = 0;
  for(int i = 0; i< N;i++){
    for(int j = 0; j<N;j++){
      if (answer[i][j] == 'o'){
        counter++;
      }
    }
  }
  cout << counter << endl;
  return 0;
}