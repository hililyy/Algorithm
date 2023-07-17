#include <iostream>
using namespace std;

int max_arr[3] = {31, 12, 2010}; // 나이 어린 사람
int min_arr[3] = {1, 1, 1990}; // 나이 많은 사람
string max_name, min_name;

int main() {
  int n, year, month, day;
  string name;
  cin >> n;
  
  cin >> name >> day >> month >> year;
  
  max_arr[0] = day;
  max_arr[1] = month;
  max_arr[2] = year;
  max_name = name;
  
  min_arr[0] = day;
  min_arr[1] = month;
  min_arr[2] = year;
  min_name = name;
  
  for(int i = 0; i < n - 1; i++) {
    
    cin >> name >> day >> month >> year;
    
    if(year > max_arr[2]) {
      max_name = name;
      max_arr[0] = day;
      max_arr[1] = month;
      max_arr[2] = year;
    } else if (year == max_arr[2]) {
      if(month > max_arr[1]) {
        max_name = name;
        max_arr[0] = day;
        max_arr[1] = month;
        max_arr[2] = year;
      } else if (month == max_arr[1]) {
        if(day > max_arr[0]) {
        max_name = name;
        max_arr[0] = day;
        max_arr[1] = month;
        max_arr[2] = year;
        } else if (day == max_arr[0]) {
          continue;
        }
      }
    }
    
    if(year < min_arr[2]) {
      min_name = name;
      min_arr[0] = day;
      min_arr[1] = month;
      min_arr[2] = year;
    } else if (year == min_arr[2]) {
      if(month < min_arr[1]) {
        min_name = name;
        min_arr[0] = day;
        min_arr[1] = month;
        min_arr[2] = year;
      } else if (month == min_arr[1]) {
        if(day < min_arr[0]) {
        min_name = name;
        min_arr[0] = day;
        min_arr[1] = month;
        min_arr[2] = year;
        } else if (day == min_arr[0]) {
          continue;
        }
      }
    }
  }
  
  cout << max_name << '\n' << min_name;
  return 0;
}