const int MAXK = 4;
const int dir[MAXK][2] = {{-1,0}, {0,1}, {1,0}, {0,-1}};
int C, R;

class Solution {
public:
    vector<vector<int>> floodFill(
            vector<vector<int>>& image, int sr, int sc, int newColor
    ) {
        R = image.size();
        C = image[0].size();
        if (image[sr][sc] != newColor) {
            dfs(image, sr, sc, image[sr][sc], newColor);
        }
        return image;
    }

private:
    void dfs(vector<vector<int>>& img, int r, int c, int oldc, int newc) {
        img[r][c] = newc;
        for (int k = 0; k < MAXK; ++k) {
            int nr = r + dir[k][0];
            int nc = c + dir[k][1];
            if ((0 <= nr) && (nr < R) && (0 <= nc) && (nc < C)) {
                if (img[nr][nc] != oldc) continue;
                dfs(img, nr, nc, oldc, newc);
            }
        }
    }
};
