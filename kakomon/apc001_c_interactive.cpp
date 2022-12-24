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

int main()
{
    string answer = "mvfmfmfmfmf";
    cout << answer.size() << endl;
    while(true){
        ll i;
        cin >> i;
        if (answer[i] == 'm'){
            cout << "Male" << endl;
        }else if(answer[i] == 'f'){
            cout << "Female" << endl;
        }else{
            cout << "Vacant" << endl;
            break;
        }
    }
    return 0;
}