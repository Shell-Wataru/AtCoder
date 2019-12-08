#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <map>

using namespace std;
using ll = long long;
ll BASE_NUM = 1000000007;

int main()
{
    ll N;
    cin >> N;
    for(int i =0;i<N;i++){
        string s,t;
        set<char> schars,tchars;
        cin >> s >> t;
        for(auto sc:s){
            schars.insert(sc);
        }
        for(auto tc:t){
            tchars.insert(tc);
        }
        bool has_same = false;
        for(auto sc:schars){
            if(tchars.find(sc) != tchars.end()){
                has_same = true;
                break;
            }
        }
        if(has_same){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
   return 0;
}