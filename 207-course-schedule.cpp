#include <cstdlib>
#include <cassert>
#include <stack>
#include <vector>
#include <utility>
#include <iostream>

using namespace std;

struct Node{
    int v;
    Node* next;
};

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int> >& prerequisites) {
        int i, j;
        // 节点i -> j 表示i是j的前导课程
        // graph[i]为一个邻接链表，该链表中存储所有i的前导课程
        Node** graph = (Node**)malloc(sizeof(Node*) * numCourses);

        // 初始化graph数组为空
        for(i=0; i<numCourses; i++){
            Node* head = new Node;
            head->v = -1;
            head->next = NULL;
            graph[i] = head;
        }

        // 构建连接图
        for(i=0; i<prerequisites.size(); i++){
            pair<int, int> edge = prerequisites[i];
            int curr = edge.first;
            int pre = edge.second;

            Node* p = new Node;
            p->v = pre;
            p->next = NULL;

            // curr -> pre, 表示pre是curr的先导课程
            // 将前导课程插入到链表中
            Node* pa = graph[curr];
            Node* q = pa->next;
            while(q != NULL && q->v != p->v){
                pa = q;
                q = q->next;
            }
            if(q == NULL){
                pa->next = p;
            }
        }

        // 检查该拓扑图（链表）中是否有环
        // // 有向图的拓扑排序算法
        int* deleted = (int*)malloc(sizeof(int) * numCourses); // 标记节点i是否已经被删除
        for(i=0; i<numCourses; i++)
            deleted[i] = 0;

        stack<int> s;
        while(true){
            // 查找入度为0的节点
            for(i=0; i<numCourses; i++){
                // 查找尚未被删除的，且入度为0的节点
                if(deleted[i] == 0 && graph[i]->next == NULL){
                    s.push(i);
                }
            }

            // 栈为空时，直接检查是否还存在未删除的节点
            if(s.empty())
                break;

            while(! s.empty()){
                // 取出栈顶元素，删除该节点，并删除所有以其为出发点的边
                int v = s.top(); s.pop();
                deleted[v] = 1;
                for(i=0; i<numCourses; i++){
                    Node* pa = graph[i];
                    Node* p = pa->next;
                    // 删除该链表中被删除的节点v
                    while(p != NULL){
                        if(p->v == v){
                            pa->next = p->next;
                            delete p;
                            break;
                        }else{
                            pa = p;
                            p = p->next;
                        }
                    }
                }
            }
        }

        // 检查是否还存在未删除的节点
        for(i=0; i<numCourses; i++){
            if(deleted[i] == 0)
                return false;
        }

        return true;
    }
};

int main(){
    Solution s;
    int numCourses = 3;
    pair<int, int> e1(1, 0);
    pair<int, int> e2(2, 0);
    vector<pair<int, int> > prerequisites;
    prerequisites.push_back(e1);
    prerequisites.push_back(e2);

    cout << s.canFinish(numCourses, prerequisites) << endl;
}
