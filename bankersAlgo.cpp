#include<bits/stdc++.h>
#define int long long
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

// n = 5 process ,k = 3 resources

void bankersAlgo() {
    int n,k;
    cin>>n>>k;
    vector<vector<int>> allocated(n,vector<int>(k,0));
    vector<vector<int>> maxNeed(n,vector<int>(k,0));
    vector<vector<int>> required(n,vector<int>(k,0)); // maxneed - allocated
    vector<int> avalailable(k);

    vector<int> vis(n,0);
    vector<int>ans(n);

    // I/P NEEDED FOR PROCESSING
    for(int i=0; i<n; i++) {
        for(int j=0; j<k; j++) cin>>allocated[i][j];
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<k; j++) cin>>maxNeed[i][j];
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<k; j++) required[i][j] = maxNeed[i][j] - allocated[i][j];
    }

    for(int i=0; i<k; i++) cin>>avalailable[i];
    // main logic

    int indx = 0;
    for(int K=0; K<n; K++) {
        for(int i=0; i<n; i++) {
            if(vis[i] == 0) {
                int flag = 0;
                for(int j=0; j<k; j++) {
                    if(required[i][j] > avalailable[j]) {
                        flag = 1;
                        break;
                    }
                }

                if(flag == 0) {
        
                    for(int j=0; j<k; j++) {
                        avalailable[j] += allocated[i][j];
                        allocated[i][j] = 0;
                    }

                    vis[i] = 1;
                    ans[indx++] = i;
                }
            }
        }
    }

    int flag = 0;
    for(int i=0; i<n; i++) {
        if(vis[i] == 0) {
            cout<<"deadlock is present , NOT a safe state\n";
            flag = 1;
            break;
        }
    }

    if(flag == 0) {
        for(int i=0; i<n-1; i++) {
            cout<<"P"<<ans[i]<<"->";
        }

        cout<<"P"<<ans[n-1]<<"\n";
    }
}

int32_t main() {
    fast_io;
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    bankersAlgo();
    return 0;
}

