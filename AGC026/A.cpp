#include<iostream>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;


int main()
{
    // 整数の入力
    long long  N,continue_count,last_color,current_color,total_change;
    last_color = -1;
    continue_count = 0;
    total_change = 0;
    cin >> N;
    for (int i=0;i< N;i++){
        cin >> current_color;
        if (current_color == last_color){
            continue_count++;
        }else{
            total_change += continue_count/2;
            continue_count = 1;
        }
        last_color = current_color;
    }
    total_change += continue_count/2;
    cout << total_change << endl;
    return 0;
}