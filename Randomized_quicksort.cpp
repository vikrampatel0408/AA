

#include <iostream>
using namespace std;
int count=0;
int partition (int arr[],int s, int r ){
   int pivot = arr[r];
   int i = s-1;
   int j=0;
   count++;
   for(j=s;j<=r-1 ;j++){
       if(arr[j]<=pivot){
           i=i+1;
           swap(arr[i],arr[j]);
       }


   }


   swap(arr[i+1],arr[r]);
   return i+1;
}
int randomized_partition (int arr[],int s ,int r){
   int i = rand()%(r-s + 1) + s;
   swap(arr[i],arr[r]);
   return (partition(arr,s,r));


}
void quicksort (int arr[] , int s,int r){
   if(s<r){
   int q= randomized_partition(arr,s,r);
   quicksort(arr,s,q-1);
   quicksort(arr,q+1,r);
   }
}




int main(){
   int arr [] = {4, 3, 6, 8, 5, 9, 20, 50, 12, 30, 432, 12, 69, 29, 40, 50, 10, 4, 23, 34, 45, 45, 24,
89, 799, 45, 80, 50, 10, 30, 43,54,65,76,87, 98, 21, 32, 43, 78, 98, 57, 29, 91, 34,
54, 64, 19, 82, 87, 65};
   quicksort(arr,0,(sizeof(arr)/4)-1);


   for(int i=0;i<sizeof(arr)/4;i++){
       cout<<arr[i]<<" ";
   }
   cout<<endl<<count ;
   return 0;
}
