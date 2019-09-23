#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <ctime>
#include <map>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

struct Point{
    vector<ll> x;
};

int main()
{
    // 整数の入力
    long long N,D;
    vector<Point> points;
    set<ll> squares;
    cin >> N >> D;
    for(int i = 0;i<N;i++){
        Point p;
        for(int j = 0;j<D;j++){
            ll xj;
            cin >> xj;
            p.x.push_back(xj);
        }
        points.push_back(p);
    }

    for (int i = 0;i< 1000;i++){
        squares.insert(i*i);
    }

    ll counter = 0;
    for(int i = 0;i<N;i++){
        for(int j = i+1;j<N;j++){
            ll d = 0;
            for (int k = 0;k<D;k++){
                ll dd = (points[i].x[k] - points[j].x[k]);
                d += dd*dd;
            }
            if (squares.find(d) != squares.end()){
                counter++;
            }
        }
    }
    cout << counter << endl;

    return 0;
}