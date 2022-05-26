//----------------------------------------------------------------------------------------------------------------------
///
/// \file       test_classes.cpp
/// \brief      Тестирование классов с наследованием
/// \date       25.05.22 - создан
/// \author     Соболев А.А.
///

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE test_classes

#include <iostream>
#include <armadillo>
#include <boost/test/unit_test.hpp>
#include <vector>
#include <map>

#include <classes.h>

const size_t dimX = 2;
const size_t dimY = 3;

arma::mat M1 = { { 1, 2, 3 },
                 { 4, 5, 6 } };
arma::mat M2 = { {  7,  8,  9 },
                 { 10, 11, 12 } };
arma::mat M3 = { { 13, 14, 15 },
                 { 16, 17, 18 } };
arma::mat Mzeros = arma::zeros( dimX, dimY );

const double eps = 1.0e-6;

BOOST_AUTO_TEST_CASE( test_1 )
{
    std::cout << "\ntest_1" << std::endl;
    C<dimX, dimY> instanceC1;
    instanceC1.IntegerA = 1;
    instanceC1.MatrixA = M1;

    C<dimX, dimY> instanceC2;
    instanceC2.IntegerA = 2;
    instanceC2.MatrixA = M2;

    instanceC1.MatrixA.print( "C1.MatrixA before:" );
    instanceC2.MatrixA.print( "C2.MatrixA before:" );

    instanceC1 = instanceC2; // То, ради чего всё вот это вот делается
    instanceC2.MatrixA.zeros();
    BOOST_CHECK_EQUAL( arma::approx_equal( instanceC1.MatrixA, M2, "absdiff", eps ), true );
    BOOST_CHECK_EQUAL( arma::approx_equal( instanceC2.MatrixA, Mzeros, "absdiff", eps ), true );

    instanceC1.MatrixA.print( "C1.MatrixA after:" );
    instanceC2.MatrixA.print( "C2.MatrixA after:" );
}

BOOST_AUTO_TEST_CASE( test_2 )
{
    std::cout << "\ntest_2" << std::endl;
    D<dimX, dimY> instanceD1;
    instanceD1.IntegerA = 1;
    instanceD1.MatrixA = M1;

    D<dimX, dimY> instanceD2;
    instanceD2.IntegerA = 2;
    instanceD2.MatrixA = M2;

    instanceD1.MatrixA.print( "D1.MatrixA before:" );
    instanceD2.MatrixA.print( "D2.MatrixA before:" );

    instanceD1 = instanceD2; // То, ради чего всё вот это вот делается
    instanceD2.MatrixA.zeros();
    BOOST_CHECK_EQUAL( arma::approx_equal( instanceD1.MatrixA, M2, "absdiff", eps ), true );
    BOOST_CHECK_EQUAL( arma::approx_equal( instanceD2.MatrixA, Mzeros, "absdiff", eps ), true );

    instanceD1.MatrixA.print( "D1.MatrixA after:" );
    instanceD2.MatrixA.print( "D2.MatrixA after:" );
}

BOOST_AUTO_TEST_CASE( test_3 )
{
    std::cout << "\ntest_3" << std::endl;
    E<dimX, dimY> instanceE1;
    instanceE1.IntegerA = 1;
    instanceE1.MatrixA = M1;

    E<dimX, dimY> instanceE2;
    instanceE2.IntegerA = 2;
    instanceE2.MatrixA = M2;

    instanceE1.MatrixA.print( "E1.MatrixA before:" );
    instanceE2.MatrixA.print( "E2.MatrixA before:" );

    instanceE1 = instanceE2; // То, ради чего всё вот это вот делается
    instanceE2.MatrixA.zeros();
    BOOST_CHECK_EQUAL( arma::approx_equal( instanceE1.MatrixA, M2, "absdiff", eps ), true );
    BOOST_CHECK_EQUAL( arma::approx_equal( instanceE2.MatrixA, Mzeros, "absdiff", eps ), true );

    instanceE1.MatrixA.print( "E1.MatrixA after:" );
    instanceE2.MatrixA.print( "E2.MatrixA after:" );
}

BOOST_AUTO_TEST_CASE( test_4 )
{
    std::cout << "\ntest_4" << std::endl;
    F<dimX, dimY> instanceF1;
    instanceF1.IntegerA = 1;
    instanceF1.MatrixA = M1;

    F<dimX, dimY> instanceF2;
    instanceF2.IntegerA = 2;
    instanceF2.MatrixA = M2;

    instanceF1.MatrixA.print( "F1.MatrixA before:" );
    instanceF2.MatrixA.print( "F2.MatrixA before:" );

    instanceF1 = instanceF2; // То, ради чего всё вот это вот делается
    instanceF2.MatrixA.zeros();
    BOOST_CHECK_EQUAL( arma::approx_equal( instanceF1.MatrixA, M2, "absdiff", eps ), true );
    BOOST_CHECK_EQUAL( arma::approx_equal( instanceF2.MatrixA, Mzeros, "absdiff", eps ), true );

    instanceF1.MatrixA.print( "F1.MatrixA after:" );
    instanceF2.MatrixA.print( "F2.MatrixA after:" );
}

BOOST_AUTO_TEST_CASE( test_5 )
{
    std::cout << "\ntest_5" << std::endl;
    G<dimX, dimY> instanceG1;
    instanceG1.IntegerA = 1;
    instanceG1.MatrixA = M1;

    G<dimX, dimY> instanceG2;
    instanceG2.IntegerA = 2;
    instanceG2.MatrixA = M2;

    instanceG1.MatrixA.print( "G1.MatrixA before:" );
    instanceG2.MatrixA.print( "G2.MatrixA before:" );

    instanceG1 = instanceG2; // То, ради чего всё вот это вот делается
    instanceG2.MatrixA.zeros();
    BOOST_CHECK_EQUAL( arma::approx_equal( instanceG1.MatrixA, M2, "absdiff", eps ), true );
    BOOST_CHECK_EQUAL( arma::approx_equal( instanceG2.MatrixA, Mzeros, "absdiff", eps ), true );

    instanceG1.MatrixA.print( "G1.MatrixA after:" );
    instanceG2.MatrixA.print( "G2.MatrixA after:" );
}

BOOST_AUTO_TEST_CASE( test_6 )
{
    std::cout << "\ntest_6" << std::endl;
    G<dimX, dimY> instanceG1;
    instanceG1.IntegerA = 1;
    instanceG1.MatrixA = M1;

    G<dimX, dimY> instanceG2;
    instanceG2.IntegerA = 2;
    instanceG2.MatrixA = M2;

    G<dimX, dimY> instanceG3;
    instanceG3.IntegerA = 3;
    instanceG3.MatrixA = M3;

    instanceG1.MatrixA.print( "G1.MatrixA before:" );
    instanceG2.MatrixA.print( "G2.MatrixA before:" );
    instanceG3.MatrixA.print( "G3.MatrixA before:" );

    std::vector< G<dimX, dimY> > myVec;
    myVec.push_back( instanceG1 );
    myVec.push_back( instanceG2 );
    myVec.push_back( instanceG3 );
//    myVec.erase( myVec.begin() );
    for( auto it = myVec.begin(); it != myVec.end(); ) {
        if( ( *it ).IntegerA == 2 ) {
            it = myVec.erase( it );
        } else {
            ++it;
        }
    }

    for( auto &v : myVec ) {
        std::cout << "MatrixA" << std::endl;
        v.MatrixA.print();
    }
}

BOOST_AUTO_TEST_CASE( test_7 )
{
    std::cout << "\ntest_7" << std::endl;
    A<dimX, dimY> instanceA1;
    instanceA1.IntegerA = 1;
    instanceA1.MatrixA = M1;

    A<dimX, dimY> instanceA2;
    instanceA2.IntegerA = 2;
    instanceA2.MatrixA = M2;

    A<dimX, dimY> instanceA3;
    instanceA3.IntegerA = 3;
    instanceA3.MatrixA = M3;

    instanceA1.MatrixA.print( "A1.MatrixA before:" );
    instanceA2.MatrixA.print( "A2.MatrixA before:" );
    instanceA3.MatrixA.print( "A3.MatrixA before:" );

    std::vector< A<dimX, dimY> > myVec;
    myVec.push_back( instanceA1 );
    myVec.push_back( instanceA2 );
    myVec.push_back( instanceA3 );
//    myVec.erase( myVec.begin() );
    for( auto it = myVec.begin(); it != myVec.end(); ) {
        if( ( *it ).IntegerA == 2 ) {
            it = myVec.erase( it );
        } else {
            ++it;
        }
    }

    for( auto &v : myVec ) {
        std::cout << "MatrixA" << std::endl;
        v.MatrixA.print();
    }
}
