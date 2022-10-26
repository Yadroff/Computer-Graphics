#ifndef INC_2LAB_VECTOR_H
#define INC_2LAB_VECTOR_H

#include <array>
#include <initializer_list>
#include <iostream>
#include <cmath>


/*!
 *\breif  Класс вектора
 * @tparam T - тип координат
 * @tparam L - размерность вектора
 *
 * Представляет собой L-мерный вектор
 */
template<typename T, std::size_t L>
class Vector {
public:
    template<typename ... Types>
    explicit Vector(Types... args);

    Vector(std::initializer_list<T> list);

    Vector(const Vector<T, L> &v);

    Vector(const Vector<T, L - 1> &v, const T &val);

    explicit Vector(const T &val);

    Vector<T, L> operator*(const double &f) const;

    T operator*(const Vector<T, L> &other) const;

    Vector<T, L> &operator=(const Vector<T, L> &v);

    Vector<T, L> &operator*=(const double &f);

    template<typename Type, std::size_t Size>
    friend Vector<Type, Size> operator-(const Vector<Type, Size> &lhs, const Vector<Type, Size> &rhs);

    template<typename Type, std::size_t Size>
    friend Vector<Type, Size> operator+(const Vector<Type, Size> &lhs, const Vector<Type, Size> &rhs);

    T &operator[](std::size_t i);

    const T &operator[](std::size_t i) const;

    [[nodiscard]] std::size_t size() const;

    [[nodiscard]] double magnitude() const;

    void normalize();

    template<typename TS, std::size_t &Ll>
    friend std::ostream &operator<<(std::ostream &os, const Vector<TS, Ll> &vec);

    T x() const;

    T y() const;

    T z() const;

private:
    std::array<T, L> data_;
};

template<typename T, std::size_t L>
template<typename... Types>
Vector<T, L>::Vector(Types... args) {
    if (sizeof ...(args) != L) {
        data_.fill(static_cast<T>(0));
    } else {
        data_ = {args...};
    }
}

/*!
 * \breif Конструктор из сырых данных
 *
 * Использование: Vector(int, 3) vec = {1, 2, 3};
 * @tparam T - тип данных
 * @tparam L - размерность вектора
 * @param list - список координат
 */
template<typename T, std::size_t L>
Vector<T, L>::Vector(std::initializer_list<T> list) {
    std::size_t i = 0;
    for (auto it = list.begin(); it != list.end(); ++it) {
        data_[i++] = *it;
    }
}

template<typename T, std::size_t L>
Vector<T, L>::Vector(const Vector<T, L> &v) {
    data_ = v.data_;
}

template<typename T, std::size_t L>
Vector<T, L>::Vector(const Vector<T, L - 1> &v, const T &val) {
    for (std::size_t i = 0; i < L - 1; ++i) {
        data_[i] = v.data_[i];
    }
    data_[L - 1] = val;
}

template<typename T, std::size_t L>
Vector<T, L> Vector<T, L>::operator*(const double &f) const {
    Vector<T, L> res;
    for (std::size_t i = 0; i < L; ++i) {
        res.data_[i] = data_[i] * f;
    }
}

template<typename T, std::size_t L>
Vector<T, L> &Vector<T, L>::operator*=(const double &f) {
    *this = *this * f;
    return *this;
}

template<typename T, std::size_t L>
Vector<T, L> &Vector<T, L>::operator=(const Vector<T, L> &v) {
    this->data_ = v.data_;
    return *this;
}

template<typename T, std::size_t L>
T &Vector<T, L>::operator[](std::size_t i) {
    return data_[i];
}

template<typename T, std::size_t L>
const T &Vector<T, L>::operator[](std::size_t i) const {
    return data_[i];
}

template<typename T, std::size_t L>
std::size_t Vector<T, L>::size() const {
    return L;
}

/*!
 * Функция вычисления длины вектора
 * @return длину вектора
 */
template<typename T, std::size_t L>
double Vector<T, L>::magnitude() const {
    double res = 0;
    for (const auto &elem: data_) {
        res += elem * elem;
    }
    return std::sqrt(res);
}

/*!
 * Функция приводит вектор к нормальному виду
*/
template<typename T, std::size_t L>
void Vector<T, L>::normalize() {
    double len = magnitude();
    if (len == 0) {
        throw std::overflow_error("Divide by zero");
        return;
    }
    for (auto &elem: data_) {
        elem /= len;
    }
}

template<typename TS, size_t &Ll>
std::ostream &operator<<(std::ostream &os, const Vector<TS, Ll> &vec) {
    os << "{";
    for (auto &data: vec.data_) {
        os << data << " ";
    }
    os << "}";
    return os;
}

template<typename T, std::size_t L>
T Vector<T, L>::x() const {
    if (L >= 1) {
        return data_[0];
    }
    return static_cast<T>(0);
}

template<typename T, std::size_t L>
T Vector<T, L>::y() const {
    if (L >= 2) {
        return data_[1];
    }
    return static_cast<T>(0);
}

template<typename T, std::size_t L>
T Vector<T, L>::z() const {
    if (L >= 3) {
        return data_[2];
    }
    return static_cast<T>(0);
}

template<typename Type, std::size_t Size>
Vector<Type, Size> operator-(const Vector<Type, Size> &lhs, const Vector<Type, Size> &rhs) {
    Vector<Type, Size> res;
    for (std::size_t i = 0; i < Size; ++i) {
        res.data_[i] = lhs.data_[i] - rhs.data_[i];
    }
    return res;
}

template<typename Type, std::size_t Size>
Vector<Type, Size> operator+(const Vector<Type, Size> &lhs, const Vector<Type, Size> &rhs) {
    Vector<Type, Size> res;
    for (std::size_t i = 0; i < Size; ++i) {
        res.data_[i] = lhs.data_[i] + rhs.data_[i];
    }
    return res;
}

template<typename T, std::size_t L>
Vector<T, L>::Vector(const T &val) {
    for (std::size_t i = 0; i < L; ++i) {
        data_[i] = val;
    }
}

template<typename T, std::size_t L>
T Vector<T, L>::operator*(const Vector<T, L> &other) const {
    T res = static_cast<T>(0);
    for (std::size_t i = 0; i < L; ++i) {
        res += data_[i] * other.data_[i];
    }
    return res;
}


#endif //INC_2LAB_VECTOR_H