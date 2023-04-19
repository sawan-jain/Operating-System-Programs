#include<bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

void SJF() {
    int n; cin >> n; 
    vector<int> arrivalTime(n), executionTime(n);

    for(int i=0; i<n; i++) cin >> arrivalTime[i];
    for(int i=0; i<n; i++) cin >> executionTime[i];

    int time = 0;
    
    priority_queue<pair<int,int> ,vector<pair<int,int> >, greater<pair<int,int> >> q;
    time += executionTime[0];

    for(int i=1; i<n; i++) {
        if(arrivalTime[i] <= time) {
            q.push({executionTime[i],i});
        }

        auto f = q.top();
        q.pop();
        time += f.first;
        cout << "Process " << f.second << "\n";
        

    }
    
    while(!q.empty()) {
        auto f = q.top();
        q.pop();
        time += f.first;
        cout << "Process " << f.second << "\n";
    }

    cout << "Total Time: " << time << "\n";
}

int main() {
    fast_io;
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    SJF();
    return 0;
}