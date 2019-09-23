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
ll BASE_NUM = 1000000007;

int not_free_patterns(string &s,int i,vector<ll> &frees){
    if (i == s.length()-1){
        if(s[i] == '1'){
            return 3;
        }else{
            return 1;
        }
    }
    if(s[i] == '1'){
        return (2 * not_free_patterns(s,i+1,frees) + frees[i]) % BASE_NUM;
    }else{
        return not_free_patterns(s,i+1,frees);
    }
}

int main()
{
    // 整数の入力
    string s;
    cin >> s;
    vector<ll> frees;
    ll not_free = 1;
    ll free = 1;
    frees.push_back(1);
    for (int i = 1; i < s.length(); i++)
    {
        frees.push_back(frees[i - 1] * 3 % BASE_NUM);
    }
    reverse(frees.begin(),frees.end());

    // cout << frees.size() << endl;
     cout << not_free_patterns(s,0,frees) << endl;
    return 0;
}