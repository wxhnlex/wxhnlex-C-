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
    while (cin >> l >> r) {
        memset(v, 0, sizeof(v));
        memset(prime, 0, sizeof(prime));
        memset(nprime, 0, sizeof(nprime));
        if (l == 1) l = 2;
        init(sqrt(r));
        for (int i = 1; i <= prime[0]; i ++) {
            LL p = prime[i];
            LL u = max(2 * p, ((l - 1) / p + 1) * p);
            for (LL j = u; j <= r; j += p) {
                v[j - l + 1] = 1;
            }
        }
        vector<LL> lex;
        for (int i = 1; i <= r - l + 1; i ++) {
            if (!v[i]) {
                lex.push_back(i + l - 1);
            }
        }
        if (lex.size() <= 1) {
            puts("There are no adjacent primes.");
        } else {
            LL maxx = -1e9, minn = 1e9;
            LL q, w, e, t;
            for (int i = 1; i < lex.size(); i ++) {
                if (lex[i] - lex[i - 1] > maxx) {
                    maxx = lex[i] - lex[i - 1];
                    q = lex[i - 1], w = lex[i];
                }
                if (lex[i] - lex[i - 1] < minn) {
                    minn = lex[i] - lex[i - 1];
                    e = lex[i - 1], t = lex[i];
                }
            }
            printf("%lld,%lld are closest, %lld,%lld are most distant.\n", e, t, q, w);
        }
    }   
    
}