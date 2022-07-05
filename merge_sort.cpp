#include <iostream>
using namespace std;

void merge_aux(int *arr, int abajo, int alto, int medio)
{
    int i, j, k, elementos[20];
    i = abajo;
    k = abajo;
    j = medio + 1;

    while (i <= medio && j <= alto) {

        if (arr[i] < arr[j]) {
            elementos[k] = arr[i];
            k++;
            i++;
        }
        else  {
            elementos[k] = arr[j];
            k++;
            j++;
        }
    }
    while (i <= medio) {
        elementos[k] = arr[i];
        k++;
        i++;
    }
    while (j <= alto) {
        elementos[k] = arr[j];
        k++;
        j++;
    }
    for (i = abajo; i < k; i++)  {
        arr[i] = elementos[i];
    }
}

void merge_sort(int *arr, int abajo, int alto)
{
    int medio;

    if (abajo < alto ){
        medio=(abajo +alto)/2;
        merge_sort(arr,abajo,medio);
        merge_sort(arr,medio+1,alto);

        merge_aux(arr,abajo,alto,medio);
    }
}
int main()
{
    int myarray[30], num;
    cout<<"Cantidad de numeros a  ingresara?   =>";
    cin>>num;
    cout<<"-------------------------------------"<<endl;
    cout<<"ingrese los  =>  "<<num<<" elementos:"<<endl;

    for (int i = 0; i < num; i++) {
            cin>>myarray[i];
    }
    merge_sort(myarray, 0, num-1);

    cout<<"Array Ordenado \n";
    cout<<"---------------------------"<<endl;
    for (int i = 0; i < num; i++)
    {
        cout<<myarray[i]<<"\t";
    }
}
