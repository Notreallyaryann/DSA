class Solution {
public:

bool canEatAll(vector<int>& piles,int mid,int h){
    int actualhrs=0;
    for(int &x :piles){
        actualhrs+=x/mid; //hrs. mid=3 piles=7 (7/3)
        if(x%mid!=0){
             actualhrs++     ; //jo baki reh gya 
        }
    }
    return actualhrs<=h ;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1;
        int r=*max_element(piles.begin(),piles.end());

        while(l<r){
            int mid=l+(r-l)/2;

            if(canEatAll(piles,mid,h)){
                r=mid;
            }else{
                l=mid+1;
            }
        }
        return l;
    }
};