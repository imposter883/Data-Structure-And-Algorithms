#include<iostream>
using namespace std;

const int column = 100;

// For insert Elements
void insertElements(int arr[][column], int &s1, int &s2){
    for(int i=0; i<s1; i++){
        for(int j=0; j<s2; j++){
            cin>>arr[i][j];
        }
    }
}

// For print Elements
void print(int arr[][column], int &s1, int &s2){
    for(int i=0; i<s1; i++){
        for(int j=0; j<s2; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

// Search an element from a multidimentional Array
void Search(int arr[][column], int &s1, int &s2, int target){
    for(int i=0; i<s1; i++){
        for(int j=0; j<s2; j++){
            if(arr[i][j]==target){
                cout<<"Found at index"<<" "<<"("<<i<<","<<j<<")"<<endl;
            }
        }
    }
}

//Delete an Element from a multidimentional Array
void Delete(int arr[][column], int &s1, int &s2, int &p1, int &p2){
    if (p1 < 0 || p1 >= s1 || p2 < 0 || p2 >= s2) {
        cout << "Invalid position" << endl;
        return;
    }
    arr[p1][p2] = 0;
}


int main(){
    int s1,s2;
    cin>>s1>>s2;

    int arr[s1][column];

    cout<<"Enter the elements:"<<endl;
    insertElements(arr,s1,s2);

    cout<<"The Array is"<<endl;
    print(arr,s1,s2);

    int target;
    cout<<"Enter the Element for search"<<":"<<" ";
    cin>>target;

    Search(arr,s1,s2,target);

    int p1;
    cout<<"Enter the First Position of the Element for Delete"<<":"<<" ";
    cin>>p1;

     int p2;
    cout<<"Enter the Second Position of the Element for Delete"<<":"<<" ";
    cin>>p2;

    Delete(arr,s1,s2,p1,p2);

    cout<<"After Deleting the Array is"<<endl;
    print(arr,s1,s2);

    return 0;
}