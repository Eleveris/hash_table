#include <iostream>
#include "hash_table.h"

using namespace std;

int main(){
    hash_table z(7);

    z.add_element(13);
    z.add_element(12);
    if (z.find_element(13)) cout << "true\n";
    else cout << "false\n";
    z.delete_element(13);
    if (z.find_element(13)) cout << "true\n";
    else cout << "false\n";
    z.print_table();
    return 1;
}
