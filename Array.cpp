#include<iostream>
using namespace std;

//insert the elements from user
void insertElements(int arr[], int size){
    for(int i=0; i<size; i++){
        cin>>arr[i];
    }
}

//print the elements of the array
void printElements(int arr[], int size){
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

//Delete a element from the array
void deleteingElement(int arr[], int &size, int position){
    for(int i= position-1; i<size-1; i++){
        arr[i] = arr[i+1];
    }
    size = size - 1;
}

//search a element form the array
void search(int arr[], int size, int target){
    for(int i=0; i<size; i++){
        if(arr[i] == target){
            cout<<"Found at index "<<":"<<" "<<i<<endl;
        }
    }
}

int main(){
    int size;
    cout<<"Enter the size of the array"<<":"<<" ";
    cin>>size;

    int arr[size];

    int position;
    cout<<"Enter the Position"<<":"<<" ";
    cin>>position;

    int target;
    cout<<"Enter the search element"<<":"<<" ";
    cin>>target;

    cout<<"Enter the Elements of the array"<<":"<<endl;
    insertElements(arr,size);

    cout<<"The Elements of the array is"<<":"<<" ";
    printElements(arr,size);

    deleteingElement(arr,size,position);

    cout<<"After deleting the elements of the array is"<<":"<<" ";
    printElements(arr, size);

    search(arr,size,target);

    return 0;

}