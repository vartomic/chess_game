#pragma once

#include "move_figure.h"
#include "matrix.hpp"
#include "get_index.h"
#include <iostream>
#include <regex>

//LK! проверка что пешка может переместиться на нужную позицию
bool isPawnCanMove(
    //LK! наша доска с фигурами
    Matrix<std::string>& chessboard,
    //LK! место откуда идет пешка
    int row_start, int col_start,
    //LK! место куда идет пешка
    int row_fin, int col_fin
    ) {

    //LK! начинаем проверку всех возможный вариантов

    //Рассмотрим пока случай когда на финальной позиции никого нет !!!
    // 
    //1.Проверим что на позиции [row_fin,col_fin] никого нет (--)
    //1.1 Пешка может ходить только по вертикали, проверим что (col_fin-col_start) равен 0
    //1.2 Проверим белая ли наша пешка, если да, то пешка может ходить только вверх
    //    1.2.1 Проверим стоит ли наша пешка на 2 линии, если да то пешка может походить на 1 или 2 клетки вверх
    //          Проверим что row_fin на 1 или 2 выше row_start
    //    1.2.2 Иначе пешка ушла со 2 линии и row_fin может быть только на 1 выше чем row_start
    //1.3 Если пешка не белая, значит черная и может ходить только вниз
    //    1.3.1 Проверим стоит ли наша пешка на 7 линии, если да, то пешка может походить на 1 или 2 клетки вниз
    //          Проверим что row_fin на 1 или 2 ниже row_start
    //    1.3.2 Иначе пешка ушла с 7 линии и row_fin может быть только на 1 ниже row_start

    //если все проверки прошли, то возвращаем true. То есть наша пешка может так походить
    return true;
}

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
    
    size_t row_start = 0; size_t col_start = 0;
    size_t row_fin = 0; size_t col_fin = 0;

    //��������� ������� ������� �� ������
    std::string index_first = command.substr(0, 2);

    //��������� ������� ������� �� ������
    std::string index_second = command.substr(2, 4);

    //LK! место откуда идет наша фигура
    get_index(index_first, row_start, col_start);

    string val_start = chessboard(row_start, col_start);

    //LK! место куда идет наша фигура
    get_index(index_second, row_fin, col_fin);

    string val_fin = chessboard(row_fin, col_fin);

    if (val_start == "--") {
        if (val_start == val_fin) {
            return false;
        }
    }
  
    //LK! проверка что на начальной позиции наш цвет
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

    //LK! val_start[1] - тип фигуры
    //LK! выбираем нужный тип
    switch (val_start[1]) {
        case 'p':
            //LK! наш тип это пешка
            if (!isPawnCanMove(chessboard, 
                row_start,col_start, 
                row_fin,col_fin)) {
                /*LK! если фукнция вернула false, сюда нельзя ходить*/
                return false;
            }
        break;
    }

    //chessboard(row_index, col_index) = "--";

    //get_index(index_second, row_index, col_index);

   // chessboard(row_index, col_index) = "wp";

    
    return 0;
}
