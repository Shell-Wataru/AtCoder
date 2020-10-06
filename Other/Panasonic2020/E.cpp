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


bool match(string &a, string &b, int zure){
    for(int b_index = 0;b_index< b.size();b_index++){
        int a_index = b_index + zure;
        if (a_index >= a.size()){
            break;
        }

        if(a[a_index] != '?' && b[b_index] != '?' && a[a_index] != b[b_index]){
            return false;
        }
    }
    return true;
}

ll min_value(string &a ,string &b,string &c){
    ll min_ret = a.size() + b.size() + c.size();
    ll ret_a = a.size();
    for(int i = 0;i <= a.size();i++){
        if (min_ret <= ret_a){
            break;
        }
        ll ret_b = i + b.size();
        if (ret_b < min_ret && match(a,b,i)){
            for(int j = 0;j <= b.size();j++){
                ll ret_c = i + j + c.size();
                if (ret_c < min_ret && match(b,c,j) && match(a,c,i+j)){
                    min_ret = min(max(max(ret_a,ret_b),ret_c), min_ret);
                }
            }
        }
    }
    return min_ret;
}
int main()
{
    // 整数の入力
    string a,b,c;
    cin >> a >> b >> c;
    ll min_length = 1000000;
    min_length = min(min_value(a,b,c),min_length);
    min_length = min(min_value(a,c,b),min_length);
    min_length = min(min_value(b,a,c),min_length);
    min_length = min(min_value(b,c,a),min_length);
    min_length = min(min_value(c,a,b),min_length);
    min_length = min(min_value(c,b,a),min_length);
    cout << min_length << endl;
    return 0;
}