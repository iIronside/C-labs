#include <iostream>
#include <string>
#include <typeinfo>
#include <vector>
#include <algorithm>


// ======================== пример шаблонной функции
template <typename T>
bool startsWith(T* arr, T elem)
{
    return arr[0] == elem;
}

// ===================== явная специализация для символов
// ===================== (добавлен функционал регистронезависимости)
template <>
bool startsWith(char* arr, char elem)
{
    return ::toupper(arr[0]) == ::toupper(elem);
}


// ============================ пример шаблонного класса
template <class T, int N>
class Container
{
public:
    void print()
    {
        std::cout << N << " " << typeid(T).name() << std::endl;
    }

protected:
    T a[N];
};

// ======================== пример №1 частичной специализации
template <int N>
class Container<int, N>
{
public:
    void print()
    {
        std::cout << N << " integers!" << std::endl;
    }

protected:
    int a[N];
};


//
// Generic programming
// SFINAE       Substitution
//              Failure
//              Is
//              Not
//              An
//              Error
//


// ======================= еще пример частичной специализации
template <typename T>
struct Get
{
    const static int Size = sizeof(T);
};

// для всех указателей компилятор будет подставлять именно эту версию функции
template <typename T>
struct Get<T*>
{
    const static int Size = 0;

    void foo()
    {
        T prop;

        // и только уже дойдя до этого места, компилятор
        // выдаст ошибку, если у типа T нет age
        prop.age = 19;
        std::cout << "Age: " << prop.age << std::endl;
    }
};


// Своя версия трейтов

template <class T>
struct type_trait
{
    const static bool isIntegral = false;
};

template <>
struct type_trait<int>
{
    // typedef нужен для SFINAE (вводится только в int-овой и short-овой специализациях)
    typedef int integral_type;
    // эту константу также можно использовать в каких-либо целях
    const static bool isIntegral = true;
};

template <>
struct type_trait<short>
{
    typedef short integral_type;
    const static int isIntegral = true;
};

// данная функция будет считаться компилятором подходящей только для тех типов,
// в которых объявлен тип integral_type
template <typename T>
void printNumber(T elem, typename type_trait<T>::integral_type flag = 0)
{
    std::cout << elem << std::endl;
}

// Начиная с C++11 доступно также следующее:  1) static_assert,  2) enable_if

// 1)
//template <typename T>
//void bar(T elem))
//{
//    static_assert(type_trait<T>::isIntegral, "Bar() parameter should be integral!");
//    std::cout << elem << std::endl;
//}

// 2)
//template <typename T>
//void bar(T elem, typename std::enable_if<type_trait<T>::isIntegral, bool>::type t = false)
//{
//    std::cout << elem << std::endl;
//}



// ====================== Еще примеры шаблонов и метапрограммирования

// =========================================== Ex.1 (classic example)

/* this is taken when I is even */
template<int I>
void center(char(*)[I % 2 == 0] = 0)
{
    std::cout << "EVEN!" << std::endl;
}

/* this is taken when I is odd */
template<int I>
void center(char(*)[I % 2 == 1] = 0)
{
    std::cout << "ODD!" << std::endl;
}


// ================================== Ex.2 (even more classic example)
template <int N>
struct Factorial
{
    enum { value = N * Factorial<N - 1>::value };
};

template <>
struct Factorial<0>
{
    enum { value = 1 };
};


struct Person
{
    std::string name;
    int age;
};


int main()
{
    // примеры вызовов шаблонной функции
    int a[] = {1, 2, 3, 4, 5};
    if (startsWith(a, 1))
        std::cout << "Array a starts with 1" << std::endl;

    double b[] = {1.0, 2.0, 3.0, 4., 5.};
    if (startsWith<double>(b, 1.0))
        std::cout << "Array b starts with 1.0" << std::endl;

    char s[] = "OK";
    if (startsWith(s, 'o'))
        std::cout << "Array s starts with 'o'" << std::endl;


    // примеры инстанцирования шаблонных классов
    Container<Person, 20> personlist;
    personlist.print();

    Container<double, 100> dlist;
    dlist.print();

    Container<int, 10> ilist;
    ilist.print();


    // пример с частичной специализацией для указателей (тип Т*) и SFINAE
    std::cout << "Size of short: " << Get<short>::Size << std::endl;
    std::cout << "Size of a pointer (should be zero): " << Get<int*>::Size << std::endl;

    Get<Person*> personHelper;
    personHelper.foo();


    // еще демо SFINAE:

    printNumber(23);
    //printNumber(23.56);       // здесь компилятор выдаст ошибку

    std::cout << "center<12>(): ";
    center<12>();
    std::cout << "center<15>(): ";
    center<15>();

    // metaprogramming: factorial demo
    std::cout << "6! = " << Factorial<6>::value << std::endl; // = 720
    std::cout << "0! = " << Factorial<0>::value << std::endl; // = 1

    return 0;
}
