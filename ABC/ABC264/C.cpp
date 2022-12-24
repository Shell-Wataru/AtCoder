#define _USE_MATH_DEFINES
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

int main()
{
  ll H1,W1;
  cin >> H1 >> W1;
  vector<vector<ll>> A(H1,vector<ll>(W1));
  for(int i = 0;i < H1;i++){
    for(int j  = 0;j < W1;j++){
      cin >> A[i][j];
    }
  }
  ll H2,W2;
  cin >> H2 >> W2;
  vector<vector<ll>> B(H2,vector<ll>(W2));
  for(int i = 0;i < H2;i++){
    for(int j  = 0;j < W2;j++){
      cin >> B[i][j];
    }
  }
  vector<ll> rows(H1,0);
  vector<ll> columns(W1,0);
  fill(rows.rbegin(),rows.rbegin()+H2,1);
  fill(columns.rbegin(),columns.rbegin()+W2,1);
  // for(int i = 0; i < H1;i++){
  //   cout << rows[i] << endl;
  // }
  do{
    do{
      // cout << "!" << endl;
      vector<vector<ll>> removedA(H2,vector<ll>(W2,0));
      ll row_index = -1;
      for(int i = 0;i < H1;i++){
        ll column_index = -1;
        if (rows[i] == 1){
          row_index++;
        }else{
          continue;
        }
        for(int j  = 0;j < W1;j++){
          if (columns[j] == 1){
            column_index++;
            removedA[row_index][column_index] = A[i][j];
          }else{
            continue;
          }

        }
      }
      if (removedA == B){
        cout << "Yes" << endl;
        return 0;
      }
    }while(next_permutation(columns.begin(),columns.end()));
  }while(next_permutation(rows.begin(),rows.end()));
  cout << "No" << endl;
  return 0;
}