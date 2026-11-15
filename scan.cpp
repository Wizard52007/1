#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int main(){
    int n,head,size;
    int req[100];
    int movement = 0;
    string direction;

    cout<<"Enter number of requests: ";
    cin>>n;

    cout<<"Enter sequence: ";
    for(int i=0; i<n; i++){
        cin >> req[i];
    }

    cout<<"Enter head position: ";
    cin>>head;

    cout<<"Enter disc size: ";
    cin>>size;

    cout<<"Enter direction: (left/right)";
    cin>>direction;

    sort(req, req+n);

    cout << "\nSeek sequence: "<<head;

    int index = 0;
    while(index < n && req[index]<head){
        index++;
    }

    if(direction == "right"){
        for(int i=index; i<n; i++){
            movement += abs(req[i] - head);
            head = req[i];
            cout << "->" <<head;
        }

        if(head != size-1){
            movement += abs(head - (size-1));
            head = size-1;
            cout << "->" <<head;
        }

        for(int i=index-1; i>=0; i--){
            movement += abs(req[i] - head);
            head = req[i];
            cout << "->" <<head;
        }
    }

    else{
        for(int i=size-1; i>=0; i--){
            movement += abs(req[i] - head);
            head = req[i];
            cout << "->" <<head;;
        }

        if(head != 0){
            movement += abs(head - 0);
            head = 0;
            cout << "->" <<head;
        }

        for(int i=index; i<n; i++){
            movement += abs(req[i]-head);
            head = req[i];
            cout << "->" <<head;
        }
    }
    cout << "\nTotal head movements: "<<movement;
    return 0;

    
}