#include <compare>
#include <iostream>

#define USE_STRONG_ORDERING

class SmallRect
{
public:
    SmallRect(int w, int h) : _w( w ), _h( h ) {}

    int GetArea() const { return _w * _h; }

#ifdef USE_STRONG_ORDERING
    std::strong_ordering operator<=>(const SmallRect& rhs) const 
    {
        // 전체 면적과 w, h의 값이 모두 같다면 "동일"
        if (GetArea() == rhs.GetArea() && _w <=> rhs._w  == 0 && _h && _h <=> rhs._h == 0)
        {
            return std::strong_ordering::equal;
        }

        // 좌변과 우변의 w,h가 동일하다면
        if (_w <=> rhs._w == 0)
        {
            // 좌변과 우변의 h로 동일한지 비교
            return _h <=> rhs._h;
        }

        // 좌변과 우변의 <=>을 반환
        return _w <=> rhs._w;
    }
#else
    std::weak_ordering operator<=>(const SmallRect& rhs) const
    {
        if (GetArea() == rhs.GetArea())
        {
            return std::weak_ordering::equivalent;
        }

        if (_w <=> rhs._w == 0)
        {
            return _h <=> rhs._h;
        }

        return _w <=> rhs._w;
    }
#endif

private:
    int _w = 0;
    int _h = 0;
};

class BigRect
{
 public:
    BigRect(SmallRect s, int value) : _s( s ), _value( value ) {}

    int GetArea() const
    {
        return _s.GetArea();
    }

#ifdef USE_STRONG_ORDERING
    std::strong_ordering operator<=>(const BigRect& r) const
    {
        if (_s <=> r._s == 0 && _value <=> r._value == 0)
        {
            return std::strong_ordering::equal;
        }
        
        if (_s <=> r._s == 0)
        {
            return _value <=> r._value;
        }
        
        return _s <=> r._s;
    }    
#else
    std::weak_ordering operator<=>(const BigRect& r) const
    {
        if (_s <=> r._s == 0 && _value <=> r._value == 0)
        {
            return std::weak_ordering::equivalent;
        }
        
        if (_s <=> r._s == 0)
        {
            return _value <=> r._value;
        }
        
        return _s <=> r._s;
    }
#endif
 private:
    SmallRect _s;
    int _value;
};

int main()
{
    SmallRect s1(2,4);
    SmallRect s2(4,2);
    SmallRect s3(10,20);
    SmallRect s4(10,20);

    BigRect b1(s1, 10);
    BigRect b2(s2, 10);
    BigRect b3(s3, 10);
    BigRect b4(s4, 10);

    std::cout << std::boolalpha << (b1<=>b2 == 0) << '\n';
    std::cout << std::boolalpha << (b1<=>b3 > 0) << '\n';
    std::cout << std::boolalpha << (b1<=>b4 < 0) << '\n';

    return 0;
}