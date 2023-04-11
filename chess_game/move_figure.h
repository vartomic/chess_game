#pragma once

#include "matrix.hpp"
#include <string>

bool move_figure(Matrix<std::string>& chessboard, bool is_white, std::string command);