class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        //count how many chips are at even post(even to even 0 cost)
        //count how many chips are at odd post(odd to odd 0 cost)
        // then 1 cost from moving even to odd

        int n=position.size();
        int even=0,odd=0;

        for(int i=0;i<n;i++){
            if(position[i]%2==0) even ++;
            else odd ++;
        }
        //ab jo min hoga usko move krege (utne steps lgege)

        return min(odd,even);
    }
};