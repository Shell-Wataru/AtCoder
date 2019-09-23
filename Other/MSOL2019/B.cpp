#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <ctime>

using namespace std;
using ll = long long;

int times(int number){
    if (number <= 5){
        return 0;
    }else if(number == 6 || number == 7){
        return 1;
    }else if(number == 8){
        return 2;
    }else if(number == 9){
        return 3;
    }else {
        return 0;
    }
}

int main()
{

    string s;
    ll k,wins;
    wins = 0;
    cin >> s;
    k = s.size();

    for (int i = 0;i< k;i++){
        if (s[i]=='o'){
            wins++;
        }
    }
    if((15 -k) + wins >=8 ){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }

    return 0;
}