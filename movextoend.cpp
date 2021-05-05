#include<bits/stdc++.h>
using namespace std;
string movextoend(string input) {
    if(input.size() <= 1)
        return input;
    string findsubstring = movextoend(input.substr(1));
    if(input[0] == 'x') {
        return findsubstring + input[0];
    }

    return input[0] + findsubstring;
}
int main() {

    system("clear");
    string input;
    cout <<"Enter the string: ";
    cin >>input;
    cout << movextoend(input);
    return 0;
}