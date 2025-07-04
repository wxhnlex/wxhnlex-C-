#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
int pr[N], cnt = 0, n, ans[N];
bool st[N];

void brp(int x) {
    for (int i = 2; i <= x / i; i++) {
        while (x % i == 0) {
            ans[i]++;
            x /= i;
        }
    }
    if (x > 1) ans[x]++;
}

int main() {
    cin >> n;
    
    for (int i = 2; i <= n; i++) {
        if (!st[i]) pr[++cnt] = i;
        for (int j = 1; pr[j] * i <= n; j++) {
            st[pr[j] * i] = 1;
            if (i % pr[j] == 0) break;
        }
    }

    for (int i = 2; i <= n; i++) {
        if (!st[i]) ans[i]++;
        else brp(i);
    }

    for (int i = 2; i <= n; i++) {
        if (!st[i]) {
            cout << i << " " << ans[i] << endl;
        }
    }
    
    return 0;
}