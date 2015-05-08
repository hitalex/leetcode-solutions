#include <cstdlib>
#include <cassert>
#include <stack>
#include <vector>


using namespace std;

struct Node{
    int v;
    Node* next;
};

class Solution {
public:
    bool canFinish(int numCourses, vector< vector<int> >& prerequisites) {
        int i, j;
        // 节点i -> j 表示i是j的前导课程
        // graph[i]为一个链表，该链表中存储所有i的前导课程
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
            int curr = prerequisites[i][0];
            int pre = prerequisites[i][1];
            
            Node* p = new Node;
            p->v = pre;
            p->next = NULL;
            
            // 将前导课程插入到链表中
            p->next = graph[curr]->next;
            graph[curr]->next = p;
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
                // skip deleted nodes
                if(deleted[i] == 1)
                    continue;
                if(graph[i]->next == NULL){
                    s.push(i);
                }
            }
            
            // 栈为空时，直接检查是否还存在未删除的节点
            if(s.empty())
                break;
            
            // 取出栈顶元素，删除该节点，并删除所有以其为出发点的边
            int v = s.top(); s.pop();
            deleted[v] = 1;
            for(i=0; i<numCourses; i++){
                Node* p = graph[i];
                Node* q = p->next;
                // 删除该链表中被删除的节点v
                while(q != NULL){
                    if(q->v == v){
                        p->next = q->next;
                        delete q;
                        q = p->next;
                    }else{
                        p = q;
                        q = p->next;
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
