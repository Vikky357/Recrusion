
#include<bits/stdc++.h>
using namespace std;
int xpath[2] = {0,1};
int ypath[2] = {1,0};
void printpath(bool tracker[][100], pair<int,int> dest) {
    for(int i=0; i<=dest.first; i++) {
        for(int j=0; j<=dest.second; j++) {
            if(tracker[i][j])
                cout<<1<<" ";
            else
                cout<<0<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    return ;
}
bool trackpath(char maze[][100], bool tracker[][100], pair<int,int> source, pair<int,int> dest) {

    if(maze[source.first][source.second] =='X' || source.first>dest.first  || source.second>dest.second)
        return false;
    if(source.first == dest.first && source.second == dest.second) {
        tracker[dest.first][dest.second] = true;
        printpath(tracker, dest);
        tracker[dest.first][dest.second] = false;
        return true;
    }
    tracker[source.first][source.second] = true;
    // bool rightmost = trackpath(maze, tracker, {source.first,source.second+1},dest);
    // if(rightmost) 
    //     return true;
    // bool down = trackpath(maze, tracker, {source.first+1,source.second},dest);
    // if(down)
    //     return true;
    for(int i=0; i<2; i++) {
        int newx = xpath[i] + source.first;
        int newy = ypath[i] + source.second;
        if(trackpath(maze, tracker, {newx,newy}, dest))
            return true;
    }
    tracker[source.first][source.second] = false;
    return false;


}
int main() {
    char maze[100][100] = {
        "OXOO","OOOX","OOXO","XOOO","XXOO"
    };
    pair<int,int> source = {0,0};
    pair<int,int> dest = {4,3};
    bool tracker[100][100];
    memset(tracker,false,sizeof(tracker));
    if(!trackpath(maze, tracker, source, dest))
        cout<<"Path not Found";
    

    return 0;

}
