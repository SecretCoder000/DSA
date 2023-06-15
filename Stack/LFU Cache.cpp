struct List {
    int val,key;
    List *right;
    List *left;
    List() : val(0),key(-1), right(nullptr) , left(nullptr) {}
    List(int x,int y) : key(x),val(y), right(nullptr) , left(nullptr) {}
};
class LRUCache {
    List *start,*end;
    int size;
public:
    LRUCache() {
        start = new List();
        end = new List();
        start->right = end;
        end->left = start;
        size = 0;
    }
    void remove(List * node){
        --size;
        List * left = node->left;
        List * right = node->right;
        left->right = right;
        right->left = left;
    }
    int popBack(){
        --size;
        List * target = end->left;
        List * prev = target->left;
        prev->right = end;
        end->left = prev;
        int ans = target->key;
        delete target;
        return ans;
    }

    void put(List * node) {
        ++size;
        List * right = start->right;
        right->left = node;
        node->right = right;
        node->left = start;
        start->right = node;
    }
    bool isEmpty(){
        return size == 0;
    }
};
class LFUCache {
    map<int,LRUCache*> freqList;
    map<int,pair<int,List*>> keyNode;
    int cap;
public:
    LFUCache(int capacity){
        cap=capacity;
    }                           //1,10
    int get(int key){
        auto itr = keyNode.find(key);
        if(itr == keyNode.end()){
            return -1;
        }
        else {
            int currFreq = itr->second.first;
            List * node = itr->second.second;
            int ans = node->val;
            freqList[currFreq]->remove(node);
            if(freqList[currFreq]->isEmpty())
                freqList.erase(currFreq);
            if(freqList.find(currFreq+1) == freqList.end()){
                LRUCache * lru = new LRUCache();
                freqList[currFreq+1] = lru;
            }
            freqList[currFreq+1]->put(node);
            keyNode[key].first = currFreq+1;
            return  ans;
        }
    }
    void put(int key,int value){
        if(keyNode.find(key) != keyNode.end()){
            auto node = keyNode.find(key);
            int currFreq = node->second.first;
            List * currNode = node->second.second;
            currNode->val = value;
            freqList[currFreq]->remove(currNode);
            if(freqList[currFreq]->isEmpty())
                freqList.erase(currFreq);
            if(freqList.find(currFreq+1) == freqList.end()){
                LRUCache * lru = new LRUCache();
                freqList[currFreq+1] = lru;
            }
            freqList[currFreq+1]->put(currNode);
            keyNode[key].first = currFreq+1;
        }else {
            if(cap == keyNode.size()){
                int rKey = freqList.begin()->second->popBack();
                keyNode.erase(rKey);
            }
            List * node = new List(key,value);
            if(freqList.find(1) == freqList.end()){
                LRUCache * lru = new LRUCache();
                freqList[1] = lru;
            }
            freqList[1]->put(node);
            keyNode[key] = {1,node};
        }
    }
};