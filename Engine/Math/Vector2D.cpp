#include "Vector2D.h"

Vector2D::Vector2D(float x, float y) : x(x), y(y) {}

Vector2D::Vector2D() {
    this->x = 0.0f;
    this->y = 0.0f;
}

Vector2D &Vector2D::add(const Vector2D &vector) {
    this->x += vector.x;
    this->y += vector.y;

    return *this;
}

Vector2D &Vector2D::subtract(const Vector2D &vector) {
    this->x -= vector.x;
    this->y -= vector.y;

    return *this;
}

Vector2D &Vector2D::multiply(const Vector2D &vector) {
    this->x *= vector.x;
    this->y *= vector.y;

    return *this;
}

Vector2D &Vector2D::divide(const Vector2D &vector) {
    this->x /= vector.x;
    this->y /= vector.y;

    return *this;
}

Vector2D &operator+(Vector2D &v1, const Vector2D &v2) {
    return v1.add(v2);
}

Vector2D &operator-(Vector2D &v1, const Vector2D &v2) {
    return v1.subtract(v2);
}

Vector2D &operator*(Vector2D &v1, const Vector2D &v2) {
    return v1.multiply(v2);
}

Vector2D &operator/(Vector2D &v1, const Vector2D &v2) {
    return v1.divide(v2);
}


Vector2D& Vector2D::operator+=(const Vector2D& vector){
    return this->add(vector);
}
Vector2D& Vector2D::operator-=(const Vector2D& vector){
    return this->subtract(vector);
}
Vector2D& Vector2D::operator*=(const Vector2D& vector){
    return this->multiply(vector);
}
Vector2D& Vector2D::operator/=(const Vector2D& vector){
    return this->divide(vector);
}

std::ostream &operator<<(std::ostream &stream, const Vector2D &vector) {
    stream << "(" << vector.x << "," << vector.y << ")";
    return stream;
}



