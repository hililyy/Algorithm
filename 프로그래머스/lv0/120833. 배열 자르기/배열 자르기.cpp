#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers, int num1, int num2) {
    vector<int> answer;
    for(int n = num1; n <= num2; n++) {
        answer.push_back(numbers[n]);
    }
    return answer;
}