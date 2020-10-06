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

vector<ll> longest(ll n, string &s){
  // cout << n << " " << s << endl;
  vector<ll> answer(n,0);
  vector<ll> continuations;
  continuations.push_back(0);
  char current_char = '<';
  for(int i = 0;i < n-1;i++){
    if (s[i] == current_char){
      continuations.back()++;
    }else{
      current_char = s[i];
      continuations.push_back(1);
    }
  }
  if (current_char == '<'){
    continuations.push_back(0);
  }

  ll current_index  = 0;
  ll smallest = 1;
  for(int i = 0;i < continuations.size();i++){
    if (i % 2 == 0){
      for(int j = 0; j < continuations[i]; j++){
        answer[current_index + j] = smallest;
        smallest++;
      }
    }
    current_index += continuations[i];
  }

  ll biggest = n;
  current_index = n - 1;
  for(int i = continuations.size() - 1;i >= 0;i--){
    current_index -= continuations[i];
    if (i % 2 == 1){
      ll to;
      if (i == continuations.size() - 1){
        to = continuations[i] + 1;
      }else{
        to = continuations[i];
      }
      for(int j = 0; j < to; j++){
        answer[current_index + j] = biggest;
        biggest--;
      }
    }
  }
  return answer;
}

int solve(){
  ll n;
  cin >> n;
  string s;
  cin >> s;
  vector<ll> longest_answer = longest(n,s);
  // cout << s << endl;
  string reverse_s(s);
  reverse(reverse_s.begin(),reverse_s.end());
  for(int i = 0; i< n - 1;i++){
    if(reverse_s[i] == '<'){
      reverse_s[i] = '>';
    }else{
      reverse_s[i] = '<';
    }
  }
  vector<ll> shortest_answer = longest(n,reverse_s);
  reverse(shortest_answer.begin(),shortest_answer.end());


  for(int i = 0;i < n;i++){
    if (i == 0){
      cout << shortest_answer[i];
    }else{
      cout << " " << shortest_answer[i];
    }
  }
  cout << endl;

  for(int i = 0;i < n;i++){
    if (i == 0){
      cout << longest_answer[i];
    }else{
      cout << " " << longest_answer[i];
    }
  }
  cout << endl;
  return 0;
}

int main()
{
  ll t;
  cin >> t;
  for (size_t i = 0; i < t; i++)
  {
      solve();
  }
 return 0;
}