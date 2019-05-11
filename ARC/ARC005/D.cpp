#include<iostream>
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

using namespace std;

string B;
long long P;
vector<long long> bs;
long long min_items[10];
long long BASE_NUM = 1000000007;

int main()
{
    // 整数の入力
    cin >> B >> P;
    for (int i = 0;i<10;i++){
        min_items[i] = 10;
    }

    for (int i = 0;i<B.size();i++){
        cout << B[i] - '0' << endl;
        bs.push_back(B[i] - '0');
        min_items[B[i] - '0'] = 1;
    }
    while(any_of(&min_items[0], &min_items[9], [](long long i){return i == 10;})){
        for (int i = 0;i<10;i++){
            for (int j = 0;j<bs.size();j++){
                if (min_items[(i)% 10] + 1 < min_items[(i + bs[j])% 10])
            }
        }
    }


    return 0;
}