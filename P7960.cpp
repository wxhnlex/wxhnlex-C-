#include<bits/stdc++.h>
using namespace std;
const int N = 1e7 + 10;
typedef long long LL;
bool v[N];
LL T, n, nx[N], c;
inline bool check (int x) {
    while (x) {
        if (x % 10 == 7) return true;
        x /= 10;
    }
    return false;
}
int main() {
    for (int i = 1; i < N; i ++) {
        if (v[i]) continue;
        if (check(i)) {
            v[i] = 1;
            for (int j = i; j * i < N; j ++) {
                v[j * i] = 1;
            }
            continue;
        }
        nx[c] = i; c = i;
    }
    cin >> T;
    while (T --) {
        cin >> n;
        if (v[n]) {
            puts("-1");
            continue;
        }
        cout << nx[n] << endl;
    }
}