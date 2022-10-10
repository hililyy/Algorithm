#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    int dp[1000][3]= {0};
    int rgb[3]={0};
    cin>>n;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            cin>>rgb[j];
        }
        if(i==0){
            dp[i][0]=rgb[0];
            dp[i][1]=rgb[1];
            dp[i][2]=rgb[2];
        }
        else {
            dp[i][0]=rgb[0]+min(dp[i-1][1],dp[i-1][2]);
            dp[i][1]=rgb[1]+min(dp[i-1][0],dp[i-1][2]);
            dp[i][2]=rgb[2]+min(dp[i-1][0],dp[i-1][1]);
        }
    }
    cout<<min({dp[n-1][0],dp[n-1][1],dp[n-1][2]});

    

    return 0;
}