class LRUCache {
public:
    class Node{
        public:
        int key,val;
        Node*next;
        Node*prev;
        Node(int _key,int _val){
            key=_key;
            val=_val;
        }
    };
    int cap;
    unordered_map<int,Node*>mpp;
    Node*head=new Node(-1,-1);
    Node*tail=new Node(-1,-1);
    LRUCache(int capacity) {
        cap=capacity;
        while(!mpp.empty()){
            mpp.erase(mpp.begin());
        }
        head->next=tail;
        tail->prev=head;
    }
    void deletenode(Node*temp){
        Node*dprev=temp->prev;
        Node*dnext=temp->next;
        dprev->next=dnext;
        dnext->prev=dprev;
    }
    void insertnode(Node*temp){
        Node*inext=head->next;
        temp->next=inext;
        inext->prev=temp;
        temp->prev=head;
        head->next=temp;
    }
    
    int get(int key) {
        if(mpp.find(key)!=mpp.end()){
            Node*res=mpp[key];
            int rval=res->val;
            deletenode(res);
            insertnode(res);
            return rval;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mpp.find(key)!=mpp.end()){
            Node*temp=mpp[key];
            mpp.erase(key);
            deletenode(temp);
        }
       else if(mpp.size()==cap){
            mpp.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        insertnode(new Node(key,value));
        mpp[key]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */