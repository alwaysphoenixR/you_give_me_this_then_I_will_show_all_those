class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> m1;

        for(char c : text){
            m1[c]++;
        }

        return min({m1['b'], m1['a'], m1['l']/2, m1['o']/2, m1['n']});
    }
};