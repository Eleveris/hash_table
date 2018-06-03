//
// Created by User on 01.03.2018.
//

#ifndef HASH_TABLE_HASH_TABLE_H
#define HASH_TABLE_HASH_TABLE_H


#include <stddef.h>
#include <iostream>
using namespace std;


class hash_table{

    struct list{
        list *prev;
        int value;
        list *next;

        list(){
            prev = NULL;
            value = 0;
            next = NULL;
        }

        list(list * p, int v, list * n){
            prev = p;
            value = v;
            next = n;
        }
    };



    int size;

public: //interface to interact with data
    hash_table(int key);

    ~hash_table();



    bool add_element(int element);

    bool find_element(int element);

    bool delete_element(int element);

    bool print_list(int key);

    bool print_table();

private:

    list **hash;

    bool get_key(int element, int *key); //searching element in hash point list

    bool search(int element, int *key, list **element_list);
    //same creation and delete function in hash point list

};



#endif //HASH_TABLE_HASH_TABLE_H
