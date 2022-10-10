#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string input[51];
string white[9] = {
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW"
};

string black[9] = {
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB"
};

int black_tile(int x, int y) {
    int result = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (input[x + i][y + j] != black[i][j]) result++;
        }
    }
    return result;
}

int white_tile(int x, int y) {
    int result = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (input[x + i][y + j] != white[i][j]) result++;
        }
    }
    return result;
}
int main()
{
    int n, m;
    int result = -1;

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }

    for (int i = 0; i <= n - 8; i++) {
        for (int j = 0; j <= m - 8; j++) {
            if(result==-1) result = min(black_tile(i,j),white_tile(i,j));
            else result = min({ black_tile(i, j), white_tile(i, j), result });
            
        }
    }
    cout << result;

}