#include <iostream>
using namespace std;
int main()
{
    int n;
    int a[1000001]={0};
    long long b,c;
    long long result =0;
    
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cin>>b>>c;
    
    for(int i=0;i<n;i++){
        a[i]-=b;
        if(a[i]>0){
            result += a[i]/c;
            if(a[i]%c>0) result++;
        }
        result++;
    }
    cout<<result;
    
}