#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int n, cnt = 0;
bool prime[N], nprime[N];
inline void init(int x) {
    for (int i = 2; i <= x; i ++) {
        if (!nprime[i]) prime[++ cnt] = i;
        for (int j = 1; j <= cnt && i * prime[j] <= x; j ++) {
            nprime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}
int main() {
    cin >> n;
    init(n+ 1);
    cout << 2 << endl;
    for (int i = 2; i <= n + 1; i ++) {
        if (!nprime[i]) cout << 2 << " ";
        else cout << 1 << " ";
    }
}