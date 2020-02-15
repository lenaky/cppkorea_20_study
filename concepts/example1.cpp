#include <algorithm>
#include <list>
#include <vector>
#include <iostream>

template<typename T>
concept bool Integral(){
  return std::is_integral<T>::value;
}

template<typename T>
requires Integral<T>()
T gcd(T a, T b){
  if( b == 0 ){ return a; }
  else{
    return gcd(b, a % b);
  }
}

template<Integral T>
class IntegralClass
{

};

template< typename T>
concept bool Object() {
    return std::integral_constant<bool,
                                       std::is_scalar<T>::value ||
                                       std::is_array<T>::value  ||
                                       std::is_union<T>::value  ||
                                       std::is_class<T>::value>::value;
}

template<Object T>
class MyVector
{

};

int main()
{
    auto val = gcd(20,10);
    std::cout << val << std::endl;

    MyVector<int> v1;
    //MyVector<IntegralClass> v2;

    return 0;
}