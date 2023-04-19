#include<bits/stdc++.h>
#define int long long
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

void firstFit() {
    int n,m; cin >> n >> m;
    vector<int> block(n),process(m);

    for(int i=0; i<n; i++) cin >> block[i];
    for(int j=0; j<m; j++) cin >> process[j];
    
    vector<int> allocated(m,-1);

    for(int i=0; i<m; i++) {
        int processSize = process[i];
        int ind = -1;

        for(int j=0; j<n; j++) {
            if(block[j] >= processSize) {
                ind = j;
                break;
            }
        }

        if(ind != -1) {
            block[ind] -= processSize;
            allocated[i] = ind+1;
        }
    }

    cout << "\nProcess No.\tPSize\tBlock no.\n";
    for (int i = 0; i < m; i++)
    {
        cout << "   " << i+1 << "\t\t\t" << process[i] << "\t\t";
        if (allocated[i] != -1)
            cout << allocated[i];
        else
            cout << "Not Allocated";
        cout << endl;
    }
}

int32_t main() {
    fast_io;
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    firstFit();
    return 0;
}

