//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


void addFraction(int num1, int den1, int num2,
                 int den2);

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int a,b,c,d,resultNum,resultDen;
        cin>>a>>b>>c>>d;
        addFraction(a,b,c,d);

    }
}

// } Driver Code Ends


/*You are required to complete this function*/
int GCD_function(int a, int b)
{
    if(b==0) return a;
    else
      return GCD_function(b, a%b);
    
}

void addFraction(int num1, int den1, int num2,int den2)
{
//Your code here
  int GCD = GCD_function(den1, den2);
      
   int LCM = (den1/GCD)*(den2);
   
   int c_num = (LCM/den1)*num1+(LCM/den2)*num2;
   
   int GCD2= GCD_function(c_num, LCM);
   
   cout<<c_num/GCD2<<'/'<<LCM/GCD2<<endl;
 }