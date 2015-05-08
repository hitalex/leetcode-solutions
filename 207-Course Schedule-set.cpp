#include <cstdlib>
#include <cassert>
#include <stack>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector< vector<int> >& prerequisites) {
        int i, j;
        // graph[i]为一个集合，该集合中存储所有i的前导课程
        set<int>* graph = (set<int>*)malloc(sizeof(set<int>) * numCourses);
        int* indegree = (int*)malloc(sizeof(int) * numCourses);
        // 初始化graph数组为空
        for(i=0; i<numCourses; i++){
            graph[i] = set<int>();
            indegree[i] = 0;
        }
        
        // 构建连接图
        for(i=0; i<prerequisites.size(); i++){
            int curr = prerequisites[i][0];
            int pre = prerequisites[i][1];
            
            graph[curr].insert(pre);
            indegree[curr] += 1;
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
                if(graph[i].size() == 0){
                    s.push(i);
                }
            }
            
            // 栈为空时，直接检查是否还存在未删除的节点
            if(s.empty())
                break;
            
            // 取出栈顶元素，删除该节点，并删除所有以其为出发点的边
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
        
        // 检查是否还存在未删除的节点
        for(i=0; i<numCourses; i++){
            if(deleted[i] == 0)
                return false;
        }
        
        return true;
    }
};


int main(){
    cout << "Starting program..." << endl;
    Solution solution = Solution();
    
    int numCourses = 3;
    vector< vector<int> > prerequisites;
    // 创建连接
    vector<int> link;
    link.push_back(1); link.push_back(0); prerequisites.push_back(link);
    
    link.clear();
    link.push_back(2); link.push_back(0); prerequisites.push_back(link);
    
    link.clear();
    
    link.push_back(0); link.push_back(1); prerequisites.push_back(link);
    
    int i, j;
    for(i=0; i<prerequisites.size(); i++){
        link = prerequisites[i];
        cout << link[0] << "->" << link[1] << endl;
    }
    
    cout << solution.canFinish(numCourses, prerequisites) << endl;
    
    
    return 1;
}
