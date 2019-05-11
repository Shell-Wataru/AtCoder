long long BASE_NUM = 1000000007;

long long extGCD(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long d = extGCD(b, a%b, y, x);
    y -= a/b * x;
    return d;
}

long long combination(long long n,long long m){
    long long value = 1;
    m = min(m,n-m);
    for (long long i = 0;i < m;i++){
        value = (value * (n - i)) % BASE_NUM;
    }

    for (long long i = 1;i <= m;i++){
        long long x,y,reverse;
        extGCD(i,BASE_NUM,x,y);
        reverse = (x + ((abs(x/BASE_NUM) + 1)* BASE_NUM) )% BASE_NUM;
        value = (value * reverse) % BASE_NUM;
    }
    return value;
}