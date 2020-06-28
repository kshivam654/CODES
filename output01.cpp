#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    for(int i = 0; i < s.length()/2+1; i++){
        // for spaces per line
        for(int j = 0; j <= i; ++j){
            cout << " ";
        }
        cout << s[i];
        // for spaces after printing a letter
        for(int k = 0; k < s.length()-i*2; ++k){
            cout << " ";
        }
        cout << s[s.length()-i-1] << endl;
    }

    return 0;
}