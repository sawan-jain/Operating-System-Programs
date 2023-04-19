#include<bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int priorityScheduling() {
    int n; cin >> n;
    vector<int> bustTime(n);
    vector<int> priority(n);

    for(int i=0; i<n; i++) cin >> bustTime[i];
    for(int i=0; i<n; i++) cin >> priority[i];

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q; // priority,index

    for(int i=0; i<priority.size(); i++) {
        q.push({priority[i],i});
    }

    int time = 0;
    while(!q.empty()) {
        auto f = q.top();
        q.pop();

        int ind = f.second;
        time += bustTime[ind];
        cout<<"process P"<<ind+1<<"\n";
    }
    
    return time;
}

int main() {
    fast_io;
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    int t = priorityScheduling();
    cout << "Total Time: " << t << "\n";
    return 0;
}