#include <cstdlib>
#include <cassert>
#include <stack>
#include <vector>
#include <utility>
#include <iostream>
#include <fstream>

// 各个状态
#define WHITE 0
#define GREY 1
#define BLACK 2

using namespace std;

struct Node{
    int v;
    Node* next;
};

class Solution {
public:
    int* start; // staring time
    int* finish; // finishing time
    int* state; // 节点状态
    Node** graph; // the graph, 邻接表表示
    int time; // 计时
    int numCourses;
    bool flag;

    void read_graph(vector<pair<int, int> >& prerequisites){
        int i, j;
        // 节点i -> j 表示i是j的前导课程
        // graph[i]为一个邻接链表，该链表中存储所有i的前导课程
        graph = (Node**)malloc(sizeof(Node*) * numCourses);

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
            p->v = curr;
            p->next = NULL;

            // pre -> curr, 表示pre是curr的先导课程
            // 将前导课程插入到链表中
            Node* pa = graph[pre];
            Node* q = pa->next;
            while(q != NULL && q->v != p->v){
                pa = q;
                q = q->next;
            }
            if(q == NULL){
                pa->next = p;
            }
        }
    }

    void dfs(int nodei){
        //cout << "Visit: " << nodei << endl;
        start[nodei] = time ++ ;
        state[nodei] = GREY;

        Node* p = graph[nodei]->next;
        while(p && flag){
            if(state[p->v] == WHITE){
                dfs(p->v);
            }else if(state[p->v] == GREY){
                // 表明有反向边，即包含回路
                flag = false;
            }
            p = p->next;
        }
        state[nodei] = BLACK;
        finish[nodei] = time ++ ;
    }

    bool canFinish(int numCourses, vector<pair<int, int> >& prerequisites) {
        this->flag = true;
        this->numCourses = numCourses;
        read_graph(prerequisites);

        time = 1;
        start = (int*)malloc(sizeof(int) * numCourses);
        finish = (int*)malloc(sizeof(int) * numCourses);
        state = (int*)malloc(sizeof(int) * numCourses);
        for(int i=0; i<numCourses; i++){
            state[i] = WHITE;
        }

        int i;
        for(i=0; i<numCourses && flag; i++){
            if(state[i] == WHITE){
                dfs(i);
            }
        }

        return flag;
    }
};

int main(){
    Solution s;
    fstream f("graph-input.txt", fstream::in);
    int numCourses;
    vector<pair<int, int> > prerequisites;

    f >> numCourses;
    int v1, v2;
    while(f >> v1 >> v2){
        pair<int, int> e(v2, v1);
        prerequisites.push_back(e);
        //cout << v1 << "->" << v2 << endl;
    }
    f.close();

    cout << s.canFinish(numCourses, prerequisites) << endl;
}
