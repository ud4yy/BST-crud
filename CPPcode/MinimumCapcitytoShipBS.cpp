int daysRequired(vector<int> &weights,int cap){
    int days=1;
    int w=0;
    for(auto it:weights){
        if(it+w>cap){
            days++;
            w=it;
        }
        else{
            w+=it;
        }
    }
    return days;
}

int leastWeightCapacity(vector<int> &weights, int d)
{
    int low= *max_element(weights.begin(),weights.end());

    int high=0;

    for(auto it:weights)
    {
        high+=it;
    }
    /*
    capcity ranges from
    maxelement from array -  sum of all elements
    */
    int ans=0;
    while(low<=high){
        int mid= low +(high-low)/2;

        if(daysRequired(weights,mid)<=d){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}
