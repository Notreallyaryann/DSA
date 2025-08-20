class Solution {
public:
bool canTrip(vector<int>& time, long long  mid,int totalTrips){
    long long  actualTrips=0;


    for(int &x:time){
        actualTrips+=mid/x;     //mid=3,time=1.   (3/1) 
    }
    return actualTrips>=totalTrips;
}

    long long minimumTime(vector<int>& time, int totalTrips) {
        int n=time.size();
        long long l=1;
        long long r=( long long)*min_element(time.begin(),time.end())*totalTrips;


        while(l<r){
            long long mid=l+(r-l)/2;

            if(canTrip(time,mid,totalTrips)){
                r=mid;
            }else{
                l=mid+1;
            }
        }
        return l;
    }
};