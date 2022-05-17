#include <iostream>
#include <map>
#include <vector>

#include <classes.h>

int main()
{
    std::cout << "test_virtual_inheritance" << std::endl;

    arma::mat M1 = { { 0, 1, 2 },
                     { 3, 4, 5 } };
    arma::mat M2 = { { 6,  7,  8 },
                     { 9, 10, 11 } };

    //------------------------------------------------------------------------------------------------------------------
    std::cout << "\n test 1 - Without rhomb \n" << std::endl;

    B<2, 3> instanceB1;
    instanceB1.IntegerA = 1;
    instanceB1.MatrixA = M1;

    B<2, 3> instanceB2;
    instanceB2.IntegerA = 2;
    instanceB2.MatrixA = M2;

    instanceB1.MatrixA.print( "B1.MatrixA before:" );
    instanceB2.MatrixA.print( "B2.MatrixA before:" );

    instanceB1 = instanceB2; // То, ради чего всё вот это вот делается
    instanceB2.MatrixA.zeros();

    instanceB1.MatrixA.print( "B1.MatrixA after:" );
    instanceB2.MatrixA.print( "B2.MatrixA after:" );

    //------------------------------------------------------------------------------------------------------------------
    std::cout << "\n test 2 - With rhomb \n" << std::endl;

    D<2,3> instanceD1;
    instanceD1.IntegerA = 1;
    instanceD1.MatrixA = M1;

    D<2,3> instanceD2;
    instanceD2.IntegerA = 2;
    instanceD2.MatrixA = M2;

    D<2,3> instanceD3 = D<2,3>( instanceD2 );

    instanceD1.MatrixA.print( "D1.MatrixA before:" );
    instanceD2.MatrixA.print( "D2.MatrixA before:" );
    instanceD3.MatrixA.print( "D3.MatrixA before:" );

    instanceD1 = instanceD2; // То, ради чего всё вот это вот делается

    instanceD1.MatrixA.print( "D1.MatrixA after:" );
    instanceD2.MatrixA.print( "D2.MatrixA after:" );

    //------------------------------------------------------------------------------------------------------------------
    std::cout << "\n test 3 - With rhomb, use std::map \n" << std::endl;

    instanceD1.IntegerA = 1;
    instanceD1.MatrixA = M1;

    instanceD2.IntegerA = 2;
    instanceD2.MatrixA = M2;

    std::map<int, D<2,3>> myMap;
    myMap.insert( std::make_pair( 1, instanceD1 ) );
    myMap.insert( std::make_pair( 2, instanceD2 ) );

    myMap.at( 1 ).MatrixA.print();
    myMap.at( 2 ).MatrixA.print();

    myMap.at( 1 ) = myMap.at( 2 ); // То, ради чего всё вот это вот делается

    for( auto &a : myMap ) {
        std::cout << ( a.first ) << std::endl;
        ( a.second ).MatrixA.print();
    }

    myMap.erase( 2 );

    for( auto &a : myMap ) { // new
        std::cout << ( a.first ) << std::endl;
        ( a.second ).MatrixA.print();
    }

    //------------------------------------------------------------------------------------------------------------------
    std::cout << "\n test 4 - With rhomb, use std::vector \n" << std::endl;

    instanceD1.IntegerA = 1;
    instanceD1.MatrixA = M1;

    instanceD2.IntegerA = 2;
    instanceD2.MatrixA = M2;

    std::vector< D<2, 3> > myVec;
    myVec.push_back( instanceD1 );
//    for( auto &v : myVec ) {
//        v.MatrixA.print();
//    }
    myVec.push_back( instanceD2 );
    for( auto &v : myVec ) {
        v.MatrixA.print();
    }

    myVec.erase( myVec.begin() ); // OK

    for( auto &v : myVec ) {
        v.MatrixA.print();
    }

    return 0;
}
