#include <iostream>
#include <map>
#include <cstdlib>

using namespace std;

class LRUCache{
private:
	int* keys;
	map<int, int> keymap;
	int capacity;
	int used;

public:
	LRUCache(int capacity) {
		this->capacity = capacity;
		this->used = 0;
		this->keys = (int*)malloc(capacity * sizeof(int));
		for (int i = 0; i < capacity; ++i){
			keys[i] = 0;
		}
	}

	int get(int key) {
		if (this->keymap.find(key) == this->keymap.end()){ // the key does not exist
			return -1;
		}
		else{
			int value = this->keymap[key];
			set_recent_access(key, -1);
			return value;
		}
	}

	void set(int key, int value) {
		if (this->keymap.find(key) == this->keymap.end()){ // the key does not exist
			if (this->used < this->capacity){
				int index = this->used;
				this->used += 1;
				this->keymap[key] = value;
				set_recent_access(key, index);
			}
			else{
				// reach the capacity
				int oldest_key = this->keys[this->capacity - 1];
				// invalidate the oldest key
				this->keymap.erase(oldest_key);
				this->keymap[key] = value;
				set_recent_access(key, this->capacity - 1);
			}
			
		}
		else{
			this->keymap[key] = value;
			set_recent_access(key, -1);
		}
	}

	void set_recent_access(int key, int last){
		// find the pos for key
		if (last < 0){
			for (int i = 0; i < this->capacity; ++i){
				if (this->keys[i] == key){
					last = i;
					break;
				}
			}
		}
		// re-arrange the elements one step to the right
		for (int i = last; i > 0; --i){
			this->keys[i] = this->keys[i-1];
		}

		this->keys[0] = key;
	}

	void print(){
		for (int i = 0; i < this->capacity; ++i){
			cout << this->keys[i] << endl;
		}
		cout << endl;
	}
};

int main(){
	LRUCache cache = LRUCache(1);
	// [get(2),set(2,6),get(1),set(1,5),set(1,2),get(1),get(2)]

	cache.set(2, 1);
	cout << cache.get(2) << endl;
	cache.set(3, 2);
	cout << cache.get(2) << endl;
	cout << cache.get(3) << endl;
	

	//cache.print();

}
