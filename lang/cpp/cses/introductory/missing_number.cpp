#include <iostream>

using namespace std;

int main () {
    size_t n;
    cin >> n;

    size_t sum = n*(n+1)>>1;

    size_t buf{};
    for (size_t i=1; i<n; i++)
    {
        cin>>buf;
        sum-=buf;
    }
    cout<<sum;

    return 0;
}
