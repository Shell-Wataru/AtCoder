#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <ctime>
#include <map>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

int main()
{
    // 整数の入力
    long long N,M,listened_disc;
    time_t t;
    string name,kit;

    map<char,long long> num_order;
    vector<string> numbers;
    for(int i = 0;i<10;i++){
        char c;
        cin >> c;
        num_order[c] = i;
    }
    cin >> N;
    for(int i = 0;i<N;i++){
        string s;
        cin >> s;
        numbers.push_back(s);
    }

    sort(numbers.begin(),numbers.end(),[&num_order](string &x,string &y)->bool{
        if (x.size() == y.size()){
            for(int i = 0;i <x.size();i++){
                if(x[i] != y[i]){
                    return num_order[x[i]] < num_order[y[i]];
                }
            }
            return false;
        }else{
            return x.size() < y.size();
        }
    });

    // for(int i = 0;i<N;i++){
    //     cout << numbers[i] << endl;
    // }
    for(auto s :numbers){
        cout << s << endl;
    }
    return 0;
}