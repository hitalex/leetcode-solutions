#include <iostream>
#include <map>
#include <cstdlib>

using namespace std;

struct Node{
    int key;
    Node* next;
    Node* pre;
};

class LRUCache{
private:
    Node* head; // head of stack
    Node* tail;
    map<int, int> keymap;
    int capacity;
    int used;
    
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        this->used = 0;
        
        this->head = new Node;
        this->head->key = 0; // the dummy head
        this->head->next = NULL;
        this->head->pre = NULL;
    }
    
    int get(int key) {
        if(this->keymap.find(key) == this->keymap.end()){ // the key does not exist
            return -1;
        }else{
            int value = this->keymap[key];
            set_recent_access(key);
            return value;
        }
    }
    
    void set(int key, int value) {
        if(this->keymap.find(key) == this->keymap.end()){ // the key does not exist
            Node* p = new Node;
            p->key = key;
            
            if(this->used < this->capacity){
                this->used += 1;
                if(this->head->next == NULL){ // if the list is empty
                    this->tail = p;
                    this->tail->next = NULL;
                    this->tail->pre = this->head;
                    this->head->next = p;
                    this->keymap[key] = value;
                    return ;
                }
            }else{
                // reach the capacity
                int oldest_key = tail->key;
                this->keymap.erase(oldest_key);
                tail->pre->next = NULL; // remove the least recently used key
                
                Node* tmp = tail->pre;
                free(tail);
                tail = tmp;
            }
            
            // if list has at least one node, add this after head
            if(this->head->next == this->tail){ // only one node
                p->next = this->tail;
                p->pre = this->head;
                this->tail->pre = p;
                this->head->next = p;
                this->keymap[key] = value;
            }else{
                p->next = this->head->next;
                this->head->next = p;
                p->pre = this->head;
                this->keymap[key] = value;
            }
        }else{
            this->keymap[key] = value;
            set_recent_access(key);
        }
    }
    
    void set_recent_access(int key){
        // don't have to set when the list contains only one element
        if(this->used <= 1){
            return ;
        }
        // find the pos with key
        Node* p = this->head->next;
        Node* target = NULL;
        while(p != this->tail){ // assume the target node is not the tail
            if(p->key == key){
                target = p;
                break;
            }else{
                p = p->next;
            }
        }
        // if the target node is tail, we have to change the tail pointer
        if (p == this->tail){
            target = this->tail;
            this->tail = this->tail->pre;
            this->tail->next = NULL;
        }else{
            target->pre->next = target->next;
            target->next->pre = target->pre;
        }
        // insert target node after head
        target->next = this->head->next;
        target->pre = this->head;
        this->head->next->pre = target;
        this->head->next = target;
    }
    
    void print(){
        Node* p = head->next;
        while(p != NULL){
            cout << p->key << endl;
            p = p->next;
        }
        cout << endl;
    }
};

int main(){
    LRUCache cache = LRUCache(2);
    // [get(2),set(2,6),get(1),set(1,5),set(1,2),get(1),get(2)]
    
    cout << cache.get(2) << endl;
    cache.set(2, 6);
    cout << cache.get(1) << endl;
    cache.set(1, 5);
    cache.set(1, 2);
    cout << cache.get(1) << endl;
    cout << cache.get(2) << endl;
    
    //cache.print();

}
