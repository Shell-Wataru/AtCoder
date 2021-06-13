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

bool all_same(string &s){
    for(auto c:s){
        if (c != s[0]){
            return false;
        }
    }
    return true;
}
int main()
{
    string s;
    cin >> s;
    ll min_count = 1000;
    for(int i = 0;i < 26;i++){
        string current_s = s;
        string next_s = "";
        ll count = 0;
        while(!all_same(current_s)){
            count++;
            for(int j = 0;j < current_s.size() -1;j++){
                if (current_s[j] - 'a' == i){
                    next_s += current_s[j];
                }else if(current_s[j+1] - 'a' == i){
                    next_s += current_s[j+1];
                }else{
                    next_s += current_s[j];
                }
            }
            swap(current_s,next_s);
            next_s = "";
        }
        min_count = min(min_count,count);
    }
    cout << min_count << endl;
    return 0;
}