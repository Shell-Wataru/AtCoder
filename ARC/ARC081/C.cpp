#include<iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>

using namespace std;

int main()
{
    // 整数の入力
    long long N,ai,i,bar1,bar2;
    set<long long> bars;
    bar1 = 0;
    bar2 = 0;
    cin >> N;
    for (i= 0;i<N;i++){
        cin >> ai;
        if(bars.count(ai) > 0){
            bars.erase(ai);
            if (ai > bar1){
                bar2 = bar1;
                bar1 = ai;
            }else if(ai > bar2){
                bar2 = ai;
            }
        }else{
            bars.insert(ai);
        }
    }

    cout << bar1*bar2 << endl;
    return 0;
}