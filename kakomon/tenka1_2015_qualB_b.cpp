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

int main()
{
    string S;
    cin >> S;
    ll depth = 0;
    bool is_dict = false;
    for(auto c:S){
        if (c == '{'){
            depth++;
        }else if (c == '}'){
            depth--;
        }else if (c == ':' && depth == 1){
            is_dict = true;
        }
    }
    if (is_dict || S.size() == 2){
        cout << "dict" << endl;
    }else{
        cout << "set" << endl;
    }
    return 0;
}