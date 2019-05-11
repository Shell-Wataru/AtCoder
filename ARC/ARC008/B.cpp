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
    string name,kit;

    map<char,long long> name_bag,kit_bag;
    long long current = 0;

    cin >> N >> M;
    cin >> name;
    cin >> kit;
    for(int i = 0; i< name.size();i++){
        char n = name[i];
        name_bag[n]++;
    }
    for(int i = 0; i< kit.size();i++){
        char k = kit[i];
        kit_bag[k]++;
    }

    ll max_bags = -1;
    for(auto p: name_bag){
        if (kit_bag[p.first] == 0){
            cout << -1 << endl;
            return 0;
        }else {
            ll need = (p.second + kit_bag[p.first] - 1)/kit_bag[p.first];
            if (need > max_bags){
                max_bags = need;
            }
        }
    }
    cout << max_bags << endl;
    return 0;
}