class Solution {
public:
    using info=tuple<int, char, string>; //(timestamp, kind, users)
    static void print(auto& X){
        for(auto& x: X){
            auto& [t, k, s]=x;
            cout<<t<<"|"<<k<<"|"<<s<<endl;
        }
    }
    static void data_proc(vector<string>& event, vector<info>& X){
        int t=stoi(event[1]);
        char k=event[0]=="MESSAGE"?'M':'A';
        if (k=='A') X.emplace_back(t+60, '1', event[2]);
        X.emplace_back(t, k, event[2]);
    }
    static vector<int> countMentions(int n, vector<vector<string>>& events) {
        vector<int> freq(n, 0);
        vector<info> X;
        X.reserve(n*3);
        for (auto& e: events)
            data_proc(e, X);
        sort(X.begin(), X.end());
    //    print(X);
        bitset<100> online;
        online.set();// all bits set 1
    //    cout<<online<<endl;
        for(auto& x: X){
            auto& [t, k, s]=x;
            if (k!='M'){
                int user=stoi(s);
                online.flip(user);
            }
            else{
                if (s=="ALL") 
                    for_each(freq.begin(), freq.end(), [](int& x){
                        return ++x;});
                else if(s=="HERE"){
        //            cout<<online<<endl;
                    for(int i=0; i<n; i++)
                        freq[i]+=online[i];
                }
                else{
                    stringstream ss(s);
                    char c;
                    int user;
                    while(ss>>c>>c>>user)
                        freq[user]++;
                }
            }
        }
        return freq;
    }
};
