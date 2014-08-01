#include <iostream>
#include <map>
#include <limits>
#include <cstdlib>

using namespace std;

struct Node{
    int key;
    int val; // the value of a certain key
    int num; // how many times it is used recently
};

class LRUCache{
private:
    Node* a; // the array to store the values
    map<int, int> keymap; // key --> index in the array 'a'
    int capacity;
    
public:
    LRUCache(int capacity) {
        this->a = (Node*)malloc((capacity+1) * sizeof(Node));
        for(int i=1; i<=capacity; ++i){
            this->a[i].key = 0;
            this->a[i].val = 0;
            this->a[i].num = 0;
        }
        
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(this->keymap.find(key) == this->keymap.end()){ // the key does not exist
            return -1;
        }else{
            int index = this->keymap[key];
            this->a[index].num += 1;
            // rearrange the heap here if the array is full
            this->adjust_min_heap(index);
            return this->a[index].val;
        }
    }
    
    void set(int key, int value) {
        // find whether the key exists in the storage
        // always keep the heap sorted
        if(this->keymap.find(key) == this->keymap.end()){ // the key does not exist
            if(this->a[1].key <= 0){ // have a empty space
                ;
            }else{
                // the array reach its capacity
                int old_key = this->a[1].key;
                this->keymap.erase(old_key); // throw away the first element in heap
            }
            
            this->a[1].key = key;
            this->a[1].val = value;
            this->a[1].num = 1; // if it is set, then it is used one time
            //this->keymap[key] = 1;
            // re-arrange the heap
            adjust_min_heap(1);
            
        }else{
            int index = (this->keymap)[key];
            this->a[index].val = value; // replace the value
            this->a[index].num += 1;
        }
    }
    
    void print(){
        for(int i=1; i<=this->capacity; ++i){
            cout << "Key: " << this->a[i].key << "\tValue: " << this->a[i].val << "\tNum: " << this->a[i].num << endl;
        }
        cout << endl;
    }
    
    void print_keymap(){
        cout << "Keymap: " << endl;
        for (map<int,int>::iterator it=this->keymap.begin(); it!=this->keymap.end(); ++it)
            cout << it->first << " => " << it->second << '\n';
            
        cout << endl;
    }
    
private:
    void adjust_min_heap(int index){
        int lindex = index * 2; // left child index
        int rindex = index * 2 + 1; // right child index
        int lnum;
        int rnum;
        int num = this->a[index].num;
        
        if(lindex <= this->capacity){
            lnum = this->a[lindex].num;
        }else{
            this->keymap[this->a[index].key] = index;
            return ; // index is already a leafnode and has no child
        }
        
        if(rindex <= this->capacity){
            rnum = this->a[rindex].num;
        }else{
            rnum = numeric_limits<int>::max(); // set a dummy rnum, max int
        }
        
        if(lnum < num && lnum <= rnum){
            // switch with the left child
            if(this->a[lindex].key > 0){
                this->keymap[this->a[lindex].key] = index;
            }
            Node tmp = this->a[index];
            this->a[index] = this->a[lindex];
            this->a[lindex] = tmp;
            adjust_min_heap(lindex);
            
        }else if(rnum < num && rnum <= lnum){
            // switch with the right child
            if(this->a[rindex].key > 0){
                this->keymap[this->a[rindex].key] = index;
            }
            Node tmp = this->a[index];
            this->a[index] = this->a[rindex];
            this->a[rindex] = tmp;
            adjust_min_heap(rindex);
            
        }else{
            // do not switch and stop here
            if(this->a[index].key > 0){
                this->keymap[this->a[index].key] = index;
            }
        }
    }
};

int main(){
    LRUCache cache = LRUCache(2);
    
    cache.set(2, 1);
    cache.set(2, 2);
    cout << cache.get(2) << endl;
    cache.set(1, 1);
    cache.set(4, 1);
    cout << cache.get(2) << endl;
    
}
