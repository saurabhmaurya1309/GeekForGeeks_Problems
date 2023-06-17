//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int distributeTicket(int N, int K) {
        bool f=false;
        int temp=K;
        int ans=1;
        int ans1=N;
        while(N!=0){
            if(f){
                while(K!=0&&N!=0){
                   ans1--;
                   K--;
                   N--;
                }
                f=false;
                K=temp;
            }
            else{
                while(K!=0&&N!=0){
                    ans++;
                    K--;
                    N--;
                }
                f=true;
                 K=temp;
            }
        }
        if(f){
            return ans1;
        }
        return ans;
    }
    
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int K;
        scanf("%d",&K);
        
        Solution obj;
        int res = obj.distributeTicket(N, K);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends