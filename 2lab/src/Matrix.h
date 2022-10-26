#ifndef INC_2LAB_MATRIX_H
#define INC_2LAB_MATRIX_H

#include "Vector.h"

/*!
 * \breif Класс квадратных матриц
 * @tparam T - тип элементов матрицы
 * @tparam L - размерность матрицы
 *
 * Данные хранятся построчно.
 */
template<typename T, std::size_t L>
class Matrix {
public:
    explicit Matrix();

    explicit Matrix(const std::array<std::array<T, L>, L> &array);

    Matrix(std::initializer_list<std::initializer_list<T>> list);

    explicit Matrix(const T &diagElem);

    explicit Matrix(const Vector<T, L - 1> &v);

    Matrix(const Matrix<T, L> &other);

    std::array<T, L> operator[](const std::size_t &pos);

    const std::array<T, L> &operator[](const std::size_t &pos) const;

    Vector<T, L> operator*(const Vector<T, L> &vec) const;

    Matrix<T, L> operator*(const Matrix<T, L> &other) const;

    Matrix<T, L> &operator=(const Matrix<T, L> &other);

    void operator*=(const Matrix<T, L> &other);

    template<typename TT, std::size_t LL>
    friend std::ostream &operator<<(std::ostream &os, const Matrix<TT, LL> &matrix);

private:
    std::array<std::array<T, L>, L> data_;
};

template<typename T, std::size_t L>
Matrix<T, L>::Matrix(): Matrix(static_cast<T>(0)) {}

template<typename T, std::size_t L>
Matrix<T, L>::Matrix(const std::array<std::array<T, L>, L> &array) {
    data_ = array;
}

template<typename T, std::size_t L>
Matrix<T, L>::Matrix(std::initializer_list<std::initializer_list<T>> list) {
    std::size_t i = 0;
    std::size_t j = 0;
    for (auto it1 = list.begin(); it1 != list.end(); ++it1, ++i) {
        for (auto it2 = it1->begin(); it2 != it1->end(); ++it2, ++j) {
            data_[i][j] = *it2;
        }
        j = 0;
    }
}

template<typename T, std::size_t L>
Matrix<T, L>::Matrix(const T &diagElem) {
    for (std::size_t i = 0; i < L; ++i) {
        for (std::size_t j = 0; j < L; ++j) {
            data_[i][j] = (i == j) ? diagElem : static_cast<T>(0);
        }
    }
}

template<typename T, std::size_t L>
Matrix<T, L>::Matrix(const Vector<T, L - 1> &v): Matrix(static_cast<T>(1)) {
    for (std::size_t i = 0; i < L - 1; ++i) {
        data_[i][i] *= v[i];
    }
}

template<typename T, std::size_t L>
std::array<T, L> Matrix<T, L>::operator[](const size_t &pos) {
    if (pos >= L) {
        throw std::out_of_range("Index is " + std::to_string(pos));
    }
    return data_[pos];
}

template<typename T, std::size_t L>
Matrix<T, L>::Matrix(const Matrix<T, L> &other) {
    data_ = other.data_;
}

template<typename T, std::size_t L>
const std::array<T, L> &Matrix<T, L>::operator[](const size_t &pos) const {
    if (pos >= L) {
        throw std::out_of_range("Index is " + std::to_string(pos));
    }
    return data_[pos];
}

template<typename T, std::size_t L>
Vector<T, L> Matrix<T, L>::operator*(const Vector<T, L> &vec) const {
    Vector<T, L> res;
    for (std::size_t i = 0; i < L; ++i) {
        for (std::size_t j = 0; j < L; ++j) {
            res[i] += data_[i][j] * vec[j];
        }
    }
    return res;
}

template<typename T, std::size_t L>
Matrix<T, L> Matrix<T, L>::operator*(const Matrix<T, L> &other) const {
    Matrix<T, L> res;
    for (std::size_t i = 0; i < L; ++i) {
        for (std::size_t j = 0; j < L; ++j) {
            for (std::size_t k = 0; k < L; ++k) {
                res.data_[i][j] += this->data_[i][k] * other.data_[k][j];
            }
        }
    }
    return res;
}

template<typename T, std::size_t L>
Matrix<T, L> &Matrix<T, L>::operator=(const Matrix<T, L> &other) {
    data_ = other.data_;
    return *this;
}

template<typename T, std::size_t L>
void Matrix<T, L>::operator*=(const Matrix<T, L> &other) {
    *this = *(this) * other;
}

template<typename TT, std::size_t Size>
std::ostream &operator<<(std::ostream &os, const Matrix<TT, Size> &matrix) {
    for (auto &row: matrix.data_) {
        os << "( ";
        for (auto &el: row) {
            os << el << " ";
        }
        os << ")" << std::endl;
    }
    return os;
}


#endif //INC_2LAB_MATRIX_H
