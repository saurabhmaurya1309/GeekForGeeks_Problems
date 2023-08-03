//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    
public:
    int dx[8]={0,0,-1,1,-1,1,-1,1};
    int dy[8]={-1,1,0,0,-1,1,1,-1};
    bool dfs(string word,vector<vector<char> >& board,vector<vector<bool>>&visited,int i,int j,int idx){
        if(idx==word.length())
        {
            // cout<<word[idx-1];
            return true;
            
        }
           
        if(i>=0&&i<board.size()&&j>=0&&j<board[0].size()&&visited[i][j]==false&&board[i][j]==word[idx]){
            visited[i][j]=true;
            for(int k=0;k<8;k++){
                int x=i+dx[k];
                int y=j+dy[k];
                if(dfs(word,board,visited,x,y,idx+1)){
                   
                    return true;
                }
            }
            visited[i][j]=false;
        }  
        return false;
    }
    bool exist(string word,vector<vector<char> >& board){
        int n=board.size();
        int m=board[0].size();
        //  cout<<word<<endl;
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
               if(word[0]==board[i][j]){
                    // cout<<word<<endl;
                   if(dfs(word,board,visited,i,j,0)){
                       return true;
                   }
               }
            }
        }
        return false;
    }
	vector<string> wordBoggle(vector<vector<char> >& board, vector<string>& dictionary) {
	    vector<string>ans;
	    for(int i=0;i<dictionary.size();i++){
	        string word=dictionary[i];
	        if(exist(word,board)){
	            ans.push_back(word);
	        }
	    }
	    return ans;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> dictionary;
        for (int i = 0; i < N; ++i) {
            string s;
            cin >> s;
            dictionary.push_back(s);
        }
        
        int R, C;
        cin >> R >> C;
        vector<vector<char> > board(R);
        for (int i = 0; i < R; i++) {
            board[i].resize(C);
            for (int j = 0; j < C; j++) cin >> board[i][j];
        }
        Solution obj;
        vector<string> output = obj.wordBoggle(board, dictionary);
        if (output.size() == 0)
            cout << "-1";
        else {
            sort(output.begin(), output.end());
            for (int i = 0; i < output.size(); i++) cout << output[i] << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends