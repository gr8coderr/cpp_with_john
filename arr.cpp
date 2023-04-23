#include<bits/stdc++.h>
using namespace std;

main(){
    int temp;
    int n  = 2;
    int *p = new int[n]; // locate memory in heap
    int *q = new int[n+1];// locate memory in heap
    
    for(int j=0; j<n;j++)
        p[j] = 10*(j+1);
    
    for(int i=0; i<n;i++)
        q[i] = p[i]; 

    delete []p;//Delete the old array 'p'
    p = q; // Assign the pointer of 'q' to 'p'
    q = NULL; // delete the location of pointer 'q'



    cout<<"Please enter a value: "<<endl;    
    cin>>temp;
    p[n] = temp;

    for(int j=0; j<n+1;j++)
        cout<<j<<' '<<p[j]<<endl;    

    return 0;
}