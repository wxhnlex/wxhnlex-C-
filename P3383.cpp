#include<bits/stdc++.h>
using namespace std;
const int N = 1e8 + 10;
typedef long long LL;
LL n, q, prime[N], cnt = 0;
bool nprime[N];
inline LL read() {
    LL x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
inline void init(LL x) {
    for (LL i = 2; i <= x; i ++) {
        if (!nprime[i]) prime[++ cnt] = i;
        for (LL j = 1; j <= cnt && i * prime[j] <= x; j ++) {
            nprime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}
int main() {
    n = read(), q = read();
    init(n);
    while (q --) {
        LL x = read();
        cout << prime[x] << endl;
    }
}