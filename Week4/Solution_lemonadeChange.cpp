/*
* 860. 柠檬水找零
*/
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five=0,ten=0;
        for(auto& b:bills) {
            if(5 == b) ++five;
            else if(10 == b && five>0) {  ++ten;--five; }
            else if(20 == b && five>0){
                if( ten >0 ) {--ten;--five; }
                else if( five>2 ) five -= 3;
                else return false;
            }
            else return false;
        }
        return true;
    }
};
