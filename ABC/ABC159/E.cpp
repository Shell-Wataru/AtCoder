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
#include <set>
using namespace std;
using ll = long long;
ll BASE_NUM = 1000000007;

int main()
{
    // 整数の入力
    ll H,W,K;
    cin >> H >> W >> K;
    vector<string> S(H);
    for(int i = 0; i < H;i++){
      cin >> S[i];
    }
    ll min_lines = BASE_NUM;
    for (int bit = 0; bit < (1<<(H-1)); ++bit){
      // cout << bitset<10>(bit) << endl;
      map<ll,ll> group;
      ll current_group = 0;
      ll holizontal_lines = 0;
      ll vertical_lines = 0;
      for(int i = 0;i < H;i++){
        group[i] = current_group;
        if (bit & 1<<i){
          current_group = i + 1;
          holizontal_lines++;
        }
      }
      map<ll,ll> counts;
      int i = 0;
      int start_from = 0;
      while(i < W){
        if (counts.empty()){
          start_from = i;
        }
        for(int j = 0;j< H;j++){
          if(S[j][i] == '1'){
           counts[group[j]]++;
          }
        }
        bool not_over = true;
        for(auto p:counts){
          if(p.second > K){
            not_over = false;
            break;
          };
        }
        if(not_over){
          i++;
        }else if(start_from == i){
          vertical_lines = BASE_NUM;
          break;
        }else{
          counts.clear();
          vertical_lines++;
        }
      }
      // for(auto p:counts){
      //   cout << p.first << " " << p.second <<endl;
      // }
      min_lines =  min(min_lines,vertical_lines + holizontal_lines);
    }
    cout << min_lines << endl;
    return 0;
}
