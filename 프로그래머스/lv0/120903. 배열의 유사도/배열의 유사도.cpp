#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<string> s1, vector<string> s2) {
    int answer = 0;
    for(string n1 : s1) {
        for(string n2 : s2) {
            if(n1 == n2) answer++;
        }
    }
    return answer;
}