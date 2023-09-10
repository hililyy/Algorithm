#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list) {
    vector<int> answer;
    int a = 0, b = 0;
    for(int num: num_list) {
        if(num % 2) {
            b++;
        } else {
            a++;
        }
    }
    answer.push_back(a);
    answer.push_back(b);
    return answer;
}