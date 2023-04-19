#include<bits/stdc++.h>
#define int long long
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

void forking() {
    pid_t c_pid = fork();
  
    if (c_pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    else if (c_pid > 0) {
        cout << "printed from parent process " << getpid() << endl;
    }
    else {
        cout << "printed from child process " << getpid()<<"\n";
    }

    cout << "Sawan\n";
}

int32_t main() {
    fast_io;
    forking();
// #ifndef ONLINE_JUDGE
//     freopen("input.txt","r",stdin);
//     freopen("output.txt","w",stdout);
// #endif
    return 0;
}
