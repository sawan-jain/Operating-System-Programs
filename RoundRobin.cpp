#include<bits/stdc++.h>
using namespace std;

int roundRobin(vector<int> &arrivalTime,vector<int> &executionTime,int t) {
    queue<int> q;
    int time = 0;
    q.push(executionTime[0]);
    for(int i=1; i<arrivalTime.size(); i++) {
        int f = q.front();
        q.pop();
        // cout<<f<<" "<<time<<"\n";
        time += min(f,t);
        if(time>= arrivalTime[i]) {
            q.push(executionTime[i]);
            if(f-t>0) q.push(f-t);
        } else {
            time = arrivalTime[i];
        }
    }

    while(!q.empty()) {
        int f = q.front();
        q.pop();
        // cout<<f<<" "<<time<<"\n";
        time += min(f,t);
        if(f-t>0) q.push(f-t);
    }

    return time;
}

int main() {
    vector<int> arrivalTime = {0,50,130,190,210,350};
    vector<int> exe = {250,170,75,100,130,50};
    cout<<roundRobin(arrivalTime,exe,100)<<"\n";
    return 0;
}