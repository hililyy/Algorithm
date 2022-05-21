#include <iostream>
#include <algorithm>
using namespace std;
double score[10000001]={0};

int main() {
 int n;

 cin>>n;
 for(int i=0;i<n;i++) {
     cin >> score[i];
 }
 sort(score,score+n);
 for(int i=0;i<7;i++){
     printf("%.3lf\n",score[i]);
 }
}
