#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;
ll BASE_NUM = 1000000007;

int main()
{

    vector<string> base7_7 = {
            "...#.##",
            "###....",
            "###....",
            "....###",
            "###....",
            "...##.#",
            "...###."
        };
    vector<string> base7_9 = {
        "...#.##",
        "###....",
        "...##.#",
        "###....",
        "....###",
        "###....",
        "...###."
    };
    vector<string> base8_8 = {
        "....#.##",
        "#.##....",
        "##.#....",
        "###.....",
        ".....###",
        ".###....",
        "....##.#",
        "....###."
    };
    vector<string> base8_10 = {
        "....#.##",
        "#.##....",
        "##.#....",
        "....##.#",
        "###.....",
        ".....###",
        ".###....",
        "....###."
    };
    ll N;
    cin >> N;
    vector<string> S(N,string(N,'.'));
    if (N % 3 == 0){
        for(int i = 0;i < N;i++){
            for(int j = 0;j < 3;j++){
                S[i][(3*i+j)%N] = '#';
            }
        }
    }else if (N % 6 == 1){
        for(int i = 0;i < 7;i++){
            for(int j = 0;j < 7;j++){
                S[i][j] = base7_7[i][j];
            }
        }
        for(int i = 0;i < N-7;i++){
            for(int j = 0;j < 3;j++){
                S[i+7][(3*i+j) % (N-7) + 7] = '#';
            }
        }
    }else if (N % 6 == 2){
        for(int i = 0;i < 8;i++){
            for(int j = 0;j < 8;j++){
                S[i][j] = base8_8[i][j];
            }
        }
        for(int i = 0;i < N-8;i++){
            for(int j = 0;j < 3;j++){
                S[i+8][(3*i+j) % (N-8) + 8] = '#';
            }
        }
    }else if (N % 6 == 4){
        for(int i = 0;i < 3;i++){
            for(int j = 0;j < 3;j++){
                S[i][j] = '#';
            }
        }
        for(int i = 0;i < 7;i++){
            for(int j = 0;j < 7;j++){
                S[i+3][j+3] = base7_9[i][j];
            }
        }
        for(int i = 0;i < N-10;i++){
            for(int j = 0;j < 3;j++){
                S[i+10][(3*i+j) % (N-10) + 10] = '#';
            }
        }
    }else{
        for(int i = 0;i < 3;i++){
            for(int j = 0;j < 3;j++){
                S[i][j] = '#';
            }
        }
        for(int i = 0;i < 8;i++){
            for(int j = 0;j < 8;j++){
                S[i+3][j+3] = base8_10[i][j];
            }
        }
        for(int i = 0;i < N-11;i++){
            for(int j = 0;j < 3;j++){
                S[i+11][(3*i+j) % (N-11) + 11] = '#';
            }
        }
    }
    for(int i = 0;i < N;i++){
        cout << S[i] << "\n";
    }
    cout << endl;
    return 0;
}