#include <iostream>
using namespace std;
const int N = 100010;
int e[N], l[N], r[N],index = 0;

void init()
{
    //如下初始化导致第 a 个插入的元素的索引为： a + 1
    l[1] = 0;
    r[0] = 1;
    index = 2;
} 

// 在索引为 a 的右侧插入x，对应第 a - 1 个插入元素右侧插入 x
void insert(int a, int x)
{
    e[index] = x;
    l[index] = a;
    r[index] = r[a];
    l[r[a]] = index;
    r[a] = index++;
}

//删除索引为 a 的元素，对应于删除第 a - 1 个插入元素。
void remove(int a)
{
    r[l[a]] = r[a];
    l[r[a]] = l[a];
}

int main()
{
    init();
    int m;
    cin>>m;
    while(m--)
    {
        string op;
        cin >> op;
        int k, x;
        if(op == "L")
        {
            cin >> x;
            insert(0, x);
        }
        else if(op == "R")
        {
            cin >> x;
            insert(l[1], x);
        }
        else if (op == "D")
        {
            cin >> k;
            remove(k + 1);//第 k 个插入元素对应的索引为 k + 1
        }
        else if (op == "IL")
        {
            cin >> k >> x;
            insert(l[k + 1], x);// 第 k 个插入元素对应的索引为 k + 1， l[k + 1] 为链表中上一个位置对应的索引
        }
        else
        {
            cin >> k >> x;
            insert(k + 1, x);//第 k 个插入元素对应的索引为 k + 1
        }
    }
    for (int i = r[0]; i != 1; i = r[i]) cout << e[i] << ' ';
    cout << endl;

    return 0;

}
