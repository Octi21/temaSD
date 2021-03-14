#include <iostream>
#include <vector>
#include <time.h>
#include <algorithm>
using namespace std;

void bubbleSort(vector <int>& v)
{
    int i,j;
    for(i=0;i<v.size();i++)
        for(j=0;j<v.size()-i-1;j++)
            if(v[j]>v[j+1])
                swap(v[j],v[j+1]);
    //for(int e : v)
      //  cout<<e<<" ";
}


void interClasare(vector <int>& v,int l,int m,int r)
{
    //int n1 = m- l +1;
    //int n2 = r-m;
    int /*arr1[n1], arr2[n2] ,*/ i,j,k;
   // for(i=0;i<n1;i++)
       // arr1[i] = arr[l+i];
   // for(j=0;j<n2;j++)
      //  arr2[j] = arr[m+1+j];

    //vector <int> v1 (v.begin()+l ,v.begin() +l + n1);
    //vector <int> v2 (v.begin() +m+1, v.begin()+m+1+n2);
    vector <int> v1 (v.begin()+l ,v.begin() +m+1);
    vector <int> v2 (v.begin() +m+1, v.begin()+r+1);


    //for(i=0;i<n1;i++)
       // v1.push_back(v[l+i]);

   // for(j=0;j<n2;j++)
       // v2.push_back(v[m+1+j]);
   /* cout<<"elem din v1 = ";
    for(int elem: v1)
      cout<<elem<<" ";
    cout<<endl;
    cout<<"elem din v2 = ";
    for(int elem: v2)
      cout<<elem<<" ";
    cout<<endl; */
    i=0;
    j=0;
    k=l;
    int n1 = v1.size(), n2=v2.size();
    while(i<n1 && j<n2)
    {
        if(v1[i]<=v2[j])
        {
            v[k] = v1[i];
            ++i;
        }
        else
        {
            v[k] = v2[j];
            ++j;
        }
        ++k;
    }
    while(i<n1)
    {
        v[k] = v1[i];
        ++k;
        ++i;
    }
    while(j<n2)
    {
        v[k] = v2[j];
        ++k;
        ++j;
    }
}
void mergeSort(vector <int>& v, int l, int r)
{
    if(l>=r)
        return;
    int m = l + (r-l)/2;
    //int m = (l+r)/2;
    mergeSort(v,l,m);
    mergeSort(v,m+1,r);
    interClasare(v,l,m,r);

}



void countSortPeCifre(vector <int>& v, int n, int exp)
{
    ///int copie[n];
    vector <int> vcopie(v.begin(), v.end());
    int maxx = v[0],i;
   // for(i=1;i<n;i++)
    //if(arr[i]>maxx)
          //  maxx=arr[i];
    int frec[10]={0};
    //for(i=0;i<=maxx;i++)
     //   frec[i]=0;
    //for(i=0;i<n;i++)
       // frec[(arr[i]/exp) %10]++;
    for(int elem: v)
    {
        frec[(elem/exp) %10]++;
    }
    for(i=1;i<10;i++)
        frec[i] = frec[i] + frec[i-1];
    for(i=n-1;i>=0;i--)
    {
        vcopie[frec[(v[i]/exp)%10]-1] = v[i];

        frec[(v[i]/exp)%10]--;
    }
    for(i=0;i<n;i++)
    {
        v[i] = vcopie[i];
       // cout<<arr[i]<<" ";
    }
}

void radixSort(vector <int>& v, int n)
{
    int i,maxx=v[0],exp;
    for(i=1;i<n;i++)
        if(v[i]>maxx)
            maxx=v[i];
    for(exp=1;maxx/exp>0;exp*=10)
        countSortPeCifre(v,n,exp);
}



void countSort(vector <int>& v)
{
    vector <int> copie(v.begin(),v.end());
    int maxx = v[0],i;
    for(int element : v)
        if(element > maxx)
            maxx = element;
    vector <int> frec;
    for(i=0;i<=maxx;i++)
        frec.push_back(0);
    for(int element : v)
        frec[ element ] ++;
    for(int i=1;i<=frec.size();++i)
        frec[i] += frec[i-1];
    for (int element : v)
    {
        copie [frec[element] -1] = element;
        frec[element]--;
    }
    for(int i=0;i<v.size();++i)
    {
        v[i] = copie[i];
      // cout<<v[i]<<" ";
    }


}



int med3(int x, int y, int z)
{
    if ((x>y) xor (x>z))
        return x;
    else
        if ((y<x) xor (y<z))
            return y;
        else
            return z;
}

void quickSort(vector <int>& v, int st, int dr)
{

    int i = st, j = dr;
    int aux;

    //int pivot = v[(st + dr) / 2];
    int pivot = med3(v[st],v[(st+dr)/2],v[dr]);
    while (i <= j)
    {

        while (v[i] < pivot)

            i++;

        while (v[j] > pivot)

            j--;

        if (i <= j)
        {

            aux = v[i];

            v[i] = v[j];

            v[j] = aux;

            i++;

            j--;
          //swap(v[i],v[j]);

        }

    }

    if (st < j)

        quickSort(v, st, j);

    if (i < dr)

        quickSort(v, i, dr);

}



void afis(vector <int> v)
{
     for(int elem: v)
       cout << elem <<" ";
    cout<<endl;
}
void generare(vector <int>& v, int n, int m)
{
    for(int i=0;i<n;++i)
     {

         v.push_back(rand() %m +1);

     }
}

void verifica(vector <int> v, int n)
{
    bool ok =true;
    for(int i = 0;i<n-1;i++)
        if(v[i] > v[i+1])
        {
            ok = false;
            break;
        }
    if(ok)
        cout<<"Sortat Corect"<<endl;
    else
        cout<<"Nu e sortat corect"<<endl;
}
int main()
{
    srand(time(NULL));
    vector <int> v;
    int i,n,m;
    cout<<"n = ";
    cin>>n;
    cout<<"m = ";
    cin>>m;
    clock_t start;
    clock_t sfarsit;
    double secunde;
    if(n<=100000000)
    {
    cout<<endl<<"QuickSort :"<<endl;
    generare(v,n,m);
    //afis(v);

    start = clock();
    quickSort(v,0,v.size()-1);
    sfarsit = clock();
    secunde = double(sfarsit-start) / CLOCKS_PER_SEC;
    cout<<"time QuickSort == "<< secunde<<endl;
    verifica(v,n);
    //afis(v);
    }
    else
        cout<<endl<<"pt n = "<<n<<" QuickSort-ul dureaza prea mult"<<endl;

    if(n<=1000000000)
    {
    v.clear();
    cout<<endl<<"CountSort :"<<endl;
    generare(v,n,m);
    //afis(v);

    start = clock();
    countSort(v);
    sfarsit = clock();
    secunde = double(sfarsit-start) / CLOCKS_PER_SEC;
    cout<<"time CountSort == "<< secunde<<endl;
    //afis(v);
    }
    else
         cout<<endl<<"pt n = "<<n<<" CountSort-ul dureaza prea mult"<<endl;

    if(n<=100000000)
    {
    v.clear();
    cout<<endl<<"RadixSort :"<<endl;
    generare(v,n,m);
    //afis(v);

    start = clock();
    radixSort(v,v.size());
    sfarsit = clock();
    secunde = double(sfarsit-start) / CLOCKS_PER_SEC;
    cout<<"time RadixSort== "<< secunde<<endl;
    //afis(v);
    }
    else
        cout<<endl<<"pt n = "<<n<<" RadixSort-ul dureaza prea mult"<<endl;

    if(n<=100000000)
    {
    v.clear();
    cout<<endl<<"MergeSort :"<<endl;
    generare(v,n,m);
    //afis(v);

     start = clock();
    mergeSort(v,0,v.size());
    sfarsit = clock();
    secunde = double(sfarsit-start) / CLOCKS_PER_SEC;
    cout<<"time MergeSort== "<< secunde<<endl;
    //afis(v);
    }
    else
        cout<<endl<<"pt n = "<<n<<" MergeSort-ul dureaza prea mult"<<endl;


    if(n<=100000000)
    {
    v.clear();
    cout<<endl<<"SortSTL :"<<endl;
    generare(v,n,m);
    //afis(v);

    start = clock();
    sort(v.begin(),v.end());
    sfarsit = clock();
    secunde = double(sfarsit-start) / CLOCKS_PER_SEC;
    cout<<"time SortSTL == "<< secunde<<endl;
    //afis(v);
    }
    else
        cout<<endl<<"pt n = "<<n<<" Sort-ul din STL dureaza prea mult"<<endl;


    if(n<=100000)
    {
    v.clear();
    cout<<endl<<"BubbleSort :"<<endl;
    generare(v,n,m);
    //afis(v);

    start = clock();
    bubbleSort(v);
    sfarsit = clock();
    secunde = double(sfarsit-start) / CLOCKS_PER_SEC;
    cout<<"time BubbleSort == "<< secunde<<endl;
    //afis(v);
    }
    else
        cout<<endl<<"pt n = "<<n<<" BubbleSort-ul dureaza prea mult"<<endl;


    return 0;
}
