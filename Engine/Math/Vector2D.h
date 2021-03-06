#ifndef ENGIPIXI_VECTOR2D_H
#define ENGIPIXI_VECTOR2D_H

#include <iostream>

enum Direction{
    X,
    Y
};

class Vector2D{
//private:
public:
    float x;
    float y;

    Vector2D();
    Vector2D(float x, float y);

    Vector2D& add(const Vector2D& vector);
    Vector2D& subtract(const Vector2D& vector);
    Vector2D& multiply(const Vector2D& vector);
    Vector2D& divide(const Vector2D& vector);
    Vector2D normalized();
    
    float magnitude() const;

    friend Vector2D& operator+(Vector2D& v1, const Vector2D& v2);
    friend Vector2D& operator-(Vector2D& v1, const Vector2D& v2);
    friend Vector2D& operator*(Vector2D& v1, const Vector2D& v2);
    friend Vector2D& operator/(Vector2D& v1, const Vector2D& v2);

    Vector2D& operator*(const int & i);
    Vector2D& operator*(const float & f);
    
    Vector2D& zero();

    Vector2D& operator+=(const Vector2D& vector);
    Vector2D& operator-=(const Vector2D& vector);
    Vector2D& operator*=(const Vector2D& vector);
    Vector2D& operator/=(const Vector2D& vector);

    friend std::ostream& operator<<(std::ostream& stream, const Vector2D& vector);
};
#endif //ENGIPIXI_VECTOR2D_H
