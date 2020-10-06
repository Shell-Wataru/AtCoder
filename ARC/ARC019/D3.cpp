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
#include <bitset>
using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;
ll BASE_NUM = 1000000007;
const ll square_size = 3;
const ll bit_size = square_size*2 -1;

bool can_put_row(bitset<bit_size> &current, ll new_one){
  for(int i = 0; i < square_size; i++){
    int j = new_one - i;
    for(int k = 0;k < i;k++){
      for(int l = 0;l < j;l++){
        ll one = k+l;
        ll two = k + j;
        ll three = i+l;
        if (current[one] && current[two] && current[three]){
          return false;
        }
      }
    }
  }
  return true;
}
int main()
{
  // vector<string> answer(150, "......................................................................................................................................................");
  vector<bitset<bit_size>> candidates;
  candidates.push_back(bitset<bit_size>());
  for(int i = 0; i< bit_size;i++){
    ll candidate_size = candidates.size();
    cout << i << ":" << candidate_size << endl;
    for(int j = 0; j< candidate_size; j++){
      if (can_put_row(candidates[j],i)){
        bitset<bit_size> new_c = candidates[j];
        new_c.set(i);
        candidates.push_back(new_c);
      }
    }
  }
  ll max_count = 0;
  bitset<bit_size> max_bits;
  for(auto c:candidates){
    ll count = 0;
    for(int i = 0;i< bit_size; i++){
      if(c[i]){
        count += min(square_size - (i+1),i+1ll);
      }
    }
    if (count > max_count){
      max_count = count;
      max_bits = c;
    }
  }
  cout << max_count << endl;
  cout << max_bits << endl;
  return 0;
}