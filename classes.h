#ifndef CLASSES_H
#define CLASSES_H

#include <iostream>
#include <armadillo>

/*
Задача: сделать ромбовидное наследование (diamond of death) для классов: А - главный родительский класс,
В, C - потомки А, класс D - наследует B и C так, что поля класса А должны быть в единственном экземпляре.

Класс D предполагается использовать внутри контейнеров std::vector, std::map.

Поля всех классов "ромба" - int, double, arma::mat, какие-либо указатели отсутствуют.

*/
//----------------------------------------------------------------------------------------------------------------------
template<size_t SizeX, size_t SizeY>
class A
{
public:
    A() : IntegerA( 0 ), MatrixA( arma::zeros( SizeX, SizeY ) )
    {
        std::cout << "default constructor A" << std::endl;
    }

    A( const A &other )
    {
        std::cout << "copy constructor A" << std::endl;
        this->IntegerA = other.IntegerA;
        this->MatrixA = other.MatrixA;
    }

    A& operator=( A other ) // Да, именно так, без &: https://stackoverflow.com/questions/3279543/what-is-the-copy-and-swap-idiom
    {
        std::cout << "copy assignment A" << std::endl;        
        swap( *this, other );
        return *this;
    }

    A( A &&other ) noexcept
        : IntegerA( 0 ), MatrixA( arma::zeros( SizeX, SizeY ) )
    {
        std::cout << "move constructor A" << std::endl;
        swap( *this, other );
    }

    A& operator=( A &&other ) noexcept
    {
        std::cout << "move assignment A" << std::endl;
        swap( *this, other );
        return *this;
    }

    ~A() = default;

    friend void swap( A<SizeX, SizeY> &lhs, A<SizeX, SizeY> &rhs ) noexcept
    {
        std::cout << "swap A" << std::endl;

        // Свап полей класса
        std::swap( lhs.IntegerA, rhs.IntegerA );
        std::swap( lhs.MatrixA, rhs.MatrixA );
    }

    // Поля
    int IntegerA;
    arma::mat MatrixA;
};
//----------------------------------------------------------------------------------------------------------------------
template<size_t SizeX, size_t SizeY>
class B : virtual public A<SizeX, SizeY>
{
public:
    using A<SizeX, SizeY>::A;

    B() : A<SizeX, SizeY>(),
        IntegerB( 0 ), MatrixB( arma::zeros( SizeX, SizeY ) )
    {
        std::cout << "default constructor B" << std::endl;
    }

    B( const B &other ) : A<SizeX, SizeY>( other )
    {
        std::cout << "copy constructor B" << std::endl;
        this->IntegerB = other.IntegerB;
        this->MatrixB = other.MatrixB;
    }

    B& operator=( B other ) // Да, именно так, без &
    {
        std::cout << "copy assignment B" << std::endl;        
        swap( *this, other );
        return *this;
    }

    B( B &&other ) : A<SizeX, SizeY>(),
        IntegerB( 0 ), MatrixB( arma::zeros( SizeX, SizeY ) )
    {
        std::cout << "move constructor B" << std::endl;
        swap( *this, other );
    }

    B& operator=( B &&other )
    {
        std::cout << "move assignment B" << std::endl;
        swap( *this, other );
        return *this;
    }

    ~B() = default;

    friend void swap( B<SizeX, SizeY> &lhs, B<SizeX, SizeY> &rhs )
    {
        std::cout << "swap B" << std::endl;
        swap( static_cast<A<SizeX, SizeY>&>( lhs ), static_cast<A<SizeX, SizeY>&>( rhs ) ); // Свап предка 1 порядка

        // Свап полей класса
        std::swap( lhs.IntegerB, rhs.IntegerB );
        std::swap( lhs.MatrixB, rhs.MatrixB );
    }

    // Поля
    int IntegerB;
    arma::mat MatrixB;
};
//----------------------------------------------------------------------------------------------------------------------
template<size_t SizeX, size_t SizeY>
class C : virtual public A<SizeX, SizeY>
{
public:
    using A<SizeX, SizeY>::A;

    C() : A<SizeX, SizeY>(),
        IntegerC( 0 ), MatrixC( arma::zeros( SizeX, SizeY ) )
    {
        std::cout << "default constructor C" << std::endl;
    }

    C( const C &other ) : A<SizeX, SizeY>( other )
    {
        std::cout << "copy constructor C" << std::endl;
        this->IntegerC = other.IntegerC;
        this->MatrixC = other.MatrixC;
    }

    C& operator=( C other ) // Да, именно так, без &
    {
        std::cout << "copy assignment C" << std::endl;        
        swap( *this, other );
        return *this;
    }

    C( C &&other ) noexcept
        : IntegerC( 0 ), MatrixC( arma::zeros( SizeX, SizeY ) )
    {
        std::cout << "move constructor C" << std::endl;
        swap( *this, other );
    }

    C& operator=( C &&other ) noexcept
    {
        std::cout << "move assignment C" << std::endl;
        swap( *this, other );
        return *this;
    }

    ~C() = default;

    friend void swap( C<SizeX, SizeY> &lhs, C<SizeX, SizeY> &rhs ) noexcept
    {
        std::cout << "swap C" << std::endl;
        swap( static_cast< A<SizeX, SizeY> &>( lhs ), static_cast< A<SizeX, SizeY> &>( rhs ) ); // Свап предка 1 порядка

        // Свап полей класса
        std::swap( lhs.IntegerC, rhs.IntegerC );
        std::swap( lhs.MatrixC, rhs.MatrixC );
    }

    // Поля
    int IntegerC;
    arma::mat MatrixC;
};
//----------------------------------------------------------------------------------------------------------------------
template<size_t SizeX, size_t SizeY>
class D : public B<SizeX, SizeY>, public C<SizeX, SizeY>
{
public:
    using B<SizeX, SizeY>::B;
    using C<SizeX, SizeY>::C;

    D() : B<SizeX, SizeY>(), C<SizeX, SizeY>(),
        IntegerD( 0 ), MatrixD( arma::zeros( SizeX, SizeY ) )
    {
        std::cout << "default constructor D" << std::endl;
    }

    D( const D &other ) : B<SizeX, SizeY>( other ), C<SizeX, SizeY>( other ), A<SizeX, SizeY>( other )
    {
        std::cout << "copy constructor D" << std::endl;
        this->IntegerD = other.IntegerD;
        this->MatrixD = other.MatrixD;
    }

    D& operator=( D other ) // Да, именно так, без &
    {
        std::cout << "copy assignment D" << std::endl;        
        swap( *this, other );
        return *this;
    }

    D( D &&other ) noexcept
        : IntegerD( 0 ), MatrixD( arma::zeros( SizeX, SizeY ) )
    {
        std::cout << "move constructor D" << std::endl;
        swap( *this, other );
    }

//    D& operator=( D &&other ) noexcept
//    {
//        std::cout << "move assignment D" << std::endl;
//        swap( *this, other );
//        return *this;
//    }

    ~D() = default;

    friend void swap( D<SizeX, SizeY> &lhs, D<SizeX, SizeY> &rhs ) noexcept
    {
        std::cout << "swap D" << std::endl;
        swap( static_cast< B<SizeX, SizeY> &>( lhs ), static_cast< B<SizeX, SizeY> &>( rhs ) ); // Свап предка 1 порядка
        swap( static_cast< C<SizeX, SizeY> &>( lhs ), static_cast< C<SizeX, SizeY> &>( rhs ) ); // Свап предка 1 порядка
        swap( static_cast< A<SizeX, SizeY> &>( lhs ), static_cast< A<SizeX, SizeY> &>( rhs ) ); // Свап предка 2 порядка

        // Свап полей класса
        std::swap( lhs.IntegerD, rhs.IntegerD );
        std::swap( lhs.MatrixD, rhs.MatrixD );
    }

    // Поля
    int IntegerD;
    arma::mat MatrixD;
};

#endif // CLASSES_H
