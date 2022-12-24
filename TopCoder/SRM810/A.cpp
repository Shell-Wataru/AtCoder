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

class WordleColors
{
public:
    string color(string hidden,string guess)
    {
        string ret(5,'-');
        map<char,ll> counts;
        for(int i = 0;i < 5;i++){
            counts[hidden[i]]++;
        }

        for(int i = 0;i < 5;i++){
            if (hidden[i] == guess[i]){
                ret[i] = 'g';
                counts[hidden[i]]--;
            }
        }
        for(int i = 0;i < 5;i++){
            if (hidden[i] != guess[i]){
                if (counts[guess[i]] > 0){
                    ret[i] = 'y';
                    counts[guess[i]]--;
                }

            }
        }
        return ret;
    }
};

// int main()
// {
//     WordleColors m;
//     // cout << m.color("ABBOT","BOBBY") << endl;
//     cout << m.color("CANAL","AAAAA") << endl;
//     return 0;
// }
