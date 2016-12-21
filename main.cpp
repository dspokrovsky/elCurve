#include <iostream>

#include <gcrypt.h>
#include <point.hpp>
#include <curvemontgomety.hpp>
using namespace std;


struct
{
    const char *p = "00FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFD97";
    const char *a = "00C2173F1513981673AF4892C23035A27CE25E2013BF95AA33B22C656F277E7335";
    const char *b = "00295F9BAE7428ED9CCC20E7C359A9D41A22FCCD9108E17BF7BA9337A6F8AE9513";
    const char *q = "00400000000000000000000000000000000FD8CDDFC87B6635C115AF556C360C67";
} ko;

void show_mpi(gcry_mpi_t mpi)
{
    unsigned char *check_buf = (unsigned char *)malloc(254);
    memset(check_buf, '\0', 254);
    gcry_mpi_print(GCRYMPI_FMT_HEX, check_buf, 254, NULL, mpi);
    printf("%s\n", check_buf);
}

int main()
{
    gcry_mpi_t b;
    gcry_mpi_t a;
    gcry_mpi_t p;
    p = gcry_mpi_new(255);
    a = gcry_mpi_new(0);
    b = gcry_mpi_new(0);
        //gcry_mpi_randomize(p, 254, GCRY_WEAK_RANDOM);
    gcry_mpi_scan(&p, GCRYMPI_FMT_HEX, ko.p, 0, NULL);
    gcry_mpi_scan(&a, GCRYMPI_FMT_HEX, ko.a, 0, NULL);
    gcry_mpi_scan(&b, GCRYMPI_FMT_HEX, ko.b, 0, NULL);
    Point pp;

    curveMontgomety myC(b,a,p);

    myC.buildRandomPoint(pp);
    show_mpi(b);
    return 0;
}
