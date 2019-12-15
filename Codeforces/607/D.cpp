#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
using namespace std;
using ll = long long;
ll BASE_NUM = 998244353;


bool can_reverse(string w, set<string> &words){
  reverse(w.begin(),w.end());
  return words.find(w) == words.end();
}
int solve(){
  ll n;
  cin >> n;
  set<string> words;
  vector<string> word_list;
  ll zero_zero = 0;
  ll zero_one = 0;
  ll one_zero = 0;
  ll one_one = 0;
  for(int i = 0;i<n;i++){
    string w;
    cin >> w;
    if (w.front() == '0' && w.back() == '0' ){
      zero_zero++;
    }else if (w.front() == '0' && w.back() == '1' ){
      zero_one++;
    }else if (w.front() == '1' && w.back() == '0' ){
      one_zero++;
    }else{
      one_one++;
    }
    words.insert(w);
    word_list.push_back(w);
  }
  if (one_one > 0 && zero_zero > 0 && one_zero == 0 && zero_one == 0){
    cout <<  -1 << endl;
  }else{
    ll reverses = abs(one_zero - zero_one)/2;
    cout << reverses << endl;
    vector<ll> reverse_list;
    for(int i = 0;i< n;i++){
      string w = word_list[i];
      if (one_zero - zero_one > 0){
        if (w.front() == '1' && w.back() == '0' && can_reverse(w,words)){
          reverse_list.push_back(i);
        }
      }else{
        if (w.front() == '0' && w.back() == '1' && can_reverse(w,words) ){
          reverse_list.push_back(i);
        }
      }
      if (reverse_list.size() == reverses){
        break;
      }
    }
    for(int i = 0;i< reverses;i++){
      if (i == 0){
        cout << reverse_list[i] + 1;
      }else{
        cout << " " <<reverse_list[i] + 1;
      }
    }
    cout << endl;

  }
  return 0;
}
int main()
{
  ll t;
  cin >> t;
  for(int i = 0;i< t ;i++){
    solve();
  }
 return 0;
}