#include "get_index.h"

//вычислить индексы фигуры
bool get_index(std::string str_index, size_t& row_index, size_t& col_index) {

    for (int i = 0; i < str_index.size(); i++) {
        //index_find = элемент подстроки
        auto index_find = str_index[i];

        //если индекс элемента строки [0]
        if (i == 0) {

            //temp = (кол-во строк - 1) - command[0] (остаток столбцов)
            auto temp = 'g' - index_find;

            //индекс столбца = кол-во строк - остаток столбцов - 1
            col_index = 8 - temp - 1;
        }
        else if (i == 1) {
            //индекс строки = char кол-во строк - char command[1]
            row_index = '8' - index_find;
        }
    }
    return row_index, col_index;
}