class Solution {
public:
    int findDuplicate(vector<int>& nums) {
//👉 Brute force

         map<int,int>mpp;
         for(int i=0;i<nums.size();i++){
             mpp[nums[i]]++;
         }
         int ans=0;
         for(auto it :mpp){
             if(it.second>1){
                 ans=it.first;
             }
         }
    return ans;
  T.C-O(n+n)
  S.C-O(n)
//👉 Better approach
   int slow=nums[0];
   int fast=nums[0];
   do{
       slow=nums[slow];
       fast=nums[nums[fast]];
   }while(slow!=fast);
   
   fast=nums[0];
   while(slow!=fast){
       slow=nums[slow];
       fast=nums[fast];
   }
   return fast;
    }
};

T.C-O(n)
S.C-O(1)
