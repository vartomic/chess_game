#pragma once

#include "set_array.h"
#include "matrix.hpp"

#include <string>

string* set_array() {
    Matrix<std::string> chessboard(9, 9);

    std::string arr[] = {
        "8","br","bn","bb","bk","bq","bb","bn","br",
        "7","bp","bp","bp","bp","bp","bp","bp","bp",
        "6","--","--","--","--","--","--","--","--",
        "5","--","--","--","--","--","--","--","--",
        "4","--","--","--","--","--","--","--","--",
        "3","--","--","--","--","--","--","--","--",
        "2","wp","wp","wp","wp","wp","wp","wp","wp",
        "1","wr","wn","wb","wk","wq","wb","wn","wr",
        " " , "a ", "b ", "c " , "d ", "e ", "f ", "g ", "h "
    };

    //кол-во элементов массива = размер массива(байт)/размер любого эелемента массива || размер типа массива
    size_t arr_size = sizeof(arr) / sizeof(arr[0]);


    chessboard.fill(arr, arr_size);

    return &chessboard;


}


