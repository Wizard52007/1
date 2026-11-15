#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int n, head;
    int req[100];
    int movement = 0;
    string direction;

    cout << "Enter number of requests: ";
    cin >> n;

    cout << "Enter request sequence: ";
    for(int i = 0; i < n; i++) {
        cin >> req[i];
    }

    cout << "Enter initial head position: ";
    cin >> head;

    cout << "Enter direction (left/right): ";
    cin >> direction;

    sort(req, req + n);

    cout << "\nSeek Sequence: " << head;

    int index = 0;

    while(index < n && req[index] < head) {
        index++;
    }

    if(direction == "right") {

        for(int i = index; i < n; i++) {
            movement += abs(head - req[i]);
            head = req[i];
            cout << " -> " << head;
        }

        if(index > 0) {
            movement += abs(head - req[0]);
            head = req[0];
            cout << " -> " << head;

            for(int i = 1; i < index; i++) {
                movement += abs(head - req[i]);
                head = req[i];
                cout << " -> " << head;
            }
        }
    }
    else {

        for(int i = index - 1; i >= 0; i--) {
            movement += abs(head - req[i]);
            head = req[i];
            cout << " -> " << head;
        }

        if(index < n) {
            movement += abs(head - req[n - 1]);
            head = req[n - 1];
            cout << " -> " << head;

            for(int i = n - 2; i >= index; i--) {
                movement += abs(head - req[i]);
                head = req[i];
                cout << " -> " << head;
            }
        }
    }

    cout << "\nTotal Head Movement: " << movement;

    return 0;
}