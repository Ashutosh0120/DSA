class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char d='8';
        for(char x: letters){
            if(x>target){
                d=x; break;
            }
        }
        if(d=='8') return letters[0];
        return d;
    }
};