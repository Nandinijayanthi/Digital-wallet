
#include<bits/stdc++.h>
using namespace std;
bool compare(pair<int,int>&a,pair<int,int>&b)
{
    return a.second<b.second;
}

int main() {
    int n,balance,user_id;
    cin>>n;
    map<int,int>user;
    for(int i=0;i<n;i++)
    {
        cin>>user_id;
        cin>>balance;
        user[user_id]=balance;
    }
    int t,from_user,to_user,amount;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>from_user>>to_user>>amount;
        if((user.find(from_user)!=user.end())&&(user.find(to_user)!=user.end())&&(user[from_user]>=amount))
        {
            user[from_user]-=amount;
            user[to_user]+=amount;
            cout<<"Success"<<endl;
        }
        else
        {
            cout<<"Failure"<<endl;
        }
    }
    cout<<endl;
    vector<pair<int, int>>v(user.begin(), user.end());
    sort(v.begin(),v.end(),compare);
    for(const auto& user:v)
    {
        cout<<user.first<<" "<<user.second<<endl;
    }
    return 0;
}
