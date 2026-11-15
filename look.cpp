#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int main(){
    int head,n;
    int req[100];
    int movement = 0;
    string direction;

    cout<<"Enter number of req: ";
    cin>>n;
    
    cout<<"Enter sequence: ";
    for(int i=0; i<n; i++){
        cin>>req[i];
    }

    cout<<"Enter head pos: ";
    cin>>head;

    sort(req, req+n);

    cout<<"Enter direction :(right/left)";
    cin>>direction;

    cout<<"\nSeek Sequence: "<<head;

    int index = 0;
    while(index < n && req[index]<head){
        index++;
    }

    if(direction == "right"){
        for(int i=index; i<n; i++){
            movement += abs(head - req[i]);
            head = req[i];
            cout << "->" <<head;
        }
        for(int i=index-1; i>=0; i--){
            movement += abs(head - req[i]);
            head = req[i];
            cout << "->" <<head;
        }
    }
    else{
        for(int i=index-1; i>=0; i--){
            movement += abs(head - req[i]);
            head = req[i];
            cout << "->" <<head;
        }
        for(int i = index; i<n; i++){
            movement += abs(head - req[i]);
            head = req[i];
            cout << "->" <<head;
        }
    }
    cout<<"\nTotal head movements" <<movement;

}