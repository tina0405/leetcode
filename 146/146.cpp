//g++ -std=c++11 146.cpp -o 146
#include<iostream>
#include<string>
#include<unordered_map>
#include<list>
using namespace std;
class LRUCache {
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(hashmap.find(key) == hashmap.end()){ /*Not find*/
            return -1;
        }else{
            put(key, hashmap[key]->second);
            return hashmap[key]->second;

        }
        
    }
    
    void put(int key, int value) {

        
        if(hashmap.find(key) == hashmap.end()){  /*Not find*/
            if(capacity>0){ /*Add element*/ 
                key_cont.push_front({key,value});
                hashmap[key] = key_cont.begin();
                capacity--;
                
            }else{ /*Delete last element, and add the op*/
               
                key_cont.push_front({key,value});
                hashmap[key] = key_cont.begin();
                hashmap.erase(key_cont.back().first);
                key_cont.pop_back();
    
            }
        }else{
            key_cont.erase(hashmap[key]);
            key_cont.push_front({key,value});
            hashmap[key] = key_cont.begin();
        }   
        
    }
private:
    int capacity;
    unordered_map<int, list<pair<int, int>>::iterator> hashmap;
    list<pair<int, int>> key_cont;
    //vector<int> key_cont;
};

int main(void){
	LRUCache cache(2);
	cache.put(1, 1);
	cache.put(2, 2);
	cout << cache.get(1) << endl;
	cache.put(3, 3);    // evicts key 2
	cout << cache.get(2) << endl;       // returns -1 (not found)
	cache.put(4, 4);    // evicts key 1
	cout << cache.get(1) << endl;       // returns -1 (not found)
	cout << cache.get(3) << endl;       // returns 3
	cout << cache.get(4) << endl;       // returns 4
	return 0;
}
