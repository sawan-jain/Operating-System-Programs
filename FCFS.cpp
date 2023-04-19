#include<bits/stdc++.h>
#define int long long
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

void FCFS() {
    int n; cin >> n;
    vector<int> bustTime(n), waitTime(n,0),tat(n,0);

    // for(int i=0; i<n; i++) cin >> arrivalTime[i];
    for(int i=0; i<n; i++) cin >> bustTime[i];

    // waitTime
    for(int i=1; i<n; i++) {
        waitTime[i] = bustTime[i-1] + waitTime[i-1];
    }

    // Total Turnaround time
    for(int i=0; i<n; i++) {
        tat[i] = waitTime[i] + bustTime[i];
    }

    cout << "PNO.    BT\t WT\t Tat\t\n";

    for(int i=0; i<n; i++) {
        cout <<"\t"<<i+1 << "\t" << bustTime[i] << "\t " << waitTime[i] << "\t " << tat[i] << "\n"; 
    }

}

int32_t main() {
    fast_io;
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    FCFS();
    return 0;
}

