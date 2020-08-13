#pragma once
#include <list>
#include <iostream>
#include <string>
using namespace std;

class backwardList{
    private:
        list<int> int_list;
    public:
        void insert(const int *arr);
        int find_first(int x);
        void remove_from_list(int x);
        void print_list(void);
};