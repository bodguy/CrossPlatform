#ifndef Vector2d_h
#define Vector2d_h

namespace Quark {
    class Vector2d {
    public:
        Vector2d();
        //! constructor with two elements
        Vector2d(const float tx, const float ty);
        //! copy constructor
        Vector2d(const Vector2d& other);
        //! assignment operator
        Vector2d& operator = (Vector2d other);
        
        //! add, add and assignment operator
        Vector2d operator +(const Vector2d& other) const;
        Vector2d& operator +=(const Vector2d& other);
        
        //! subtract, assignment operator
        Vector2d operator -(const Vector2d& other) const;
        Vector2d& operator -=(const Vector2d& other);
        
        //! multiply, assignment operator
        Vector2d operator *(const Vector2d& other) const;
        Vector2d& operator *=(const Vector2d& other);
        
        Vector2d operator /(const Vector2d& other) const;
        Vector2d& operator /=(const Vector2d& other);
        
        static float CrossProduct(const Vector2d& a, const Vector2d& b);
        static float DotProduct(const Vector2d& a, const Vector2d& b);
        
        //! add by scalar
        Vector2d operator +(const float scalar) const;
        Vector2d& operator +=(const float scalar);
        
        //! subtract by scalar
        Vector2d operator -(const float scalar) const;
        Vector2d& operator -=(const float scalar);
        
        //! multiply by scalar
        Vector2d operator *(const float scalar) const;
        Vector2d& operator *=(const float scalar);
        
        //! divided by scalar
        Vector2d operator /(const float scalar) const;
        Vector2d& operator /=(const float scalar);
        
        //! vector comparison
        bool operator <(const Vector2d& other) const;
        bool operator >(const Vector2d& other) const;
        bool operator <=(const Vector2d& other) const;
        bool operator >=(const Vector2d& other) const;
        bool operator ==(const Vector2d& other) const;
        bool operator !=(const Vector2d& other) const;
        
        //! scalar comparison
        bool operator <(const float scalar) const;
        bool operator >(const float scalar) const;
        bool operator <=(const float scalar) const;
        bool operator >=(const float scalar) const;
        bool operator ==(const float scalar) const;
        bool operator !=(const float scalar) const;
        
        //! unary operator
        Vector2d operator -() const;
        Vector2d operator +() const;
        
        Vector2d Perpendicular();
        Vector2d& Normalize();
        float Magnitude();
        float Distance(const Vector2d& other);
        float DistanceSqrare(const Vector2d& other);
        
        //! linear interpolation
        static Vector2d Lerp(const Vector2d& a, const Vector2d& b, float t); // Linear Interpolation
        static Vector2d Slerp(const Vector2d& a, const Vector2d& b, float t); // Sphere Linear Interpolation
        static Vector2d Nlerp(const Vector2d& a, const Vector2d& b, float t); // Normalized Linear Interpolation
        
        float x, y;
        
    private:
        void Swap(Vector2d& fisrt, Vector2d& second);
    };
}

#endif /* Vector2d_h */