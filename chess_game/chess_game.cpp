#include <iostream>

#include "matrix.hpp"
#include "move_figure.h"
#include "set_array.h"
#include <string>

#include "get_index.h"

int main(){

    Matrix<std::string>* chessboard = set_array();

    chessboard->print();

    cout << endl;
      
    auto res = move_figure(*chessboard, true, "a2a3");

    chessboard->print();

  
}
