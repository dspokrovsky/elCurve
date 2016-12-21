#ifndef POINT_HPP
#define POINT_HPP


#include <iostream>
#include <gcrypt.h>



class Point
{
public:
    Point(){
        x = gcry_mpi_new(0);
        y = gcry_mpi_new(0);
        z = gcry_mpi_new(0);
    }
    ~Point(){
        gcry_mpi_release(x);
        gcry_mpi_release(y);
        gcry_mpi_release(z);
    }
/*
    void print(){
        std::cout << "x = ";
      //  show_mpi(x);
        std::cout << "y = ";
       // show_mpi(y);
        std::cout << "z = ";
     //   show_mpi(z);
    }*/
//TODO accessors
//private:
    gcry_mpi_t x;
    gcry_mpi_t y;
    gcry_mpi_t z;
};



class aPoint: public Point
{
};

class pPoint: public Point
{
    /*
    Point(aPoint p){
        x = gcry_mpi_copy (p.x);
        y = gcry_mpi_copy (p.y);
        z = gcry_mpi_copy (p.z);
        //TODO
        //void gcry_mpi_div (gcry_mpi_t q, gcry_mpi_t r, gcry_mpi_t dividend, gcry_mpi_t divisor, int round)


    }
    Point(){
        x = gcry_mpi_new(0);
        y = gcry_mpi_new(0);
        z = gcry_mpi_new(0);
    }
    ~Point(){
        gcry_mpi_release(x);
        gcry_mpi_release(y);
        gcry_mpi_release(z);
    }

    void print(){
        std::cout << "x = ";
        show_mpi(x);
        std::cout << "y = ";
        show_mpi(y);
        //TODO удалить вывод z
        std::cout << "z = ";
        show_mpi(z);
    }*/
};
#endif
