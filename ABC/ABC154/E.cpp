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
#include <set>
using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;
ll BASE_NUM = 1000000007;

int main()
{
    // 整数の入力
    string N;
    ll K;
    cin >> N >> K;

    string base = "";
    for(int i = 0;i< N.length();i++){
        base.push_back('0');
    }
    ll ans = 0;
    if (K == 1){
        for(int i = 0;i< N.length();i++){
            for(int i_num = 1;i_num < 10;i_num++){
                base[i] = (char) ('0' + i_num);
                if (base <= N){
                    ans++;
                }
                base[i] = '0';
            }
        }
    }else if (K == 2){
        for(int i = 0;i< N.length();i++){
            for(int i_num = 1;i_num < 10;i_num++){
                base[i] = (char) ('0' + i_num);
                for(int j = i+1;j< N.length();j++){
                    for(int j_num = 1;j_num < 10;j_num++){
                        base[j] = (char) ('0' + j_num);
                        if (base <= N){
                            ans++;
                        }
                        base[j] = '0';
                    }
                }

                base[i] = '0';
            }
        }
    }else{
        for(int i = 0;i< N.length();i++){
            for(int i_num = 1;i_num < 10;i_num++){
                base[i] = (char) ('0' + i_num);
                for(int j = i+1;j< N.length();j++){
                    for(int j_num = 1;j_num < 10;j_num++){
                        base[j] = (char) ('0' + j_num);

                        for(int k = j+1;k< N.length();k++){
                            for(int k_num = 1;k_num < 10;k_num++){
                                base[k] = (char) ('0' + k_num);
                                if (base <= N){
                                    ans++;
                                }
                                base[k] = '0';
                            }
                        }

                        base[j] = '0';
                    }
                }

                base[i] = '0';
            }
        }
    }
    cout << ans << endl;
    return 0;
}
