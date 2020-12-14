#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends




class Solution {

public:

    int sum = 0;
    int n;

    int solve(int arr[],int i,int k,int* dp,int sum)
    {
        if(i==n) return 0;
        int ans = 0;
        if(*((dp+i*(sum+1)) + k) != -1) return *((dp+i*(sum+1)) + k);

        if(k>=arr[i]) ans = max( ans , arr[i] + solve(arr,i+1,k-arr[i],dp,sum) );
        ans = max(ans,solve(arr,i+1,k,dp,sum));

        return *((dp+i*(sum+1)) + k) = ans;
    }


    int minDiffernce(int arr[], int N)
    {
        n = N;

        sum = accumulate(arr,arr+n,0);

        int dp[n+1][sum+1];

        memset(dp,-1,sizeof(dp));


        int x = solve(arr,0,sum/2,(int*)dp,sum);

        memset(dp,-1,sizeof(dp));

        int y = solve(arr,0,sum - sum/2,(int*) dp,sum);



        return min(abs(sum-2*x),abs(sum-2*y));

    }
};


// { Driver Code Starts.
int main()
{


    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
            cin >> a[i];



        Solution ob;
        cout << ob.minDiffernce(a, n) << "\n";

    }
    return 0;
}  // } Driver Code Ends