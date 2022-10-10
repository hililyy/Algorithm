/*
    memo
    처음에는 복잡하게 생각해서 666이라는 수가 어떤 경우에 순차적으로 나타나게 되는지 찾았었는데 그렇게 까지 생각할 필요 없이 순차적으로 검색하면서 666이 증가하면 count해주면 되었다.

    새롭게 배운것은 ios_base :: sync_...~ 이 부분을 추가해 주면 속도가 빨라지기 때문에 꾸준히 써주는 습관을 들여야 하는것
    잊고있던 to_string 함수를 사용해 문자열로 변경하는것
    굳이 문자열로 변경한 이유는 find함수를 사용하기 위한 것이며 find함수는 문자열에서만 search가 가능하다.

*/

#include <iostream>
#include <string>
using namespace std;

int main() {
   int N = 0;
   int title = 665;
   int count = 0;
   string _string;

   ios_base :: sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   cin >> N;

   while (++title) {
      _string = to_string(title);
      if (_string.find("666") != -1) {
         count++;
      }
      if (count == N) {
         break;
      }
   }

   cout << title;
   return 0;
}