struct List {
    int val,key;
    List *right;
    List *left;
    List() : val(0),key(-1), right(nullptr) , left(nullptr) {}
    List(int x,int y) : key(y),val(x), right(nullptr) , left(nullptr) {}
};
class LRUCache {
    List *start,*end;
    map<int,List*> temp;
    int cap;
public:
    LRUCache(int capacity) {
        cap = capacity;
        start = new List();
        end = new List();
        start->right = end;
        end->left = start;
    }

    int get(int key) {
        if(temp.find(key) == temp.end())
            return -1;
        List * prev = temp[key];
        List * left = prev->left;
        List * right = prev->right;
        left->right = right;
        right->left = left;
        prev->left = start;
        prev->right = start->right;
        prev->right->left = prev;
        start->right = prev;
        return prev->val;
    }

    void put(int key, int value) {
        if(temp.find(key) == temp.end()){
            if(cap == temp.size()){
                List *prev = end->left->left;
                List * target = end->left;
                temp.erase(target->key);
                end->left = prev;
                prev->right = end;
                prev = new List(value,key);
                prev->left = start;
                prev->right = start->right;
                prev->right->left = prev;
                start->right = prev;
                temp[key] = prev;
            } else {
                List * prev = new List(value,key);
                prev->left = start;
                prev->right = start->right;
                prev->right->left = prev;
                start->right = prev;
                temp[key] = prev;
            }
        }else {
            List * prev = temp[key];
            List * left = prev->left;
            List * right = prev->right;
            left->right = right;
            right->left = left;
            prev->val = value;
            prev->left = start;
            prev->right = start->right;
            prev->right->left = prev;
            start->right = prev;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */