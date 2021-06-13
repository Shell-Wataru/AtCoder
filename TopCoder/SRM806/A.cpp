#include <string>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <bitset>
using namespace std;
using ll = long long;

class TransposeColors
{
public:
    vector<int> move(int N)
    {
        if (N == 1){
            return vector<int>(0);
        }
        vector<int> ans;
        for(int i = 1;i < N;i++){
            for(int j =0;j < i;j++){
                ans.push_back(N*j+i);
                ans.push_back(N*i+ (j+1) % i);
            }
        }
        ans.push_back(N*N);
        return ans;
    }
};

// int main()
// {
//     TransposeColors m;
//     vector<int> ans = m.move(3);
//     for(auto a:ans){
//         cout << a << endl;
//     }
//     return 0;
// }
