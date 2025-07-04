#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
typedef long long LL;
LL l, r, v[N], prime[N], nprime[N];
inline void init(LL x) {
    for (int i = 2; i <= x; i ++) {
        if (!nprime[i]) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0] && i * prime[j] <= x; j ++) {
            nprime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}
int main() {
    cin >> l >> r;
    if (l == 1) l = 2;
    init(sqrt(r));
    for (int i = 1; i <= prime[0]; i ++) {
        LL p = prime[i];
        LL u = max(2 * p, ((l - 1) / p + 1) * p);
        for (LL j = u; j <= r; j += p) {
            v[j - l + 1] = 1;
        }
    }
    LL ans = 0;
    for (LL i = 1; i <= r - l + 1; i ++) {
        if (!v[i]) {
            ans ++;
        }
    }
    cout << ans << endl;
}