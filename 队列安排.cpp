#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int e[N], idx, n, m, r[N], l[N];
bool st[N];

void init() {
    r[0] = 1, l[1] = 0, idx = 2;
}
void add(int k, int x) {
    e[idx] = x;
    l[idx] = k, r[idx] = r[k];
    l[r[k]] = idx, r[k] = idx++;
}
int main() {
    init();
    scanf("%d", &n);
    add(0, 1);
    for (int i = 2; i <= n; i++) {
        int k, p;
        scanf("%d%d", &k, &p);
        if(p) {
            add(k + 1, i);
        }
        else {
            add(l[k + 1], i);
        }
    }
    scanf("%d", &m);
    while (m--) {
        int d;
        scanf("%d", &d);
        st[d] = true;
    }
    for(int i = r[0]; i != 1; i = r[i]) {
        if(!st[e[i]]) printf("%d ", e[i]);
    }
    return 0;
}