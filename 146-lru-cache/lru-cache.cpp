class LRUCache {
public:
    class Node {
    public:
        int key;
        int val;
        Node* next;
        Node* prev;
        // Constructor to initialize node
        Node(int k, int v) {
            key = k;
            val = v;
            next=NULL;
            prev=NULL;
        }
    };
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    // Capacity of cache
    int cap;
    // Hash map to store key-node mapping
    unordered_map<int, Node*> mp;

    LRUCache(int capacity) {
        cap=capacity;
        head->next = tail;
        tail->prev = head;
    }
    void addNode(Node* newNode) {
        Node* temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        head->next = newNode;
        temp->prev = newNode;
    }
    void deleteNode(Node* delNode) {
        Node* delPrev = delNode->prev;
        Node* delNext = delNode->next;
        delPrev->next = delNext;
        delNext->prev = delPrev;
    }
    int get(int key) {
        if(mp.find(key) == mp.end())
            return -1;

        Node* node = mp[key];

        deleteNode(node);
        addNode(node);

        return node->val;
    }
    
    void put(int key, int value) {
        // Case 1 : Key already exists
        if(mp.find(key)!=mp.end()){
            Node* node=mp[key];
            node->val=value;
            deleteNode(node);
            addNode(node);
        }
        // Case 2 : New key
        else{
            Node* node=new Node(key,value);
            // If cache is already full,remove the Least Recently Used node.
            if(mp.size()==cap){
                Node* lru = tail->prev;
                mp.erase(lru->key);
                deleteNode(lru);
                delete lru;
            }
            addNode(node);
            mp[key]=node;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */