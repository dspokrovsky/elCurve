#include "curvemontgomety.hpp"

curveMontgomety::curveMontgomety(const gcry_mpi_t &b_,const gcry_mpi_t&a_,const gcry_mpi_t &p_)
{
    b = gcry_mpi_copy(b_);
    a = gcry_mpi_copy(a_);
    p = gcry_mpi_copy(p_);

}

curveMontgomety::~curveMontgomety()
{
    gcry_mpi_release(p);
    gcry_mpi_release(a);
    gcry_mpi_release(b);
}



//Нахождение y^2 подстановкой x в уравнение кривой by^2=x^3+a*x^2+x (p)
gcry_mpi_t curveMontgomety::GetF(const gcry_mpi_t &x){
    gcry_mpi_t fx = gcry_mpi_new(0);
    gcry_mpi_t buf = gcry_mpi_new(0);
    gcry_mpi_set_ui(buf, 2);
    gcry_mpi_powm(fx, x, buf, p);
    gcry_mpi_mulm(fx, a, fx, p);
    gcry_mpi_set_ui(buf, 3);
    gcry_mpi_powm(buf, x, buf, p);
    gcry_mpi_addm(fx, buf, fx, p);
    gcry_mpi_addm(fx, fx, x, p);
    gcry_mpi_div(fx,0,fx,b,0);
    gcry_mpi_release(buf);
    return fx;
}

gcry_mpi_t curveMontgomety::GetY(gcry_mpi_t x){
    gcry_mpi_t fx = GetF(x);
    gcry_mpi_t y = gcry_mpi_new(0);
    gcry_mpi_t exp = gcry_mpi_new(0);
    gcry_mpi_t div = gcry_mpi_new(0);
    gcry_mpi_add_ui(exp, p, 1);
    gcry_mpi_set_ui(div, 4);
    gcry_mpi_div(exp, NULL, exp, div, 0);
    gcry_mpi_powm(y, fx, exp, p);
    gcry_mpi_release(exp);
    gcry_mpi_release(div);
    return y;
}

int curveMontgomety::EulerCriteria(const gcry_mpi_t &fx){
    gcry_mpi_t exp = gcry_mpi_new(0);
    gcry_mpi_t div = gcry_mpi_new(0);
    gcry_mpi_t X = gcry_mpi_new(0);
    gcry_mpi_sub_ui(exp, p, 1);
    gcry_mpi_set_ui(div, 2);
    gcry_mpi_div(exp, NULL, exp, div, 0);
    gcry_mpi_powm(X, fx, exp, p);
    int flg = gcry_mpi_cmp_ui(X,1);
    gcry_mpi_release(X);
    gcry_mpi_release(exp);
    gcry_mpi_release(div);
    return flg;
}

int curveMontgomety::aBelonging(const aPoint &point){
    gcry_mpi_t left = gcry_mpi_new(0);
    gcry_mpi_t exp = gcry_mpi_new(0);
    gcry_mpi_set_ui(exp, 2);
    gcry_mpi_powm(left, point.y, exp, p);
    gcry_mpi_t right = GetF(point.x);
    int cmp = gcry_mpi_cmp(left, right);
    gcry_mpi_release(left);
    gcry_mpi_release(right);
    return cmp;
}

int curveMontgomety::buildRandomPoint(Point &P){



    /*gcry_mpi_t buf;
    buf = gcry_mpi_new(254);
    gcry_mpi_randomize(buf, 254, GCRY_WEAK_RANDOM);
    int t = 10000; // TO DELETE
    while (EulerCriteria(GetF(P.x))!=0)
    {
        gcry_mpi_randomize(P.x, 254, GCRY_WEAK_RANDOM);
        if (t == 0 ) break; // TO DELETE
        t--; // TO DELETE
    }
    P.y = GetF(P.x);
    gcry_mpi_set_ui(P.z, 1);*/
    return 0;
}
