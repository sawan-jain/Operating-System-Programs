#include<bits/stdc++.h>
using namespace std;

int LJF(vector<int> &arrivalTime,vector<int> &executionTime) {
    int time = 0;
    priority_queue<pair<int,int>> q;  // time,index
    time += executionTime[0];

    for(int i=1; i<arrivalTime.size(); i++) {
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

    return time;
}

int main() {
    vector<int> arr = {0,1,2,4,5};
    vector<int> exe = {3,8,6,4,2};
    int t = LJF(arr,exe);
    cout << "Total time: " << t << "\n";
    return 0;
}