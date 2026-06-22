class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> count;
        int countB =0;
        int countA =0;
        int countL =0;
        int countO =0;
        int countN =0;
        for(int i =0 ; i<text.length() ; i++){
            if(text[i] == 'b'){
                countB++;
                
            }
            if(text[i] == 'a'){
                countA++;
                
            }
            if(text[i] == 'l'){
                countL++;
                
            }
            if(text[i] == 'o'){
                countO++;
            
            }
            if(text[i] == 'n'){
                countN++;
                
            }
        }
        return min({countB,countA,(countL/2),(countO/2),countN});
    }
};