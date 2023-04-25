#pragma once
#include "get_index.h"

//âû÷èñëèòü èíäåêñû ôèãóðû
bool get_index(std::string str_index, size_t& row_index, size_t& col_index) {

    for (int i = 0; i < str_index.size(); i++) {
        //index_find = ýëåìåíò ïîäñòðîêè
        auto index_find = str_index[i];

        //åñëè èíäåêñ ýëåìåíòà ñòðîêè [0]
        if (i == 0) {

            //temp = (êîë-âî ñòðîê - 1) - command[0] (îñòàòîê ñòîëáöîâ)
            auto temp = 'g' - index_find;

            //èíäåêñ ñòîëáöà = êîë-âî ñòðîê - îñòàòîê ñòîëáöîâ - 1
            col_index = 8 - temp - 1;
        }
        else if (i == 1) {
            //èíäåêñ ñòðîêè = char êîë-âî ñòðîê - char command[1]
            row_index = '8' - index_find;
        }
    }
    return row_index, col_index;
}