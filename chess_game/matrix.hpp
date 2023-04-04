#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>
#include <random>
#include <vector>

using namespace std;

template<typename T>

class Matrix {
    public:
        //конструктор по умолчанию
        Matrix(){ 
            _rows = 0;
            _columns = 0;
        }

        //конструктор
        Matrix(size_t rows, size_t cols){
            _rows = rows; 
            _columns = cols; 
            _vec.resize(rows * cols);
        }

        void print(){
            for (int i = 0; i < _rows; i++) {
                for (int j = 0; j < _columns; j++) {
                    //номер строки * кол-во столбцов(считая с 1) + номер элемента в строке
                    cout  << _vec[i * _columns + j] << "  "; 
                }
                cout << endl;
            }
        }

        //заполнение числовой матрицы случайными числами 
        void fill_random(){
            srand(time(0));
            for (int i = 0; i < _rows; i++){
                for (int j = 0; j < _columns; j++){
                    _vec[i * _columns + j] = (rand());
                }
            }
        }

        //функция заполнения вектора значениями массива, аргументы функции = указатель на массив, размер массива
        void fill(T *array, size_t array_size){
            int k = 0;
            for (int i = 0; i < _rows; i++){
                for (int j = 0; j < _columns; j++){
                    _vec[i * _columns + j] = (array[k]);
                    k++;
                }
            }
        }

        //константный перегруженный оператор
        // T operator()(size_t row, size_t col, T value=0) const{
        //     if ((row >= _rows) || (col >= _columns)){
        //         throw "out of boundary";
        //     }
        //     return _vec[row * _columns + col]; 
        // }

        T& operator()(size_t row, size_t col){
            if ((row >= _rows) || (col >= _columns)){
                throw "out of boundary";
            }
            return _vec[row * _columns + col]; 
        }
        
        /*
        template<typename T>
        void set_submatrix(size_t row, size_t col, const Matrix<T>& sumbatrix){
            
        }

        template<typename T>
        T& get_submatrix(size_t row, size_t col){

        }
        */ 

    private:
        vector<T> _vec;
        size_t _rows, _columns;     
};

#endif //MATRIX_HPP