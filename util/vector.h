#ifndef COOL_RR_UTIL_VECTOR
#define COOL_RR_UTIL_VECTOR

#include "../config.h"

namespace raven2d {

    template <typename T>
    class Vector2 {
    public:
        Vector2(T xp=0, T yp=0): x(xp), y(xp) { }
        Vector2(const raven2d::Vector2<T> &vec):
            x(vec.x), y(vec.y) { }

        T x, y;
    };

    typedef Vector2<int>  Vector2i;
    typedef Vector2<uint> Vector2u;
    typedef Vector2<real> Vector2f;

}

#endif
