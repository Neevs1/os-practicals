#include <stdio.h>



void bubble_sort(int arr[], int len){
    
     for(int i=0;i<len;i++){
        for(int j=0;j<len-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;

            }
        }
     }
}

void merge(int arr[],int l,int m,int u){
    int i,j,k;
    int l1 = m-l+1;
    int l2 = u-m;
    int L[l1],U[l2];
    for(int i=0;i<l1;i++){
        L[i]=arr[l+i];
    }
    for(int j=0;j<l2;j++){
        U[j]=arr[m+1+j];
    }
    i = 0;
    j = 0;
    k = l;
    while (i < l1 && j < l2) {
        if (L[i] <= U[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = U[j];
            j++;
        }
        k++;
    }
    while (i < l1) {
        arr[k] = L[i];
        i++;
        k++;
    }


    while (j < l2) {
        arr[k] = U[j];
        j++;
        k++;
    }

}

void mergeSort(int arr[], int l, int r){
    
    if (l < r) {
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

int main(){
    int x[] = {6,8,2,1,9};
    int len = sizeof(x)/sizeof(int);
     for(int i=0;i<len;i++){
       printf("%d ",x[i]);
    }
    printf("\n");
    //bubble_sort(x,len);
    mergeSort(x,0,len-1);
    
    for(int i=0;i<len;i++){
       printf("%d ",x[i]);
    }
    printf("\n");

    return 0;
}