//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
};

void print(struct Node *Node)
{
    while (Node!=NULL)
    {
        cout << Node->data << " ";
        Node = Node->next;
    }
}


Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}


// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
};

*/
class Solution
{
    public:
    struct Node* reverse(Node* &head){
        if(!head or !head->next) return head;
        
        Node* prev = nullptr;
        Node* curr = head;
        
        while(curr != nullptr){
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
     struct Node * mergeResult(Node *node1, Node *node2)
    {
        if(!node1) return reverse(node2);
        if(!node2) return reverse(node1);
        Node* head1 = node1;
        Node* head2 = node2;
        
        Node* ptr1 = head1;
        Node* ptr2 = head2;
        
        // Node* temp = nullptr;
        Node* head = nullptr;
        if(ptr1->data < ptr2->data){
            head = ptr1;
            ptr1 = ptr1->next;
            
        }
        else{
            head = ptr2;
            ptr2 = ptr2->next;
        }
        head->next = nullptr;
        Node* ptr = head;
        while(ptr1 != nullptr && ptr2 != nullptr){
            if(ptr1->data > ptr2->data){
                ptr->next = ptr2;
                ptr2 = ptr2->next;
            }
            else{
                ptr->next = ptr1;
                ptr1 = ptr1->next;
            }
            // cout<<ptr->data<<" ";
            ptr = ptr->next;
            ptr->next = nullptr;
        }
        // cout<<endl;
        
        while(ptr1 != nullptr){
            ptr->next = ptr1;
            ptr1 = ptr1->next;
            ptr = ptr->next;
            ptr->next = nullptr;
        }
        
        while(ptr2 != nullptr){
            ptr->next = ptr2;
            ptr2 = ptr2->next;
            ptr = ptr->next;
            ptr->next = nullptr;
        }
        
        return reverse(head);
    }  
};


//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int nA;
        cin>>nA;
        int nB;
        cin>>nB;

        struct Node* headA=NULL;
        struct Node* tempA = headA;

        for(int i=0;i<nA;i++)
        {
            int ele;
            cin>>ele;
            if(headA==NULL)
            {
                headA=tempA=newNode(ele);

            }else{
                tempA->next = newNode(ele);
				tempA=tempA->next;
            }
        }

        struct Node* headB=NULL;
        struct Node* tempB = headB;


        for(int i=0;i<nB;i++)
        {
            int ele;
            cin>>ele;
            if(headB==NULL)
            {
                headB=tempB=newNode(ele);

            }else{
                tempB->next = newNode(ele);
				tempB=tempB->next;
            }
        }
        
        Solution ob;
        struct Node* result = ob.mergeResult(headA,headB);

        print(result);
        cout<<endl;


    }
}

// } Driver Code Ends