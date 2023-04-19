#include<bits/stdc++.h>
#define int long long
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

void FifoPaging() {
    int n,capacity; cin >> n >> capacity;
    vector<int> pages(n);
    for(int i=0; i<n; i++) cin >> pages[i];

    unordered_set<int> st;
    queue<int> q;

    int page_fault = 0;
    for(int i=0; i<n; i++) {
        if(st.size() < capacity) {
            if(st.find(pages[i]) == st.end()) {
                st.insert(pages[i]);
                q.push(pages[i]);
                page_fault++;
                cout << "Page Number " << pages[i] << " added to set and queue\n";
            }
        }

        else {
            if(st.find(pages[i]) == st.end()) {
                int v = q.front();
                q.pop();
                st.erase(v);
                st.insert(pages[i]);
                q.push(pages[i]);
                page_fault++;

                cout << "Page Number " << v << " removed from queue\n";
                cout << "Page Number " << pages[i] << " added to set and queue\n";
            }
        }
    }

    cout << "Page Faults: " << page_fault << "\n";

}

int32_t main() {
    fast_io;
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    FifoPaging();
    return 0;
}

