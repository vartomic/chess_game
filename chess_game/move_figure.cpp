#pragma once

#include "move_figure.h"
#include "matrix.hpp"
#include "get_index.h"
#include <iostream>

//ход фигуры
bool move_figure(Matrix<std::string>& chessboard, bool is_white, std::string command){

    //проверка на пустоту строки
    if (command.empty()) {
        cout << "String is empty";
    }
    
    size_t row_index = 0; size_t col_index = 0;

    //выделение первого индекса из строки
    std::string index_first = command.substr(0, 2);

    //выделение второго индекса из строки
    std::string index_second = command.substr(2, 4);

    get_index(index_first, row_index, col_index);

    chessboard(row_index, col_index) = "--";

    get_index(index_second, row_index, col_index);

    chessboard(row_index, col_index) = "wp";
    
    return 0;
}