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
class A
{
public:
    A() : IntegerA( 0 ), MatrixA( arma::zeros( SizeX, SizeY ) )
    {
        std::cout << "default constructor A" << std::endl;
        MatrixA(0, 0) = 777;
    }

    A( const A &other )
    {
        std::cout << "copy constructor A" << std::endl;
        this->IntegerA = other.IntegerA;
        this->MatrixA = other.MatrixA;
    }

    // см ответ с ответ с https://stackoverflow.com/questions/70247395/ambiguous-overload-for-operator-when-trying-to-invoke-the-move-assignment-ope
    A& operator=( const A &other ) // c &
    {
        std::cout << "copy assignment A" << std::endl;
        A copy( other );
        swap( *this, copy );
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

    virtual ~A()
    {
        std::cout << "destructor A" << std::endl;
    }

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
class B : public A<SizeX, SizeY>
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

    B& operator=( const B &other )
    {
        std::cout << "copy assignment B" << std::endl;
        B copy( other );
        swap( *this, copy );
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

    virtual ~B()
    {
        std::cout << "destructor B" << std::endl;
    }

    friend void swap( B<SizeX, SizeY> &lhs, B<SizeX, SizeY> &rhs )
    {
        std::cout << "swap B" << std::endl;
        swap( dynamic_cast<A<SizeX, SizeY>&>( lhs ), dynamic_cast<A<SizeX, SizeY>&>( rhs ) ); // Свап предка 1 порядка

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
class C : virtual public B<SizeX, SizeY>
{
public:
    using B<SizeX, SizeY>::B;

    C() : B<SizeX, SizeY>(),
        IntegerC( 0 ), MatrixC( arma::zeros( SizeX, SizeY ) )
    {
        std::cout << "default constructor C" << std::endl;
    }

    C( const C &other ) : B<SizeX, SizeY>( other )
    {
        std::cout << "copy constructor C" << std::endl;
        this->IntegerC = other.IntegerC;
        this->MatrixC = other.MatrixC;
    }

    C& operator=( const C &other )
    {
        std::cout << "copy assignment C" << std::endl;
        C copy( other );
        swap( *this, copy );
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

    virtual ~C()
    {
        std::cout << "destructor C" << std::endl;
    }

    friend void swap( C<SizeX, SizeY> &lhs, C<SizeX, SizeY> &rhs ) noexcept
    {
        std::cout << "swap C" << std::endl;
        swap( dynamic_cast< B<SizeX, SizeY> &>( lhs ), dynamic_cast< B<SizeX, SizeY> &>( rhs ) ); // Свап предка 1 порядка

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
class D : virtual public B<SizeX, SizeY>
{
public:
    using B<SizeX, SizeY>::B;

    D() : B<SizeX, SizeY>(),
        IntegerD( 0 ), MatrixD( arma::zeros( SizeX, SizeY ) )
    {
        std::cout << "default constructor D" << std::endl;
    }

    D( const D &other ) : B<SizeX, SizeY>( other )
    {
        std::cout << "copy constructor D" << std::endl;
        this->IntegerD = other.IntegerD;
        this->MatrixD = other.MatrixD;
    }

    D& operator=( const D &other )
    {
        std::cout << "copy assignment D" << std::endl;
        D copy( other );
        swap( *this, copy );
        return *this;
    }

    D( D &&other ) noexcept
        : IntegerD( 0 ), MatrixD( arma::zeros( SizeX, SizeY ) )
    {
        std::cout << "move constructor D" << std::endl;
        swap( *this, other );
    }

    D& operator=( D &&other ) noexcept
    {
        std::cout << "move assignment D" << std::endl;
        swap( *this, other );
        return *this;
    }

    virtual ~D()
    {
        std::cout << "destructor D" << std::endl;
    }

    friend void swap( D<SizeX, SizeY> &lhs, D<SizeX, SizeY> &rhs ) noexcept
    {
        std::cout << "swap D" << std::endl;
        swap( dynamic_cast< B<SizeX, SizeY> &>( lhs ), dynamic_cast< B<SizeX, SizeY> &>( rhs ) ); // Свап предка 1 порядка

        // Свап полей класса
        std::swap( lhs.IntegerD, rhs.IntegerD );
        std::swap( lhs.MatrixD, rhs.MatrixD );
    }

    // Поля
    int IntegerD;
    arma::mat MatrixD;
};
//----------------------------------------------------------------------------------------------------------------------
template<size_t SizeX, size_t SizeY>
class E : public D<SizeX, SizeY>
{
public:
    using D<SizeX, SizeY>::D;

    E() : D<SizeX, SizeY>(),
        IntegerE( 0 ), MatrixE( arma::zeros( SizeX, SizeY ) )
    {
        std::cout << "default constructor E" << std::endl;
    }

    E( const E &other ) : B<SizeX, SizeY>( other ), D<SizeX, SizeY>( other )
    {
        std::cout << "copy constructor E" << std::endl;
        this->IntegerE = other.IntegerE;
        this->MatrixE = other.MatrixE;
    }

    E& operator=( const E &other )
    {
        std::cout << "copy assignment E" << std::endl;
        E copy( other );
        swap( *this, copy );
        return *this;
    }

    E( E &&other ) noexcept
        : IntegerE( 0 ), MatrixE( arma::zeros( SizeX, SizeY ) )
    {
        std::cout << "move constructor E" << std::endl;
        swap( *this, other );
    }

    E& operator=( E &&other ) noexcept
    {
        std::cout << "move assignment E" << std::endl;
        swap( *this, other );
        return *this;
    }

    virtual ~E()
    {
        std::cout << "destructor E" << std::endl;
    }

    friend void swap( E<SizeX, SizeY> &lhs, E<SizeX, SizeY> &rhs ) noexcept
    {
        std::cout << "swap E" << std::endl;
        swap( dynamic_cast< D<SizeX, SizeY> &>( lhs ), dynamic_cast< D<SizeX, SizeY> &>( rhs ) ); // Свап предка 1 порядка

        // Свап полей класса
        std::swap( lhs.IntegerE, rhs.IntegerE );
        std::swap( lhs.MatrixE, rhs.MatrixE );
    }

    // Поля
    int IntegerE;
    arma::mat MatrixE;
};
//----------------------------------------------------------------------------------------------------------------------
template<size_t SizeX, size_t SizeY>
class F : public C<SizeX, SizeY>, public E<SizeX, SizeY>
{
public:
    using C<SizeX, SizeY>::C;
    using E<SizeX, SizeY>::E;

    F() : C<SizeX, SizeY>(), E<SizeX, SizeY>(),
        IntegerF( 0 ), MatrixF( arma::zeros( SizeX, SizeY ) )
    {
        std::cout << "default constructor F" << std::endl;
    }

    F( const F &other ) : B<SizeX, SizeY>( other ), C<SizeX, SizeY>( other ), E<SizeX, SizeY>( other )
    {
        std::cout << "copy constructor F" << std::endl;
        this->IntegerF = other.IntegerF;
        this->MatrixF = other.MatrixF;
    }

    F& operator=( const F &other )
    {
        std::cout << "copy assignment F" << std::endl;
        F copy( other );
        swap( *this, copy );
        return *this;
    }

    F( F &&other ) noexcept
        : IntegerF( 0 ), MatrixF( arma::zeros( SizeX, SizeY ) )
    {
        std::cout << "move constructor F" << std::endl;
        swap( *this, other );
    }

    F& operator=( F &&other ) noexcept
    {
        std::cout << "move assignment F" << std::endl;
        swap( *this, other );
        return *this;
    }

    virtual ~F()
    {
        std::cout << "destructor F" << std::endl;
    }

    friend void swap( F<SizeX, SizeY> &lhs, F<SizeX, SizeY> &rhs ) noexcept
    {
        std::cout << "swap F" << std::endl;
        swap( dynamic_cast< B<SizeX, SizeY> &>( lhs ), dynamic_cast< B<SizeX, SizeY> &>( rhs ) ); // Свап предка 3 порядка
//        swap( dynamic_cast< C<SizeX, SizeY> &>( lhs ), dynamic_cast< C<SizeX, SizeY> &>( rhs ) ); // Свап предка 1 порядка
        swap( dynamic_cast< E<SizeX, SizeY> &>( lhs ), dynamic_cast< E<SizeX, SizeY> &>( rhs ) ); // Свап предка 1 порядка

        // Свап полей класса
        std::swap( lhs.IntegerF, rhs.IntegerF );
        std::swap( lhs.MatrixF, rhs.MatrixF );
    }

    // Поля
    int IntegerF;
    arma::mat MatrixF;
};
//----------------------------------------------------------------------------------------------------------------------
template<size_t SizeX, size_t SizeY>
class G : public F<SizeX, SizeY>
{
public:
    using F<SizeX, SizeY>::F;

    G() : F<SizeX, SizeY>(),
        IntegerG( 0 ), MatrixG( arma::zeros( SizeX, SizeY ) )
    {
        std::cout << "default constructor G" << std::endl;
    }

    G( const G &other ) : F<SizeX, SizeY>( other )
    {
        std::cout << "copy constructor G" << std::endl;
        this->IntegerG = other.IntegerG;
        this->MatrixG = other.MatrixG;
    }

    G& operator=( const G &other )
    {
        std::cout << "copy assignment G" << std::endl;
        G copy( other );
        swap( *this, copy );
        return *this;
    }

    G( G &&other ) : F<SizeX, SizeY>(),
        IntegerG( 0 ), MatrixG( arma::zeros( SizeX, SizeY ) )
    {
        std::cout << "move constructor G" << std::endl;
        swap( *this, other );
    }

    G& operator=( G &&other )
    {
        std::cout << "move assignment G" << std::endl;
        swap( *this, other );
        return *this;
    }

    virtual ~G()
    {
        std::cout << "destructor G" << std::endl;
    }

    friend void swap( G<SizeX, SizeY> &lhs, G<SizeX, SizeY> &rhs )
    {
        std::cout << "swap G" << std::endl;
        swap( dynamic_cast<F<SizeX, SizeY>&>( lhs ), dynamic_cast<F<SizeX, SizeY>&>( rhs ) ); // Свап предка 1 порядка

        // Свап полей класса
        std::swap( lhs.IntegerG, rhs.IntegerG );
        std::swap( lhs.MatrixG, rhs.MatrixG );
    }

    // Поля
    int IntegerG;
    arma::mat MatrixG;
};

#endif // CLASSES_H
