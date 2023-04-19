#include <iostream>

#include "matrix.hpp"
#include "move_figure.h"
#include "set_array.h"

#include <string>

int main(){

    string* pointer = set_array();

    *pointer = chessboard;
      
    auto res = move_figure(chessboard, true, "b2b4");

    chessboard.print();
    
}
