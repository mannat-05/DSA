#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
{
    int m=image.size();
    int n=image[0].size();
    int temp=image[sr][sc];
    if (temp == color) return image;
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    queue<pair<int, int>> q;
    image[sr][sc]=color;
    q.push({sr, sc});
    while (!q.empty())
    {
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        for (int k=0; k<4; k++)
        {
            int nx=x+dx[k];
            int ny=y+dy[k];
            if (nx<0 || nx>=m || ny<0 || ny>=n) continue;
            if (image[nx][ny] == temp)
            {
                image[nx][ny]=color;
                q.push({nx, ny});
            }
        }
    }
    return image;
}

int main() 
{
    vector<vector<int>> image = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}
    };
    int sr = 1, sc = 1, color = 2;
    vector<vector<int>> result = floodFill(image, sr, sc, color);
    cout << "Resulting Grid:\n";
    for (const auto& row : result) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << "\n";
    }
    return 0;
}