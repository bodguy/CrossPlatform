#ifndef Vector4d_h
#define Vector4d_h

namespace Quark {
    class Vector2d; class Vector3d;
    class Vector4d {
    public:
        //! default contructor
        Vector4d();
        //! constructor with three elements
        Vector4d(float tx, float ty, float tz, float tw);
        Vector4d(const Vector2d& other);
        Vector4d(const Vector3d& other);
        Vector4d(const Vector3d& other, float tw);
        //! copy constructor
        Vector4d(const Vector4d& other);
        //! assignment operator
        Vector4d& operator =(Vector4d other);
        
        //! add, add and assignment operator
        Vector4d operator +(const Vector4d& other) const;
        Vector4d& operator +=(const Vector4d& other);
        
        //! subtract, assignment operator
        Vector4d operator -(const Vector4d& other) const;
        Vector4d& operator -=(const Vector4d& other);
        
        //! multiply, assignment operator
        Vector4d operator *(const Vector4d& other) const;
        Vector4d& operator *=(const Vector4d& other);
        
        Vector4d operator /(const Vector4d& other) const;
        Vector4d& operator /=(const Vector4d& other);
        
        static float DotProduct(const Vector4d& a, const Vector4d& b);
        
        //! add by scalar
        Vector4d operator +(const float scalar) const;
        Vector4d& operator +=(const float scalar);
        
        //! subtract by scalar
        Vector4d operator -(const float scalar) const;
        Vector4d& operator -=(const float scalar);
        
        //! multiply by scalar
        Vector4d operator *(const float scalar) const;
        Vector4d& operator *=(const float scalar);
        
        //! divided by scalar
        Vector4d operator /(const float scalar) const;
        Vector4d& operator /=(const float scalar);
        
        //! vector comparison
        bool operator <(const Vector4d& other) const;
        bool operator >(const Vector4d& other) const;
        bool operator <=(const Vector4d& other) const;
        bool operator >=(const Vector4d& other) const;
        bool operator ==(const Vector4d& other) const;
        bool operator !=(const Vector4d& other) const;
        
        //! scalar comparison
        bool operator <(const float scalar) const;
        bool operator >(const float scalar) const;
        bool operator <=(const float scalar) const;
        bool operator >=(const float scalar) const;
        bool operator ==(const float scalar) const;
        bool operator !=(const float scalar) const;
        
        //! utility functions
        Vector4d& Normalize();
        float Magnitude();
        static Vector3d ToVector3d(const Vector4d& other);
        
        float x, y, z, w;
        
    private:
        void Swap(Vector4d& first, Vector4d& second);
    };
}

#endif /* Vector4d_h */