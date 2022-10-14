//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{


	public:
	string findRollOut(string s, long long arr[], int n)
	{
	    // Your code goes here
	    long long int hash[n+2] = {0};
	    for(int i=0; i<n; i++)
	        hash[arr[i]]++;
	    for(int i=n; i>=0; i--)
	        hash[i] += hash[i+1];
	    for(int i=1; i<=n; i++)
	        s[i-1] = ((s[i-1]-'a')+hash[i])%26 + 'a';
	    return s;
	}
};
	  


//{ Driver Code Starts.

int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
        cin>>n;
        string s;
        cin>>s;
        long long roll[n];
        for(int i=0;i<n;i++)
            cin>>roll[i];

       

        Solution ob;

        string res = ob.findRollOut(s, roll, n);
        cout << res;
		

        
	    cout << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends
