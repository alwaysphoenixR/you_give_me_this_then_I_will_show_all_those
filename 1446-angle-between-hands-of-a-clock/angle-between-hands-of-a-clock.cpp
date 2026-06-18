class Solution {
public:
    double angleClock(int hour, int minutes) {
        double deg1=6*minutes;
        double deg2=minutes/2.0;
        // cout<<deg2<<endl;
        double rem;
        if(hour==12){
            rem=0;
        }else{
            rem=hour*30;
        }
        // cout<<deg1<<" "<<deg2+rem<<endl;
        double a1=abs(deg1-(deg2+rem));
        return min(360-a1,a1);
        
    }
};