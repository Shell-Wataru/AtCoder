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

using namespace std;
using ll = long long;

int main()
{
  // 整数の入力
  string S1,S2,S3;
  cin >> S1 >> S2 >> S3;
  set<char> unique_char_sets;
  for(auto c:S1){
    unique_char_sets.insert(c);
  }
  for(auto c:S2){
    unique_char_sets.insert(c);
  }
  for(auto c:S3){
    unique_char_sets.insert(c);
  }
  if (unique_char_sets.size() > 10){
    cout << "UNSOLVABLE" << endl;
    return 0;
  }
  vector<ll> char_index(26,-1);
  ll index = 0;
  for(auto c:unique_char_sets){
    char_index[c - 'a'] = index;
    index++;
  }
  // for(auto i:char_index){
  //   cout << i << endl;
  // }
  vector<ll> mapping(10);
  iota(mapping.begin(),mapping.end(),0);
  // for(auto i:mapping){
  //   cout << i << endl;
  // }
  // cout << S1.size() << endl;
  // cout << S2.size() << endl;
  // cout << S3.size() << endl;
  do {
    ll n1 = 0;
    ll n2 = 0;
    ll n3 = 0;
    for(int i = 0;i < S1.size();i++){
      n1 *= 10;
      n1 += mapping[char_index[S1[i] - 'a']];
    }
    for(int i = 0;i < S2.size();i++){
      n2 *= 10;
      n2 += mapping[char_index[S2[i] - 'a']];
    }
    for(int i = 0;i < S3.size();i++){
      n3 *= 10;
      n3 += mapping[char_index[S3[i] - 'a']];
    }
    if (mapping[char_index[S1[0] - 'a']] != 0 && mapping[char_index[S2[0] - 'a']] != 0 && mapping[char_index[S3[0] - 'a']] != 0){
      // cout << "!" << endl;
      // cout << n1 << endl;
      // cout << n2 << endl;
      // cout << n3 << endl;
      if (n1 + n2 == n3){
        cout << n1 << endl;
        cout << n2 << endl;
        cout << n3 << endl;
        return 0;
      }
    }
  }while(next_permutation(mapping.begin(),mapping.end()));
  cout << "UNSOLVABLE" << endl;
  return 0;
}
