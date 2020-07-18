#include<bits/stdc++.h>
using namespace std;
int count(vector<int> v, int n){
    vector<int> y;
    for(int i = 0; i < n; i++)
        y.push_back(v[i]);
    vector<int> x;
    x.assign(n, 0);
    int c = 0;
    while(x != v){
        c++;
        for(int i = 0; i < n; i++){
            x[v[i]-1] = y[i];
        }
        y = x;
    }
    return c;

}
int main(){
    int t;
    cin >> t;
    int n, temp;
    for(int i = 0; i < t; i++){
        cin >> n;
        vector<int> v;
        for(int num = 0; num < n; num++){
            cin >> temp;
            v.push_back(temp);
        }
        cout << count(v, n);
    }

    return 0;
}