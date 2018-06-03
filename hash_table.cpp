//
// Created by User on 01.03.2018.
//

#include "hash_table.h"


hash_table::hash_table(int key) {

    this->size = key;
    this->hash = new list*[this->size]{NULL};
};

bool hash_table::add_element(int element) {
    int *key;
    list *active_list;
    key = new int;

    if (get_key(element, key)) {

        if (this->hash[*key] == NULL) {
            this->hash[*key] = new list{NULL, element, NULL};
        } else {
            active_list = this->hash[*key];
            while (1) {
                if (active_list->next == NULL) {
                    active_list->next = new list{active_list, element, NULL};
                    break;
                } else {
                    active_list = active_list->next;
                }
            }
        }

        return true;
    }
    else return false;
}

bool hash_table::delete_element(int element) {
    int *key;
    list **active_list;
    list *list_element;

    key = new int;

    active_list = new list*;
    if (get_key(element, key)){
        if (search(element, key, active_list)){
            if (((*active_list)->prev == NULL) && ((*active_list)->next == NULL)){
                this->hash[*key] = NULL;
                delete(*active_list);
            }
            else if (((*active_list)->prev == NULL) && ((*active_list)->next != NULL)){
                this->hash[*key] = (*active_list)->next;
                (*active_list)->next->prev = NULL;
                delete(*active_list);
            }
            else if (((*active_list)->prev != NULL) && ((*active_list)->next == NULL)){
                (*active_list)->prev->next = NULL;
                delete(*active_list);
            }
            else {
                (*active_list)->prev->next = (*active_list)->next;
                (*active_list)->next->prev = (*active_list)->prev;
                delete(*active_list);
            }
        }
        else return false;
    }
    else return false;

    return true;
}

bool hash_table::find_element(int element) {
    int *key;
    list **active_list;

    active_list = new list*;



    key = new int;
    if (get_key(element, key)) {
        if (search(element, key, active_list)) return true;
        else return false;

    } else return false;


}


bool hash_table::print_list(int key) {
    list *active_list;

    if (this->hash[key]!=NULL){
        active_list=this->hash[key];
    }
    else return false;

    while(1){
        cout << active_list->value << " ";
        if (active_list->next==NULL) break;
        else active_list=active_list->next;
    }

    return true;
}

bool hash_table::print_table() {
    int *key;
    int numb;
    key = new int;

    for (numb = 0; numb<this->size; numb++) {
        if (get_key(numb, key)) {
            if (this->hash[*key] != NULL) {
                cout << *key << ": ";
                print_list(*key);
                cout << "\n";
            }
        }
    }

    return true;
}


bool hash_table::get_key(int element, int *key) {

    *key = element%this->size;

    return true;
}

bool hash_table::search(int element, int *key, list **element_list) {
    list *active_list;
    active_list = this->hash[*key];
    if (active_list != NULL)
    while (1) {
        if (active_list->value == element) {
            *element_list = active_list;
            return true;
        }
        else if (active_list->next != NULL) active_list = active_list->next;
        else return false;
    }
    else return false;
}

hash_table::~hash_table() {
    int key=0;
    list *active_list;
    for (key; key<this->size; key++) {
        if (this->hash[key]!=NULL){
            active_list = this->hash[key];
            while (1){
                if (active_list->next==NULL) {
                    delete(active_list);
                    break;
                }
                else {
                    active_list=active_list->next;
                    delete(active_list->prev);
                }
            }
        }
    }

    delete(this->hash);
}

