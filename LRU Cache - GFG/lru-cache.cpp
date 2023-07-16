//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Node{
    public:
    int key;
    int value;
    Node *next;
    Node *prev;
    
    Node(int k, int v){
        key = k;
        value = v;
        next = NULL;
        prev = NULL;
    }
};

class LRUCache
{
    public:
    unordered_map<int, Node*> map;
    int capacity, count;
    Node *head, *tail;
    //Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap)
    {
        capacity = cap;
        count = 0;
        head = new Node(0,0);
        tail = new Node(0,0);
        head->next = tail;
        tail->prev = head;
    }
    void deletenode(Node *curr){
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        delete curr;
    }
    
    void addtohead(Node *curr){
        curr->next = head->next;
        curr->prev = head;
        curr->next->prev = curr;
        head->next = curr;
    }
    
    //Function to return value corresponding to the key.
    int GET(int key)
    {
        if(map.find(key)!=map.end()){
            int res = map[key]->value;
            deletenode(map[key]);
            map[key] = new Node(key, res);
            addtohead(map[key]);
            return res;
        }
        else
            return -1;
    }
    
    //Function for storing key-value pair.
    void SET(int key, int value)
    {
        Node *curr=NULL;
        if(map.find(key)!=map.end()){
            
            deletenode(map[key]);
            map[key] = new Node(key,value);
            addtohead(map[key]);
        }
        
        else if(count==capacity){
            map[key] = new Node(key,value);
            addtohead(map[key]);
            map.erase(tail->prev->key);
            deletenode(tail->prev);
            
        }
        else{
            map[key] = new Node(key,value);
            addtohead(map[key]);
            count++;
        }
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->SET(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->GET(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends