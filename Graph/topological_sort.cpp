#include <iostream>
#include <vector>
#include <queue>
using namespace std;
 
bool TopSort(vector<vector<int>> &G, int n, vector<int> &inDegree) {
    /*
    *   param
    *   G：  邻接表
    *   n：  顶点数
    *   InDegree：   记录顶点的入度 
    拓扑排序步骤如下：
（1）定义一个队列Q，并把所有入度为0的结点加入队列
（2）取队首结点，访问输出，然后删除所有从它出发的边，并令这些边到达的顶点的入度减1，如果某个顶点的入度减为0，则将其加入队列。
（3）重复进行（2）操作，直到队列为空。如果队列为空时入过队的结点数恰好为N，说明拓扑排序成功，图G为有向无环图；否则，拓扑排序失败，图G有环。
    */

    int num = 0;                //记录加入拓扑排序的顶点数
    queue<int> q;
    for (int i = 0; i < n; i++)
        if (inDegree[i] == 0)
            q.push(i);      //将所有入度为0的顶点入队
    while (!q.empty()) {
        int u = q.front();      //取队首顶点u
        cout << u << " ";       
        q.pop();
        for (int i = 0; i < G[u].size(); i++) {
            int v = G[u][i];        //u的后继节点
            inDegree[v]--;          //v的入度减1
            if (inDegree[v] == 0)       //顶点v的入度减为0则入队
                q.push(v);
        }
        G[u].clear();           //清空顶点u的所有出边
        num++;
    }
    if (num == n)               //加入拓扑序列的顶点数为n，说明拓扑排序成功，否则，失败
        return true;
    else
        return false;
}
 
int main() {
    int n, m;
    cout << "请输入顶点数和边数:";
    cin >> n >> m;
    vector<vector<int>> G(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        cout << "请输入第" << i+1 << "条边的顶点:";
        cin >> x >> y;
        G[x].push_back(y);
    }
    cout << "拓扑排序为:";
    vector<int> inDegree(n);
    for (auto x : G) {
        for (auto y : x)
            inDegree[y]++;
    }
    bool res = TopSort(G, n, inDegree);

    return 0;
    
}