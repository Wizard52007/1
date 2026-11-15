#include<iostream>
#include<cmath>

using namespace std;

int main(){
   int head,n;
   int req[100];
   bool visited[100] = {false};
   int movement = 0;
   
   cout<<"Enter number of requests: ";
   cin>>n;

   cout<<"Enter request sequence: ";
   for(int i=0; i<n; i++){
    cin >> req[i];
   }

   cout<<"Enter head position: ";
   cin>>head;

   cout<<"\nSequence of request is: "<<head;

   for(int i=0; i<n; i++){
      int minD = 999999;
      int index = -1;
      for(int j=0; j<n; j++){
        if(!visited[j] && abs(head - req[j]) < minD){
            minD = abs(head - req[j]);
            index = j;
        }
      }
      movement += minD;
      head = req[index];
      visited[index] = true;

      cout<<"->"<<head;
   }
   cout<<"\nTotal head movement: "<<movement;
   return 0;
}