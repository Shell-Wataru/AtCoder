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

int clz(unsigned long long N) {
    return N ? 63 - __builtin_clzll(N) : -1;
}

int main()
{
  ll L;
  cin >> L;
  L--;
  vector<vector<ll>> answer;
  ll total = 0;
  ll current = 0;
  while(total + (1ll<<current) <= L){
      answer.push_back({current,current+1,1ll<<current});
      answer.push_back({current,current+1,0});
      total += 1ll<<current;
      current++;
  }
  while(total < L){
      ll width = L - total;
    //   cout << "w:" << width << "->" << clz(width) << endl;
      answer.push_back({clz(width),current,total+1});
      total += (1ll<< clz(width));
  }
  cout << current + 1 << " " << answer.size() << endl;
  for(int i = 0;i < answer.size();i++){
      cout << answer[i][0] + 1 << " "<< answer[i][1] + 1 << " " << answer[i][2] << endl;
  }
  return 0;
}
