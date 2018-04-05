#ifndef Math_h
#define Math_h

namespace Quark {
    class Math {
    public:
        static bool IsEqual(const float a, const float b);
        static bool IsZero(const float a);
        static float Clamp(float x, float a, float b);
        static float Lerp(float a, float b, float t);
        static float Radians(float degrees);
        static float Degrees(float radians);
        
        static float Sin(float angle);
        static float Cos(float angle);
        static float Tan(float angle);
        static float Asin(float angle);
        static float Acos(float angle);
        static float Atan(float angle);
        
        static const float pi;
        static const int degrees;
        static const float degrees_to_radians;
    };
}

#endif /* Math_h */