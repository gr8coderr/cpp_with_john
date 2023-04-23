#include <iostream>
#include <vector>
using namespace std;

void bubbleSort2(vector<int> array) {
    vector<int> sorted_array;
    int size = array.size();
    int temp;
    for(int step=0;step<size;step++){
        for(int i=0;i<size-(step+1);i++){
           if(array[i]>array[i+1]){
               temp = array[i+1];
               array[i+1] = array[i];
               array[i] = temp; 
           } 
           
        }
        sorted_array.push_back(array[size-step-1]);
        array.pop_back();
    
    }
        for(int j=0;j<size;j++){
            cout<<sorted_array[j]<<"\t";
        }
        cout<<endl;
        array.clear();
        for(int j=0;j<size;j++){
            cout<<array[j]<<"\t";
        }
        cout<<endl;
    
}

int main(){
    vector<int> data = {-2, 45, 0, 11, -9};
    bubbleSort2(data);
}