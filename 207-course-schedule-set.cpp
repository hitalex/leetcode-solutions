#include <cstdlib>
#include <cassert>
#include <stack>
#include <vector>
#include <set>
#include <iostream>
#include <utility>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector< pair<int, int> >& prerequisites) {
        int i, j;
        // graph[i]为一个集合，该集合中存储所有i的前导课程
        vector< set<int> > graph;
        // 初始化graph数组为空
        for(i=0; i<numCourses; i++){
            graph.push_back(set<int>());
        }

        // 构建连接图
        for(i=0; i<prerequisites.size(); i++){
            pair<int, int> edge = prerequisites[i];
            int curr = edge.first;
            int pre = edge.second;

            if(graph[curr].find(pre) == graph[curr].end()){
                graph[curr].insert(pre);
            }
        }

        // 检查该拓扑图（链表）中是否有环
        // // 有向图的拓扑排序算法
        vector<int> deleted(numCourses, 0);
        stack<int> s;
        while(true){
            // 查找入度为0的节点
            for(i=0; i<numCourses; i++){
                // skip deleted nodes
                if(deleted[i] == 1)
                    continue;
                if(graph[i].size() == 0){
                    s.push(i);
                }
            }

            // 栈为空时，直接检查是否还存在未删除的节点
            if(s.empty())
                break;

            // 取出栈顶元素，删除该节点，并删除所有以其为出发点的边
            while(! s.empty()){
                int v = s.top(); s.pop();
                deleted[v] = 1;
                set<int>::iterator it;
                for(i=0; i<numCourses; i++){
                    it = graph[i].find(v);
                    if(it != graph[i].end()){
                        graph[i].erase(it);
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
