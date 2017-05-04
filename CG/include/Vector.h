#ifndef CG_VECTOR_H
#define CG_VECTOR_H

#include <cmath>
#include <initializer_list>

template<int size, typename T>
class Vector
{
public:
    friend class Matrix4;
    friend class Quaternion;
    Vector<size, T>() = default;
    Vector<size, T>(std::initializer_list<T> list);


    Vector<3, T> Cross(const Vector<3, T> &other)
    {
        return Vector<3, T>
                (
                        {            _vec[1] * other._vec[2] - _vec[2] * other._vec[1],
                                     _vec[2] * other._vec[0] - _vec[0] * other._vec[2],
                                     _vec[0] * other._vec[1] - _vec[1] * other._vec[0]
                        }
                );
    }

    Vector<3, T> operator%(const Vector<3, T> &other)
    {
        return this->Cross(other);
    }

    T Dot(const Vector<size, T> &other);
    T operator*(const Vector<size, T> &other);
    Vector<size, T> operator*(const float scale);
    Vector<size, T> &operator*=(const float scale);

    Vector<size, T> Add(const Vector<size, T> &other);
    Vector<size, T> operator+(const Vector<size, T> &other);
    Vector<size, T> operator+=(const Vector<size, T> &other);

    Vector<size, T> Sub(const Vector<size, T> &other);
    Vector<size, T> operator-(const Vector<size, T> &other);
    Vector<size, T> operator-=(const Vector<size, T> &other);
    Vector<size, T> operator-();

    float Length();

    Vector<size, T> &Normalize();
    Vector<size, T> Normalized();

    T &operator[](unsigned int index);

private:
    T _vec[size];
};

template <int size, typename T>
Vector<size, T>::Vector(std::initializer_list<T> list)
{
    int i = 0;
    for (typename std::initializer_list<T>::iterator it = list.begin(); i < size; ++i, ++it)
        _vec[i] = *it;
}


template <int size, typename T>
T& Vector<size, T>::operator[](unsigned int index)
{
    return _vec[index];
}

template <int size, typename T>
T Vector<size, T>::Dot(const Vector<size, T> &other)
{
    T res = 0;
    for (int i = 0; i < size; ++i)
        res += _vec[i] * other._vec[i];
    return res;
}

template <int size, typename T>
T Vector<size, T>::operator*(const Vector<size, T> &other)
{
    return this->Dot(other);
}

template <int size, typename T>
Vector<size, T> Vector<size, T>::operator*(const float scale)
{
    Vector<size, T> res;
    for (int i = 0; i < size; ++i)
        res._vec[i] = _vec[i] * scale;
    return res;
}

template <int size, typename T>
Vector<size, T>& Vector<size, T>::operator*=(const float scale)
{
    for (int i = 0; i < size; ++i)
        _vec[i] *= scale;
    return *this;
}

template <int size, typename T>
Vector<size, T> Vector<size, T>::Add(const Vector<size, T> &other)
{
    Vector<size, T> res;
    for (int i = 0; i < size; ++i)
        res._vec[i] = _vec[i] + other._vec[i];
    return  res;
}

template <int size, typename T>
Vector<size, T> Vector<size, T>::operator+(const Vector<size, T> &other)
{
    return this->Add(other);
}

template <int size, typename T>
Vector<size, T> Vector<size, T>::operator+=(const Vector<size, T> &other)
{
    for (int i = 0; i < size; ++i)
        _vec[i] += other._vec[i];
    return *this;
}

template <int size, typename T>
Vector<size, T> Vector<size, T>::Sub(const Vector<size, T> &other)
{
    Vector<size, T> res;
    for (int i = 0; i < size; ++i)
        res._vec[i] = _vec[i] - other._vec[i];
    return res;
}

template <int size, typename T>
Vector<size, T> Vector<size, T>::operator-(const Vector<size, T> &other)
{
    return this->Sub(other);
}

template <int size, typename T>
Vector<size, T> Vector<size, T>::operator-=(const Vector<size, T> &other)
{
    for (int i = 0; i < size; ++i)
        _vec[i] -= other._vec[i];
    return *this;
}

template <int size, typename T>
Vector<size, T> Vector<size, T>::operator-()
{
    Vector<size, T> res;
    for (int i = 0; i < size; ++i)
        res._vec[i] = -_vec[i];
    return res;
}

template <int size, typename T>
float Vector<size, T>::Length()
{
    T l = 0;
    for (int i = 0; i < size; ++i)
        l += _vec[i] * _vec[i];
    return sqrt(l);
}

template <int size, typename T>
Vector<size, T>& Vector<size, T>::Normalize()
{
    T l = this->Length();
    for (int i = 0; i < size; ++i)
        _vec[i] /= l;
    return *this;
}

template <int size, typename T>
Vector<size, T> Vector<size, T>::Normalized()
{
    Vector<size, T> res;
    T l = this->Length();
    for (int i = 0; i < size; ++i)
        res._vec[i] /= l;
    return res;
}


using Vec3f = Vector<3, float>;
using Vec4f = Vector<4, float>;
using Vec2f = Vector<2, float>;

class Vector3;
class Vector4;

class Vector4
{
public:
    friend class Vector3;
    friend class Quaternion;
    Vector4();
    Vector4(float x, float y, float z, float w = 0);
    Vector4(const Vector3 &other, float w);

    float Dot(const Vector4 &other);
    float operator*(const Vector4 &other);

    float Length();

    Vector4 &Normalize();

    Vector4 operator-();
    float &operator[](unsigned int index);
private:
    float _vec[4];
};

class Vector3
{
public:
    friend class Vector4;
    friend class Quaternion;
    Vector3();
    Vector3(float x, float y, float z);
    Vector3(const Vector4 &other);
    Vector3(const Vector3 &other);

    float Dot(const Vector3 &other);
    float operator*(const Vector3 &other);
    Vector3 operator*(const float scale);
    Vector3 &operator*=(const float scale);

    Vector3 Cross(const Vector3 &other);
    Vector3 operator%(const Vector3 &other);

    Vector3 Add(const Vector3 &other);
    Vector3 operator+(const Vector3 &other);
    Vector3 &operator+=(const Vector3 &other);

    Vector3 Sub(const Vector3 &other);
    Vector3 operator-(const Vector3 &other);
    Vector3 &operator-=(const Vector3 &other);

    Vector3 operator-();

    float Length();

    Vector3 &Normalize();

    float &operator[](unsigned int index);
private:
    float _vec[3];

};

#endif //CG_VECTOR_H