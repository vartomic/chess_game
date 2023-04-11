#include <iostream>
#include <random>
#include <vector>

#include "matrix.hpp"

#include "get_index.h"


//ход фигуры
bool move_figure(Matrix<std::string>& chessboard, bool is_white, std::string command) {

    bool first_move = true;
    bool previous_color = false;

    //проверка на пустоту строки
    if (command.empty()) {
        cout << "String is empty";
    }
    else {
        //если первый ход и это ход черных фигур = ошибка
        if (first_move == true && is_white == false) {
            throw "First move should do white";
        }
        //если первый ход и это ход белых
        else if (first_move == true && is_white == true) {

            //индекс строки, индекс столбца
            size_t row_index = 0; size_t col_index = 0;

            //выделение первого индекса из строки
            std::string index_first = command.substr(0, 2);

            //выделение второго индекса из строки
            std::string index_second = command.substr(2, 4);

            get_index(index_first, row_index, col_index);

            chessboard(row_index, col_index) = "--";

            get_index(index_second, row_index, col_index);

            chessboard(row_index, col_index) = "wp";

            first_move = false;
            previous_color = is_white;
        }
        //если ход не первый и предыдущий цвет равен текущему = ошибка
        else if (first_move == false && previous_color == is_white) {
            throw "Other color should make a move";
        }
    }
    return 0;
}



int main(){
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
    size_t arr_size = sizeof(arr)/sizeof(arr[0]);

    chessboard.fill(arr, arr_size);
    
    chessboard.print();

    cout << endl;

    auto res = move_figure(chessboard, true, "b2b4");

    chessboard.print();
    
}
