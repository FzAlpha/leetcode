class Solution {
public:
    void fill(vector<vector<int>>& image, int i, int j, int ncolor , int ocolor){
        if(i<0||j<0||i>= image.size() || j>= image[0].size() || image[i][j] ==ncolor || image[i][j] != ocolor){
            return;
        }
        image[i][j] = ncolor;
        fill(image , i-1 , j ,ncolor,ocolor);
        fill(image , i , j+1 ,ncolor,ocolor);
        fill(image , i+1 , j ,ncolor,ocolor);
        fill(image , i , j-1 ,ncolor,ocolor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        fill(image,sr,sc,color,image[sr][sc]);
        return image;
    }
};