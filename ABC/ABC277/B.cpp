

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
    ll N;
    cin >> N;
    set<string> SS;
    bool is_ok = true;
    for(int i = 0;i < N;i++){
      string S;
      cin >> S;
      if (!(S[0] == 'H' || S[0] == 'D' || S[0] == 'C' || S[0] == 'S')){
        is_ok = false;
      }
      string T ="A23456789TJQK";
      bool any = false;
      for(auto t:T){
        if (S[1] == t){
          any = true;
        }
      }
      if (!any){
        is_ok = false;
      }
      SS.insert(S);
    }
    if (is_ok && SS.size() == N){
      cout << "Yes" << endl;
    }else{
      cout << "No" << endl;
    }
    return 0;
}