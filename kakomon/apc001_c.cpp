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
#include <regex>
using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

string query(ll i){
    string s;
    cout << i << endl;
    cin >> s;
    return s;
}
int main()
{
    ll N;
    cin >> N;
    string head = query(0);
    string tail = head;
    if (head == "Vacant"){
        return 0;
    }
    ll l = 0;
    ll r = N;
    while(true){
        ll center = (l+r)/2;
        // cerr << l << ":" <<r << endl;
        if (l == r){
            break;
        }
        // cerr << center << endl;
        string center_string =  query(center);
        if (center_string == "Vacant"){
            return 0;
        }
        if (head == center_string && (center - l) % 2 == 1){
            r = center;
            tail = center_string;
        }else if (tail == center_string && (r - center) % 2 == 1){
            l = center;
            head = center_string;
        }else if (head != center_string && (center - l) % 2 == 0){
            r = center;
            tail = center_string;
        }else{
            l = center;
            head = center_string;
        }
    }
    return 0;
}