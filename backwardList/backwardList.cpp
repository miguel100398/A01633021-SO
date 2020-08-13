#include "backwardList.h"
#include <iostream>
#include <string>
using namespace std;


void backwardList::insert(const int *arr){
    for (int i=0; i<10; i++){
        int_list.push_back(arr[i]);
    }
}

int backwardList::find_first(int x){
    if (x > 9){
        return find_first(x/10);
    }else{
        return x;
    }
}

void backwardList::remove_from_list(int x){
    list<int> tmp = int_list;
    auto it = int_list.end();
    it--;
    for (int i =int_list.size(); i>0; i--){
    if (find_first(tmp.front())==x){
            int_list.erase(it);
            break;
        }
        tmp.pop_front();
        it--;
    }
}

void backwardList::print_list(){
    list<int> tmp_list = int_list;
    for(int i=0; i<int_list.size(); i++){
        cout << to_string(tmp_list.front()) + " ";
        tmp_list.pop_front();
    }
    cout << "\n";
}

int main(void){
    int remove;
    const int tmp[10] = {456, 92, 361, 416, 915, 647, 60, 778, 35, 406};
    backwardList *backwardlist= new backwardList();
    backwardlist->insert(tmp);
    backwardlist->print_list();
    cout <<"Enter digit";
    cin >> remove;
    if (remove<0||remove>9){
        cout << "Error";
    }else{
        backwardlist->remove_from_list(remove);
        backwardlist->print_list();
    }
}