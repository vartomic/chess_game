#include <iostream>
#include <random>
#include <vector>

#include "matrix.hpp"

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

//ход фигуры
bool move_figure(Matrix<std::string>& chessboard, bool is_white, std::string command){

    bool first_move = true;
    bool previous_color = false;

    //проверка на пустоту строки
    if (command.empty()) {
        throw "String is empty";
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

    auto res = move_figure(chessboard, true, "");

    chessboard.print();
    
}
