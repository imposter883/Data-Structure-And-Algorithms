#include<iostream>
using namespace std;

void insertElements(int arr[], int size){
    for(int i=0; i<size; i++){
        cin>>arr[i];
    }
}

void subArray(int arr[],int size){
    for(int i=0; i<size; i++){
        for(int j=i; j<size; j++){
            for(int k=i; k<=j; k++){
                cout<<arr[k]<<" ";
            }
            cout<<endl;
        }
    }
}

int main(){
    int size;
    cout<<"Enter the size of the array"<<" ";
    cin>>size;

    int arr[size];
    cout<<"Enter the elements of the Array"<<endl;
    insertElements(arr,size);

    cout<<"The sub-Arrays are :"<<endl;
    subArray(arr,size);

    return 0;
}