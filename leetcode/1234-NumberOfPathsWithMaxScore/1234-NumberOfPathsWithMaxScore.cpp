// Last updated: 10/12/2026, 9:52:45 PM
class Solution {
public:
    int n;
    int MOD = 1e9+7;
    vector<vector<pair<int,int>>> t;
    
    int getIntFromChar(char ch){
        return ch!= 'S'? ch -'0':0;
    }

    bool isValid(int i , int j , vector<string>& board){
        return (i>= 0 && i<n && j>= 0 && j<n && board[i][j] != 'X');
    }
    pair<int,int> solve(int i , int j ,vector<string>& board){
        if(board[i][j] == 'E'){
            return {0,1};
        }
        if(board[i][j] == 'X'){
            return {0,0};
        }
        if(t[i][j] != make_pair(-1,-1)){
            return t[i][j];
        }
        int upScore =0 , upPath =0;
        int leftScore =0, leftPath =0;
        int diagScore =0,diagPath =0;

        char ch = board[i][j];

        if(isValid(i-1,j,board)){
            auto [score , paths] = solve(i-1,j,board);
            upPath = paths;
            upScore = score;
            if(upPath > 0){
                upScore += getIntFromChar(ch);
            }
        }
        if(isValid(i,j-1,board)){
            auto [score , paths] = solve(i,j-1,board);
            leftPath = paths;
            leftScore = score;
            if(leftPath > 0){
                leftScore += getIntFromChar(ch);
            }
        }
        if(isValid(i-1,j-1,board)){
            auto [score , paths] = solve(i-1,j-1,board);
            diagPath = paths;
            diagScore = score;
            if(diagPath > 0){
                diagScore += getIntFromChar(ch);
            }
        }

        int bestScore,bestPath;
        if(upScore == leftScore && leftScore == diagScore ){
            bestScore = upScore;
            bestPath = upPath +leftPath + diagPath;
        }else if(upScore == leftScore){
            bestScore = upScore;
            bestPath = upPath + leftPath;
            if(diagScore > bestScore || (diagScore == bestScore && diagPath > bestPath)){
                bestScore = diagScore;
                bestPath = diagPath;   
            }
        }else if(leftScore == diagScore){
            bestScore = leftScore;
            bestPath = leftPath + diagPath;
            if(upScore > bestScore || (upScore == bestScore && upPath > bestPath)){
                bestScore = upScore;
                bestPath = upPath;   
            }
        }else{
            bestScore = upScore;
            bestPath = upPath;
            if(leftScore > bestScore || (leftScore == bestScore && leftPath > bestPath)){
                bestScore = leftScore;
                bestPath = leftPath;   
            }
            if(diagScore > bestScore || (diagScore == bestScore && diagPath > bestPath)){
                bestScore = diagScore;
                bestPath = diagPath;   
            }
        }

        return t[i][j] = {bestScore , bestPath%MOD};
    }

    vector<int> pathsWithMaxScore(vector<string>& board) {
        n = board.size();
        t.assign(n, vector<pair<int,int>>(n,{-1,-1}));
        pair<int,int> result = solve(n-1,n-1,board);
        
        return {result.first, result.second};
    }
};