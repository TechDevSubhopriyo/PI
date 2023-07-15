#include <iostream>
#include <string>
#include "Collide.h"

using namespace std ;

Object::Object(long int const m, double v):
    _m(m),
    _v(v)
{
}

Object::~Object()
{
}

void
Object::SetVelocity(double v)
{
    _v = v ;
}

string
Object::GetImage() const
{
    // Create image of current state of mass
    return "M: " + std::to_string(_m) + ", V: " + std::to_string(_v) ;
}

void
Object::Collide(Object &m2)
{
    /* 
     * Perfectly Elastic Collision - 
     * Law of conservation of momentum
     * m1*(*v1) + m2*(*v2) = m1*(*u1) + m2*(*v2) ;
     * Law of conservation of energy
     * m1*(*v1^2) + m2*(*v2^2) = m1*(*u1^2) + m2*(*v2^2) ;
    */
    double v1 = (((this->GetMass() - m2.GetMass()) * this->GetVelocity()) + (2 * m2.GetMomentum())) / (this->GetMass() + m2.GetMass()) ;
    double v2 = (((m2.GetMass() - this->GetMass()) * m2.GetVelocity()) + (2 * this->GetMomentum())) / (this->GetMass() + m2.GetMass()) ;
    this->SetVelocity(v1) ;
    m2.SetVelocity(v2) ;
}

void
Object::WallCollide()
{
    // Full elastic collision with wall will
    // change the direction of mass only
    this->SetVelocity(-(this->GetVelocity())) ;
}

void
ShowImage(Object m1 /* Smaller mass */, Object m2 /* Bigger mass */)
{
    cout<<m1.GetImage()<<endl ;
    cout<<m2.GetImage()<<endl ;
}

unsigned
Automate(Object m1 /* Smaller mass */, Object m2 /* Bigger mass */)
{
    unsigned count = 0 ;
    while((m2.GetMomentum() >= 0) || (m1.GetVelocity() < 0 && m1.GetVelocity() < m2.GetVelocity())) {
        // Two masses collide
        m2.Collide(m1) ;
        count ++ ;
        // Wall collide condition
        if (m1.GetVelocity()) {
            m1.WallCollide() ;
            count ++ ;
        }
    }
    return count ;
}

int main()
{
    long int mass ;
    cout<<"Mass Digits to get digits of pi: " ; cin>>mass ;
    Object m1(1, 0) ;
    cout<<"Object 1 created :"<<m1.GetImage()<<endl ;
    Object m2((pow(10, ((mass-1)*2))), 1) ;
    cout<<"Object 2 created :"<<m2.GetImage()<<endl ;
    // Automate the loop to print result
    cout<<Automate(m1, m2)<<endl ;
    return 0 ;
}
