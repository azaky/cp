#include <iostream>

using namespace std;

int main(){
    long long n,prime=1;
    cin >> n;
    for (int i=2; i*i<=n; i++)
        if (!(n%i)) prime=0;
    if (prime) cout << "PRIME\n";
    else cout << "NOT PRIME\n";
    return 0;
}
