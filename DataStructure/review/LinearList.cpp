//Linear List(Sequential List)


//ADT of 1D Array
#include <iostream>
#include <stdlib.h>
template <class T>
class Array{
private:
    T *elements;
    int ArraySize;
    void getArray();
public:
    Array(int Size = DefaultSize);//constructor
    Array(const Array<T>& x);//copy constructor
    ~Array(){delete []elements}
    Array<T> & operator = (const Array<T> & A);
    T & operator [] (int i);
    T * operator () const{return elements;}
    int Length() const{return ArraySize;}
    void ReSize(int sz);
}

template <class T>
void Array<T>::getArray(){
    elements = new T[ArraySize];
    if(elements == 0){
        ArraySize = 0;
        cerr<<"Error"<<endl;
        return;
    }
}

template <class T>
Array<T>::Array(int sz){
    if(sz<0){
        ArraySize = 0;
        cerr<<"Invalid size"<<endl;
        return;
    }
    ArraySize = sz;
    getArray();
}

template <class T>
Array<T>::Array(const Array<T> & x){
    int n = ArraySize = x.ArraySize;
    elements = new T[n];
    if(elements == 0){
        ArraySize = 0;
        cerr<<"Error"<<endl;
        return;
    }
    T *srcptr = x.elements;
    T *destptr = elements;
    while(n--) *destptr++ = * srcptr++;
}

template <class T>
T & Array<T>::operator[](int i){
    if(i<0 || i>ArraySize-1){
        cerr<<"out bound"<<endl;
        return NULL;
    }
    return elements[i];
}

template class<T>
void Array<T>::ReSize(int sz){
    if(sz>=0 && sz!=ArraySize){
        T * newarray = new T[sz];
        if(newarray = 0){
            cerr<<"Error"<<endl;
            return;
        }
        int n = (sz<=ArraySize)?sz:ArraySize;
        T *srcptr = elements;
        T *destptr = newarray;
        while(n--) *destptr++ = *srcptr++;
        delete []elements;
        elements = newarray;
        ArraySize = sz;
    }
}



//ADT of Sequential List
template <class T>
class SeqList{
private:
    T *data;
    int MaxSize;
    int last;
public:
    SeqList (int MaxSize = DefaultSize);
    ~SeqList(){delete [] data;}
    int Length()const{return last+1}
    int Find(T & x) const;
    int IsIn(T & x);
    int Insert(T & x, int i);
    int Remove(T & x);
    int Prior(T & x);
    int Next(T & x);
    int IsEmpty(){return last == -1;}
    int IsFull(){return last==MaxSize-1;}
    T Get(int i){
        return i<0||i>last?NULL:data[i];
    }
}

template <class T>
SeqList<T>::SeqList(int sz){
    if(sz>0){
        MaxSize = sz;
        last = -1;
        data = new T[MaxSize];
        if(data == NULL){
            MaxSize = 0;
            last = -1;
            return;
        }
    }
}

template class<T>
SeqList<T>::Find(T & x)const{
    int i=0;
    while(i<=last && data[i]!=x)
        i++;
    if(i>last) return -1;
    else return i;
}

template <class T>
int SeqList<T>::Insert(T & x, int i){
    if(i<0||i>last+1||last==MaxSize-1)
        return 0;
    else{
        last++;
        for(int j=last;j>i;j--){
            data[j] = data[j-1];
        }
        data[i] = x;
        return 1;
    }
}

template <class T>
int SeqList<T>::Remove(T & x){
    int i = Find(x);
    if(i>=0){
        last--;
        for(int j=i;j<last;j++){
            data[j] = data[j+1];
        }
        return 1;
    }
    return 0;
}

//Union of two Sets 并集
template <class T>
void Union(SeqList<T> & LA, SeqList<T> & LB){
    int n = LA.Length();
    int m = LB.Length();
    for(int i=1;i<=m;i++){
        T x = LB.Get(i);
        int k = LA.Find(x);
        if(k==-1){
            LA.Insert(x,n+1);
            n++;
        }
    }
}

//Intersection of two sets
template <class T>
void Intersection(SeqList<T> & LA, SeqList<T> & LB){
    int n = LA.Length();
    int m = LB.Length();
    int i=0;
    while(i<n){
        T x = LA.Get(i);
        int k = LB.Find(x);
        if(k==-1){
            LA.Remove(i);
            n--;
        }
        else i++;
    }    
}

//Merge two sorted list
template <class T>
SeqList & Merge_List(SeqList<T> & LA, SeqList<T> & LB){
    int n = LA.Length();
    int m = LB.Length();
    SeqList LC(m+n);
    
    int i=j=k=0;
    while(i<n && j<m){
        T x = LA.Get(i);
        T y = LB.Get(j);
        if(x<=y){
            LC.Insert(k,x);
            i++;
            k++;
        }
        else{
            LC.Insert(k,y);
            j++;
            k++;            
        }
    }
    while(i<n){
        T x = LA.Get(i);
        LC.Insert(k,x);
        i++;
        k++;  
    }
    while(j<m){
        T y = LA.Get(i);
        LC.Insert(k,y);
        j++;
        k++;  
    }
    return LC;    
}
