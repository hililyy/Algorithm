#include <iostream>
using namespace std;
void swap(int *x, int *y) {
  int tmp;
  tmp = *x;
  *x = *y;
  *y = tmp;
}

int main()  {
  int n, m;
  int box[101] = { 0 };
  cin >> n >> m;
  
  for(int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    if(!box[a]) box[a] = a;
    if(!box[b]) box[b] = b;
    swap(&box[a], &box[b]);
  }
  
  for(int i = 1; i <= n; i++) {
    if(!box[i]) box[i] = i;
    cout << box[i] << ' ';
  }
  
  return 0;
}