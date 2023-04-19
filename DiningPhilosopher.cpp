#include<bits/stdc++.h>
#define int long long
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

void wait(int &s) {
    if(s>0) s--;
}

void signal(int &s) {
    s++;
}

void producerConsumer() {
    int n; cin >> n;          // BUFFER SIZE
    int empty = n, full = 0;  // COUNTING SEMAPHORE
    int mutex = 1;            // BINARY SEMAPHORE

    while(1) {
        int choice; cin >> choice;
        if(choice == 1) {
            if(empty>0 && mutex==1) {
                wait(empty);
                wait(mutex);

                // Critical Section
                cout << "empty: " << empty << " " << "mutex: " << mutex<<"\n";

                signal(mutex);
                signal(full);
            }

            else {
                cout << "Buffer Full\n";
            }
        }

        else if(choice == 2) {
            if(full>0 && mutex==1) {
                wait(full);
                wait(mutex);
                
                // Critical Section
                cout << "Full: " << full << " " << "mutex: " << mutex<<"\n";

                signal(mutex);
                signal(empty);

            }

            else cout << "Buffer Empty\n";
        }

        else break;
    }

}

int32_t main() {
    fast_io;
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    producerConsumer();
    return 0;
}

