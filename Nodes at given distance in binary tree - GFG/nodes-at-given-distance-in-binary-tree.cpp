//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


// } Driver Code Ends
/* A binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
*/

class Solution
{
private:
Node* preorder(Node* root,int target){
        if(!root) return NULL;
        if(root->data==target) return root;
            
        Node* tmp=preorder(root->left,target);
        if(!tmp) tmp=preorder(root->right,target);
        return tmp;
        
    }
    void findParent(Node*root,unordered_map<Node*,Node*>&parent_track)
    {
        queue<Node*>q;
        q.push(root);
        bool flag=1;
        while(!q.empty())
        {
            Node*temp=q.front();
            q.pop();
            if(temp->left){
                parent_track[temp->left]=temp;
                q.push(temp->left);
            }
            if(temp->right){
                parent_track[temp->right]=temp;
                q.push(temp->right);
            }
        }
    }

public:


    vector <int> KDistanceNodes(Node* root, int target , int k)
    {
        // return the sorted vector of all nodes at k dist
            unordered_map<Node*,Node*>parent_track;
        Node* target1=preorder(root,target);
        findParent(root,parent_track);
        unordered_map<Node*, bool>visited;
        queue<Node*>q;
        q.push(target1);
        visited[target1] =true;
        
        while(!q.empty() and k)
        {
            int n=q.size();
            k--;
            for(int i=0;i<n;i++)
            {
                Node*temp=q.front();
                q.pop();
                if(temp->left and !visited[temp->left]){
                    visited[temp->left]=true;
                    q.push(temp->left);
                }
                if(temp->right and !visited[temp->right])
                {
                    visited[temp->right]=true;
                    q.push(temp->right);
                }
                if(parent_track[temp] and !visited[parent_track[temp]])
                {
                    visited[parent_track[temp]]=true;
                    q.push(parent_track[temp]);
                }
            }
            
        }
        vector<int>v;
        while(!q.empty())
        {
            v.push_back(q.front()->data);
            q.pop();
        }
        sort(v.begin(), v.end());
        return v;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    getchar();
    
    Solution x = Solution();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* head = buildTree(s);
        
        int target, k;
        cin>> target >> k;
        getchar();
        
        vector <int> res = x.KDistanceNodes(head, target, k);
        
        for( int i=0; i<res.size(); i++ )
            cout<< res[i] << " ";
        cout<<endl;
    }
    return 0;
}

// } Driver Code Ends