#include <iostream>
using namespace std;
int output[100001]={0};
int num[100001]={0};
int main()
{
    int n,m,a;
    int first_num,second_num;
    int sum=0;
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin >> a;
        sum += a;
        num[i] = sum;
    }

    for(int i=0;i<m;i++){
        cin>>first_num>>second_num;
        output[i]=num[second_num]-num[first_num-1];
        cout<<output[i]<<'\n';
    }
}