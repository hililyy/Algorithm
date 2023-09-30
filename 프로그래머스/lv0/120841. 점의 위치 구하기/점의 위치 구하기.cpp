#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> dot) {
    if(dot.front() > 0 && dot.back() > 0) return 1;
    else if(dot.front() < 0 && dot.back() > 0) return 2;
    else if(dot.front() < 0 && dot.back() < 0) return 3;
    else if(dot.front() > 0 && dot.back() < 0) return 4;
}