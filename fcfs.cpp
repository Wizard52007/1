#include<iostream>
#include<cmath>

using namespace std;

int main(){
    int n,head;
    int req[10];
    int movement = 0;

    cout<<"Enter number of requests: ";
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> req[i];
    }

    cout << "Initial head position: ";
    cin >> head;

    cout << "\nSeek Sequence: "<<head;
    
    for(int i=0; i<n; i++){
        movement += abs(head - req[i]);
        head = req[i];

        cout << "->" << head;
    }
    cout << "\nTotal head movement: "<<movement;
    return 0;
}