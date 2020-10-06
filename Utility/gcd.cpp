#include <map>
#include <set>
#include <vector>
#include <iostream>

using ll = long long;
using namespace std;

long long gcd(long long a, long long b){

    if (a== 0){
        return b;
    }else if (b == 0){
        return a;
    }

    if (a%b == 0){
        return b;
    }else{
        return gcd(b,a%b);
    }
}

int main(){
    cout << gcd(12,8) << endl;
    cout << gcd(12,-6) << endl;
    return 0;
}

