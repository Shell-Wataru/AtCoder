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
    string S;
    cin >> S;
    deque<char> q;
    bool is_reverse = false;
    for(auto c:S){
        if (c == 'R'){
            is_reverse = !is_reverse;
        }else{
            if (is_reverse){
                if (q.empty() || q.front() != c){
                    q.push_front(c);
                }else{
                    q.pop_front();
                }
            }else{
                if (q.empty() || q.back() != c){
                    q.push_back(c);
                }else{
                    q.pop_back();
                }
            }
        }
    }
    if (is_reverse){
        while(!q.empty()){
            cout << q.back();
            q.pop_back();
        }
        cout << endl;
    }else{
        while(!q.empty()){
            cout << q.front();
            q.pop_front();
        }
        cout << endl;
    }
    return 0;
}