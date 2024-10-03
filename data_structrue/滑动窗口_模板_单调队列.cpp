#include<bits/stdc++.h>
using namespace std;
const int N = 1000005;
int a[N];
deque<int> q;
int main() {
    int n, m; scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) {
        while (!q.empty() && a[q.back()] > a[i]) q.pop_back(); // 原队尾破环单调性，弹出
        q.push_back(i);
        if (i >= m) {   // 每个窗口输出一次
            while(!q.empty() && q.front() <= i - m) q.pop_front(); // 队头元素脱离窗口，弹出
            printf("%d ", a[q.front()]);
        }
    }
    printf("\n");
    q.clear();
    for (int i = 1; i <= n; i ++) {
        while (!q.empty() && a[q.back()] < a[i]) q.pop_back();
        q.push_back(i);
        if (i >= m){
            while (!q.empty() && q.front() <= i - m) q.pop_front();
            printf("%d ", a[q.front()]);
        }
    }
    return 0;
}