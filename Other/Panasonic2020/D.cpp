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

int main()
{
    // 整数の入力
    ll N;
    cin >> N;
    vector<vector<string>> candidates(N+1);
    candidates[0].push_back("");
    for(int i = 1;i <= N;i++){
        for(auto c: candidates[i-1]){
            set<char> unique_chars;
            for(auto cc:c){
                unique_chars.insert(cc);
            }
            for(int j = 0;j < unique_chars.size() + 1 ;j++){
                candidates[i].push_back(c + (char)('a' + j));
            }
        }
    }
    for(auto c: candidates[N]){
        cout << c << endl;
    }
    return 0;
}