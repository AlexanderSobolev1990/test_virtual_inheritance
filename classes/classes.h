//----------------------------------------------------------------------------------------------------------------------
///
/// \file       classes.h
/// \brief      Иерархия классов с ромбовидным наследованием
/// \date       25.05.22 - создан
/// \author     Соболев А.А.
///

#ifndef CLASSES_H
#define CLASSES_H

#include <iostream>
#include <armadillo>

std::string GetVersion();

//----------------------------------------------------------------------------------------------------------------------
template<size_t SizeX, size_t SizeY>
struct A
{
    A() : IntegerA( 0 ), MatrixA( arma::zeros( SizeX, SizeY ) ) {}

    A( const A& ) = default;
    A& operator=( const A& ) = default;
    A( A&& ) = default;
    A& operator=( A&& ) = default;
    virtual ~A() = default;

    int IntegerA;
    arma::mat MatrixA;
};
//----------------------------------------------------------------------------------------------------------------------
template<size_t SizeX, size_t SizeY>
struct B : A<SizeX, SizeY>
{
    B() : IntegerB( 0 ), MatrixB( arma::zeros( SizeX, SizeY ) ) {}

    virtual ~B() = default;

    int IntegerB;
    arma::mat MatrixB;    
};
//----------------------------------------------------------------------------------------------------------------------
template<size_t SizeX, size_t SizeY>
struct C : virtual B<SizeX, SizeY>
{
    C() : IntegerC( 0 ), MatrixC( arma::zeros( SizeX, SizeY ) ) {}

    int IntegerC;
    arma::mat MatrixC;
};
//----------------------------------------------------------------------------------------------------------------------
template<size_t SizeX, size_t SizeY>
struct D : virtual B<SizeX, SizeY>
{
    D() : IntegerD( 0 ), MatrixD( arma::zeros( SizeX, SizeY ) ) {}

    int IntegerD;
    arma::mat MatrixD;
};
//----------------------------------------------------------------------------------------------------------------------
template<size_t SizeX, size_t SizeY>
struct E : D<SizeX, SizeY>
{
    E() : IntegerE( 0 ), MatrixE( arma::zeros( SizeX, SizeY ) ) {}

    int IntegerE;
    arma::mat MatrixE;
};
//----------------------------------------------------------------------------------------------------------------------
template<size_t SizeX, size_t SizeY>
struct F : C<SizeX, SizeY>, E<SizeX, SizeY> {
    F() : IntegerF( 0 ), MatrixF( arma::zeros( SizeX, SizeY ) ) {}

    int IntegerF;
    arma::mat MatrixF;
};
//----------------------------------------------------------------------------------------------------------------------
template<size_t SizeX, size_t SizeY>
struct G : F<SizeX, SizeY>
{
    G() : IntegerG( 0 ), MatrixG( arma::zeros( SizeX, SizeY ) ) {}

    int IntegerG;
    arma::mat MatrixG;
};

/*
//----------------------------------------------------------------------------------------------------------------------
template<size_t SizeX, size_t SizeY>
struct D1 : virtual B<SizeX, SizeY>
{
    D1() : IntegerD1( 0 ), MatrixD1( arma::zeros( SizeX, SizeY ) ) {}

    int IntegerD1;
    arma::mat MatrixD1;
};
//----------------------------------------------------------------------------------------------------------------------
template<size_t SizeX, size_t SizeY>
struct E1 : D1<SizeX, SizeY>
{
    E1() : IntegerE1( 0 ), MatrixE1( arma::zeros( SizeX, SizeY ) ) {}

    int IntegerE1;
    arma::mat MatrixE1;
};
//----------------------------------------------------------------------------------------------------------------------
template<size_t SizeX, size_t SizeY>
struct F1 : C<SizeX, SizeY>, E1<SizeX, SizeY> {
    F1() : IntegerF1( 0 ), MatrixF1( arma::zeros( SizeX, SizeY ) ) {}

    int IntegerF1;
    arma::mat MatrixF1;
};
//----------------------------------------------------------------------------------------------------------------------
template<size_t SizeX, size_t SizeY>
struct G1 : F1<SizeX, SizeY>
{
    G1() : IntegerG1( 0 ), MatrixG1( arma::zeros( SizeX, SizeY ) ) {}

    int IntegerG1;
    arma::mat MatrixG1;
};
*/
#endif // CLASSES_H
