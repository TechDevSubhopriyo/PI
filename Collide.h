#include <string>
#include <cmath>

class Object
{
public:
    // Prevent compiler from creating copy constructor
    Object operator=(Object&) ;

    Object(const long int m, double v) ;
    ~Object() ;

public:
    inline const long int           GetMass()               const { return _m ; }
    inline double                   GetVelocity()           const { return _v ; }
    inline double                   GetSpeed()              const { return abs(_v) ; }
    inline double                   GetMomentum()           const { return (_v * _m) ; }

    inline void                     SetVelocity(double v) ;

    void                            Collide(Object &m) ;
    void                            WallCollide() ;
    std::string                     GetImage()              const ;

private:
    const long int      _m ; // Mass
    double              _v ; // Velocity
} ; // class Object
