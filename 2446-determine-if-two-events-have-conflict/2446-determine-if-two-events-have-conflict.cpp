class Solution {
public:
    bool haveConflict(vector<string>& v1, vector<string>& v2) {
        string s1=v1[0],s2=v1[1],s3=v2[0],s4=v2[1];
        return (s1<=s4 and s3<=s2);
    }
};