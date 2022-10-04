{
public:

    void find(int ind, vector <int> &arr, int N, vector<int> &v, int sum){
        if(ind==N){
            v.push_back(sum);
            return;
        }
        find(ind + 1, arr, N, v, sum);
        find(ind + 1, arr, N, v, sum + arr[ind]);
    }
    
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector <int> v;
        find(0,arr, N, v, 0);
        return v;
    }
};
