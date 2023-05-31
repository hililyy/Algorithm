#include <iostream>
#include <string.h>
using namespace std;
int n;
char field[100][100];
char _field[100][100];
bool visited[101][101] = { 0 };
bool _visited[101][101] = { 0 };
int count = 0;
int _count = 0;
int x_arr[4] = {0, 0, 1, -1};
int y_arr[4] = {1, -1, 0, 0};

void dfs(int y, int x, char color) {
    for(int t = 0; t < 4; t++) {
        int xx = x_arr[t] + x;
        int yy = y_arr[t] + y;
        if(xx < 0 || yy < 0 || xx >= n || y >= n) continue;
        if(field[yy][xx] == color && !visited[yy][xx]) {
            visited[yy][xx] = true;
            dfs(yy, xx, color);
        }
    }
}

void _dfs(int y, int x, char color) {
    for(int t = 0; t < 4; t++) {
        int xx = x_arr[t] + x;
        int yy = y_arr[t] + y;
        if(xx < 0 || yy < 0 || xx >=n || y >= n) continue;
        if(_field[yy][xx] == color && !_visited[yy][xx]) {
            _visited[yy][xx] = true;
            _dfs(yy, xx, color);
        }
    }
}
void check(char color, bool type, int i, int j) {
    if (type) {
        if((!visited[i][j]) && (field[i][j] == color)) {
            visited[i][j] = true;
            count++;
            dfs(i, j, color);
        }
    } else {
        if((!_visited[i][j]) && (_field[i][j] == color)) {
            _visited[i][j] = true;
            _count++;
            _dfs(i, j, color);
        }
    }
}

int main() {
    cout.tie(0); cin.tie(0) -> sync_with_stdio(0);
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        string input;
        cin >> input;
        for(int j = 0; j < n; j++) {
            field[i][j] = input[j];
            if (field[i][j] == 'R' || field[i][j] == 'G') {
                _field[i][j] = 'G';
            } else {
                _field[i][j] = 'B';
            }
        }
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            check('R', true, i, j);
            check('G', true, i, j);
            check('B', true, i, j);
            check('G', false, i, j);
            check('B', false, i, j);
        }
    }
    cout << count << ' ' << _count;
}