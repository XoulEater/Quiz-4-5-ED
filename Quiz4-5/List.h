#include "Node.h"

#ifndef LIST 

#define LIST 1

// 2. ajustar a que esta lista sea doblemente enlazada, cambia el add, find, insert y el remove
template <class T>
class List {
    private:
        Node<T> *first;
        Node<T> *last;
        int quantity;
        bool empty;
        Node<T> *searchPosition = NULL;
        Node<T> *searchBehind = NULL;

    public:
        List() {
            first = NULL;
            last = NULL;
            quantity = 0;
            empty = true;
        }

        void add(T *pData) {
            Node<T> *newNode = new Node<T>(pData);

            if (quantity>0) {
                this->last->setNext(newNode);
                newNode->setPrev(this->last);        //  []  []
            } else {
                this->first = newNode;
            }
            this->last = newNode;

            empty = false;
            quantity++;
        }

        Node<T>* getFirst() {
            return this->first;
        }

        Node<T>* getLast() {
            return this->last;
        }

        int getSize() {
            return quantity;
        }

        bool isEmpty() {
            return !quantity;
        }

        T* find(int pPosition) {
            T* result = NULL;
            searchPosition = this->first;

            if (pPosition<getSize()) {
                while(pPosition>0) {
                    searchBehind = searchPosition;
                    searchPosition = searchPosition->getNext();
                    pPosition--;
                } 
            }
            return result = searchPosition->getData();
        }


        // es que si el position es mayor a la cantidad, entonces inserto al final
        void insert(int pPosition, T *pData) {

            if (pPosition<getSize() && first!=NULL) {
                Node<T> *newNodo = new Node<T>(pData);


                T* result = find(pPosition);

                newNodo->setNext(searchPosition);

                if (searchBehind!=NULL) {
                    searchBehind->setNext(newNodo);
                    newNodo->setPrev(searchBehind);

                    searchPosition->setPrev(newNodo);
                    newNodo->setNext(searchPosition);
                } else {
                    newNodo->setNext(this->first);
                    this->first->setPrev(newNodo);
                    this->first = newNodo;
                }
                quantity++;
            } else {
                add(pData);
            }
        }

        bool remove(int pPosition) {
            bool result = false;
            if (this->first!=NULL && pPosition<getSize()) {
                Node<T> *search = this->first;
                if (pPosition!=0) {
                    
                    T* result = find(pPosition);

                    searchBehind->setNext(searchPosition->getNext());
                    
                    if (searchPosition==this->last) {
                        this->last = searchBehind;
                    } else {
                        searchPosition->getNext()->setPrev(searchBehind);
                    }
                    searchPosition->setNext(NULL);
                    searchPosition->setPrev(NULL);
                    delete searchPosition;
                } else {
                    this->first = this->first->getNext();
                    this->first->setPrev(NULL);
                    search->setNext(NULL);
                    delete search;
                }

                quantity--;
            }
            return result;
        } 
};

#endif