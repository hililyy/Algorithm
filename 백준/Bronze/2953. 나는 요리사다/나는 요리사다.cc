#include <iostream>
using namespace std;

int main()  {
  int answer_score = 0;
  int answer_person;
  
  for(int i = 1; i <= 5; i++) {
    int sum = 0;
    for(int j = 0; j < 4; j++) {
      int score;
      cin >> score;
      sum += score;
    }
    
    if (answer_score < sum) {
      answer_score = sum;
      answer_person = i;
    }
  }
  
  cout << answer_person << ' ' << answer_score;
  
  return 0;
}