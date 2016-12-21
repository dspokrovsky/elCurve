#ifndef CURVEMONTGOMETY_HPP
#define CURVEMONTGOMETY_HPP

#include <iostream>
#include <gcrypt.h>
#include <point.hpp>


class curveMontgomety
{
public:
    curveMontgomety(const gcry_mpi_t &b_,const gcry_mpi_t&a_,const gcry_mpi_t &p_);
    ~curveMontgomety();
    //Нахождение y^2 подстановкой x в уравнение кривой by^2=x^3+a*x^2+x (p)
    gcry_mpi_t GetF(const gcry_mpi_t &x);

    // Вычисление y = f(x)^((p+1)/4) (p) при допущении, p = 3 (4)
    gcry_mpi_t GetY(gcry_mpi_t x);


    // Критерий Эйлера: f(x) - квадратичный вычет в p или нет?
    int EulerCriteria(const gcry_mpi_t &fx);

    // Проверка принадлежности аффинной точки к кривой
    int aBelonging(const aPoint &Point);

    // Проверка принадлежности проективной точки к кривой
    int pBelonging(const pPoint &Point);

    // build point
    int buildRandomPoint(Point &P);



    
private:
    gcry_mpi_t b,a,p;
};

#endif // CURVEMONTGOMETY_HPP
