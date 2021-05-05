#include<bits/stdc++.h>
using namespace std;
void mapstring(string input, string output) {
    if(input[0] == '\0') {
        cout << output<<endl;
        return ;
    }
    char singledigit = (input[0]-'0') - 1 + 'A';
    mapstring(input.substr(1), output+singledigit);
    if(input.size() >= 2) {
        int doubledigit = (input[0]-'0')*10 + (input[1]-'0');
        if(doubledigit > 0 && doubledigit <= 26) {
            char doublechar = doubledigit - 1 + 'A';
            mapstring(input.substr(2),output+doublechar);
        }
    }

    return ;
}
int main() {

    system("clear");
    string input;
    cout<<"Enter the string: ";
    cin >> input;
    mapstring(input,"");
    return 0;
}