#pragma once

#include "move_figure.h"
#include "matrix.hpp"
#include "get_index.h"
#include <iostream>
#include <regex>

//��� ������
bool move_figure(Matrix<std::string>& chessboard, bool is_white, std::string command){

    regex reg("[abcdefgh][0-8][abcdefgh][0-8]");


    //�������� �� ������� ������
    if (command.empty()) {
        return false;
    }
    if (command.length() != 4) {
        return false;
    }
    if (!regex_search(command, reg)) {
        return false;
    }
    
    size_t row_index = 0; size_t col_index = 0;

    //��������� ������� ������� �� ������
    std::string index_first = command.substr(0, 2);

    //��������� ������� ������� �� ������
    std::string index_second = command.substr(2, 4);

    get_index(index_first, row_index, col_index);

    string val_start = chessboard(row_index, col_index);

    get_index(index_second, row_index, col_index);

    string val_fin = chessboard(row_index, col_index);

    if (val_start == "--") {
        if (val_start == val_fin) {
            return false;
        }
    }
  
    if (is_white) {
        if (val_start.find('b') != std::string::npos){
            return false;
        }
    }   
    if (!is_white) {
        if (val_start.find('w') != std::string::npos){
            return false;
        }
    }


    //chessboard(row_index, col_index) = "--";

    //get_index(index_second, row_index, col_index);

   // chessboard(row_index, col_index) = "wp";
    
    return 0;
}
