#include <iostream>
#include "hash_table.h"

using namespace std;

int main(){
    hash_table z(7);

    for (int i=0; i < 25; i++){
        z.add_element(i);
    }
    if (z.delete_element(3)) cout << "true" << "\n" ;
    else cout << "false" << "\n";
    if (z.delete_element(8)) cout << "true" << "\n" ;
    else cout << "false" << "\n";
    if (z.delete_element(13)) cout << "true" << "\n" ;
    else cout << "false" << "\n";
    if (z.delete_element(23)) cout << "true" << "\n" ;
    else cout << "false" << "\n";
    z.print_table();
    return 1;
}
