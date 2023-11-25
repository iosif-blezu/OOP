#pragma once
#include <iostream>
#include "Movie.h"
template <typename TEelem>

class DynamicArray
{
private:
    TEelem* elements;
    int index;
    int capacity;
    void resize();

public:
    DynamicArray(const int capacity);

    int getCapacity() const;
    int getIndex() const;
    TEelem getSpecificElement(int pos) const;
    void addElem(const TEelem& element);
    void deleteElem(int pos);
    void updateElem(int pos, TEelem element);

};
template <typename TElem>
DynamicArray<TElem> ::DynamicArray(const int capacity)
{
    this->index =0;
    this->capacity=capacity;
    this->elements = new TElem[this->capacity];
}

template <typename TElem>
void DynamicArray<TElem>::resize()
{
    this->capacity*=2;
    TElem* elemente = new TElem[this->capacity];
    for(int i=0;i<=this->index;i++)
        elemente[i]=this->elements[i];
    delete[] this->elements;
    this->elements = elemente;
}

template <typename TElem>
int DynamicArray<TElem>::getCapacity() const
{
    return this->capacity;
}

template <typename TElem>
int DynamicArray<TElem>::getIndex() const
{
    return this->index;
}

template <typename TElem>
TElem DynamicArray<TElem>::getSpecificElement(int pos) const
{
    return this->elements[pos];
}


template <typename TElem>
void DynamicArray<TElem>::addElem(const TElem& element)
{
    if(this->index == this->capacity)
        this->resize();
    this->elements[this->index]=element;
    this->index++;
}
template <typename TElem>
void DynamicArray<TElem>::deleteElem(int pos)
{
    int j=0;
    TElem* elemente = new TElem[this->capacity];
    for(int i=0;i<=this->index;i++)
    {
        if(i==pos)
            j++;
        elemente[i]=this->elements[j];
        j++;
    }

    delete[] this->elements;
    this->elements = elemente;
    this->index--;
}

template <typename TElem>
void DynamicArray<TElem>::updateElem(int pos, TElem element)
{
    this->elements[pos] = element;
}