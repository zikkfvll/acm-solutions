#include<bits/stdc++.h>
using namespace std;

char t;
stack<int> s;

int main() {
    while(cin >> t&&t != '@') {
        if(t>='0'&&t<='9'){
            int temp=t-'0';
            while(cin>>t&&t>='0'&&t<='9')
                temp=temp*10+t-'0';
            s.push(temp);
        } else if(t == '+') {
            int a=s.top();
            s.pop();
            int b=s.top();
            s.pop();
            s.push(b+a);
        } else if(t == '-') {
            int a=s.top();
            s.pop();
            int b=s.top();
            s.pop();
            s.push(b-a);
        } else if(t == '*') {
            int a=s.top();
            s.pop();
            int b=s.top();
            s.pop();
            s.push(b*a);
        } else if(t == '/') {
            int a=s.top();
            s.pop();
            int b=s.top();
            s.pop();
            s.push(b/a);
        }
    }
    cout<<s.top();
    return 0;
} 

