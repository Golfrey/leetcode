/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 */

// @lc code=start
class LRUCache {
public:
    class node {
    public:
        int val, key;
        node *prev, *next;
        node() {}
        node(int key, int val) : val(val), key(key), prev(nullptr), next(nullptr) {}
    };

    void addToHead(int key) {
        node *tmp = head->next;
        head->next = umap[key];
        umap[key]->prev = head;
        umap[key]->next = tmp;
        tmp->prev = umap[key];
    }

    void removeKey(int key) {
        node *tmp1 = umap[key]->prev, *tmp2 = umap[key]->next;
        tmp1->next = tmp2;
        tmp2->prev = tmp1;
        //umap.erase(key);
    }

    void removeLast() {
        node* tmp = tail->prev;
        tmp->prev->next = tail;
        tail->prev = tmp->prev;
        umap.erase(tmp->key);
    }

    LRUCache(int capacity) {
        //cout << 1;
        this->size = 0;
        this->capacity = capacity;
        head = new node();
        tail = new node();
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        //cout << 2;
        if (umap.find(key) == umap.end())
            return -1;
        removeKey(key);
        addToHead(key);
        return umap[key]->val;
    }

    void put(int key, int value) {
        //cout << 3;
        if (umap.find(key) != umap.end()) {
            umap[key]->val = value;
            removeKey(key);
            addToHead(key);
        } else if (size < capacity) {
            node* p = new node(key, value);
            umap[key] = p;
            addToHead(key);
            size++;
        } else {
            removeLast();
            node* p = new node(key, value);
            umap[key] = p;
            addToHead(key);
        }
    }
private:
    unordered_map<int, node*> umap;
    int size, capacity;
    node *head, *tail;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

