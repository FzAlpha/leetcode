class Solution {
    fun maxNumberOfBalloons(text: String): Int {
        var countB = 0;
        var countA = 0;
        var countL =0;
        var countO = 0;
        var countN = 0;
        for (i in text){
            if (i == 'b'){
                countB++;
            }
            if (i == 'a'){
                countA++;
            }
            if(i == 'l'){
                countL++;
                
            }
            if(i == 'o'){
                countO++;
            
            }
            if(i == 'n'){
                countN++;
                
            }
        }
        
        return minOf(countB,countA,(countL/2),(countO/2),countN)
    }
}