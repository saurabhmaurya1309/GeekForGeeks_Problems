//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int Count(string S);


int main(){
    int t;
    cin >> t;
    while(t--){
        string S;
        cin >> S;
        cout << Count(S) << endl;
    }
return 0;
}


// } Driver Code Ends


int Count(string S){
   int ans=0;
   int n=S.length();
   for(int i=0;i<n;i++){
       if((S[i]>='a'&&S[i]<='z')||(S[i]>='A'&&S[i]<='Z')){
           ans++;
       }
   }
   return ans;
}