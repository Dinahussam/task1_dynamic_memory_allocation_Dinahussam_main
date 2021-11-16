#include "MyArray.h"
#include <iostream>
using namespace std;

template <class T>
MyArray<T>::MyArray(){
    data=new T[capacity];

}

template <class T>
MyArray<T>::MyArray(T*arr, int size){
    this->size=size;
    data=new T[capacity];
    if(size>=capacity){
        capacity=capacity*2;
    }
    for(int counter=0;counter!=size;counter++){
        data[counter]=arr[counter];
    }
}

template<class T>
T MyArray<T>::get(int index){
    return data[index];
}
template<class T>
void MyArray<T>:: push(T element){
    if (size==capacity){
        expansion();
    }
    data[size]=element;
    size++;
}

template<class T>
T MyArray<T>::pop(){
    if(size==0){
        return -1;
    }
    T ptr=data[size-1];
    size--;
    shrinkage();
    return ptr;
}


template<class T>
void MyArray<T>::insert(int index, T element){
    size++;
    if(size==capacity){
        expansion();
    }
    for(int i=size-1;i>index;i--){
        data[i]=data[i-1];
    }
    data[index]=element;

}



template<class T>
T MyArray<T>::remove(int index){
    if(index<size){
        T tmp = data[index+1];
        T removed_elem = data[index];
        for(int counter = index;counter < size;counter++){
            data[counter] = tmp;
            if(counter < size-1)
                tmp= data[counter+2];
        }
        size--;
        shrinkage();
        return removed_elem;

    }
    else{
        return -1;
    }

}

template<class T>
void MyArray<T>::print(){
    cout<<"[";
    for(int i=0;i<size-1;i++){
        cout<<data[i]<<",";
    }
    cout<<data[size-1]<<"]";
}

template <class T>
int MyArray<T>::get_size(){
    return size;
}

template <class T>
int MyArray<T>::get_capacity(){
    return capacity;
}


template<class T>
void MyArray<T>::expansion(){
    // if(size==capacity){
    capacity=capacity*2;
    T* ptr =new T[capacity];
    for (int i=0;i<size;i++){
        ptr[i]=data[i];
    }
    delete[]data;
    data=ptr;
}
//}

template <class T>
void MyArray<T>::shrinkage(){
    if(size==capacity/4){
        capacity=capacity/2;
        T* ptr =new T[capacity];
        for (int i=0;i!=size;i++){
            ptr[i]=data[i];
        }
        delete[]data;
        data=ptr;
    }
}

