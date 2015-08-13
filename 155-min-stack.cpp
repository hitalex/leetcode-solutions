#include <iostream>
#include <stack>
#include <climits>

using namespace std;

class MinStack {
private:
    stack<int> s1;
    stack<int> s2; // 记录最小值的历史

public:
    void push(int x) {
        if(s2.empty() || x < getMin()){
            s2.push(x);
        }
        s1.push(x);
    }

    void pop() {
        if(s1.top() == getMin()){
            s2.pop();
        }
        s1.pop();
    }

    int top() {
        return s1.top();
    }

    int getMin() {
        if(s2.empty())
            return INT_MAX;
        else
            return s2.top();
    }
};

int main(){
    MinStack ms;
    ms.push(-3);
    cout << ms.getMin() << endl;
    return 0;
}
