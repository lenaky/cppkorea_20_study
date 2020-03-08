# Spaceship operator

같다(equal) / 동등하다(equivalent)

같다의 의미는 strong_ordering 이냐 weak_ordering 이냐에 따라 달라질 수 있음.

여러가지 비교 상태 (==, !=, <, >, <=, >= 등등)를 표현할 수 있다.

# Span

함수의 인자로 배열을 넘길때 포인터와 길이를 넘겨줬어야 했음.
c++11에서는 std::array 라는 것이 생기고 템플릿 파라미터로 타입과 array 길이를 넣어서 생성할 수 있음.
array 의 문제는 템플릿 인자로 길이를 넣어줘야하기 때문에 길이가 다른것을 쓸 때마다 매번 새로운것을 선언해야함.
span이 이것을 모두 해결해줌.
사용할 수 있는 자료형이 정해져있다. map, array 등이 됨. operator[]가 있어야 할 듯 함.

# endian

기존에 코드 짤 때 현재 머신의 endian에 따라 전처리를 두는식으로 구현..
endian::native 라는 것을 사용해서 

# consteval

무조건 컴파일 타임때만 사용할 수 있는 것.

# bit_cast

어떤 값이라도 비트로 캐스팅해줌.

# jthread

스스로 종료할때 조인을 걸고 나옴.
stop_token 이란 것을 넣어서 중간에 인터럽트를 걸 수 있다.

# calendar / timezone

연월일 표현이 쉬워짐.

https://github.com/HowardHinnant/date 에서 사용중

