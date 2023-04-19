#include<bits/stdc++.h>
#define int long long
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

void LRU() {
    int n,capacity; cin >> n >> capacity;
    vector<int> pages(n);
    for(int i=0; i<n; i++) cin >> pages[i];

    unordered_set<int> st;
    unordered_map<int,int> mp;

    int page_fault = 0;
    for(int i=0; i<n; i++) {
        if(st.size() < capacity) {
            if(st.find(pages[i]) == st.end()) {
                st.insert(pages[i]);
                mp[pages[i]] = i;
                page_fault++;

                cout << "Page Number " << pages[i] << " added to set\n";
            }
        }

        else {
            if(st.find(pages[i]) == st.end()) {
                int lru = INT_MAX,val;
                for(auto it = st.begin(); it != st.end(); ++it) {
                    if(mp[*it] < lru) {
                        lru = mp[*it];
                        val = *it;
                    }
                }

                st.erase(val);
                st.insert(pages[i]);
                page_fault++;
                cout << "Page Number " << pages[i] << " added to set\n";
            }

            mp[pages[i]] = i;
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

    LRU();
    return 0;
}

