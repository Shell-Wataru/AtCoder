#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <ctime>
#include <map>
#include <boost/multiprecision/cpp_int.hpp>
#include <string>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;


int main()
{
    // 整数の入力
    ll N;
    cin >> N;
    vector<ll> H(N);
    vector<ll> dekoboko;
    for (size_t i = 0; i < N; i++)
    {
        scanf("%lld",&H[i]);
    }
    for(int i = 0;i < N;i++){
        if (i == 0 || i == N-1){
            dekoboko.push_back(i);
        }else{
            if (H[i-1] < H[i] && H[i] > H[i+1]){
                dekoboko.push_back(i);
            }else if(H[i-1] > H[i] && H[i] < H[i+1]){
                dekoboko.push_back(i);
            }
        }
    }
    // cout << dekoboko.size() << endl;
    // cout << dekoboko[0] << endl;
    // cout << dekoboko[1] << endl;
    if (H[0] > H[1]){
        ll max_size = 0;
        for(int i = 0;i < dekoboko.size();i++){
            if (i % 2 == 0){
                ll size = 1;
                if (i - 1 >= 0){
                    size += dekoboko[i] - dekoboko[i-1];
                }
                if (i + 1 < dekoboko.size()){
                    size += dekoboko[i+1] - dekoboko[i];
                }
                max_size = max(max_size,size);
            }
        }
        cout << max_size << endl;
    }else{
        ll max_size = 0;
        for(int i = 0;i < dekoboko.size();i++){
            if (i % 2 == 1){
                ll size = 1;
                if (i - 1 >= 0){
                    size += dekoboko[i] - dekoboko[i-1];
                }
                if (i + 1 < dekoboko.size()){
                    size += dekoboko[i+1] - dekoboko[i];
                }
                max_size = max(max_size,size);
            }
        }
        cout << max_size << endl;
    }

    return 0;
}