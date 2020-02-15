# Concepts

## What is Concepts?

컴파일 타임 술어.

문법은 아래와 같음.
```c++
template<typename T>
concept bool Integral() {
    ...
}
```
Predicate 가 어떻게 타입이 되지?

## 이점
requirements 를 인터페이스의 일부로 직접적인 표현이 가능.
템플릿 파라미터들의 requirements 에 근간하여 함수 오버로딩과 클래스 템플릿의 특수화를 지원한다.
좀 더 나은 에러 메세지를 얻을 수 있다. (requirement나 템플릿 arguments 들을 비교하여..)
predefined 컨셉들을 사용하거나 직접 만들어 사용도 가능
auto를 쓰는 대신 concepts를 그냥 사용하면 된다. auto와 concepts의 사용법이 합쳐진다. 
함수 선언이 concepts을 사용한다면, 자동으로 함수 템플릿이 된다. 함수 템플릿을 사용하는것이 그냥 함수 작성하는 것 만큼이나 쉬워진다.
제너릭 프로그램에서 플레이스홀더로 사용이 될 수 있다.

## Example

Sortable Concept를 사용하는 3가지 방법.

* Requires 절을 사용
template<typename Cont> require Sortable<Cont>
void sort(Cont& container);

* 후행 Requires 절을 사용
template<typename Cont> void sort(Cont& container)
require Sortable<Cont>;

* Contrained Template Parameters
template<Sortable Cont>
void sort(Cont& container)



# References

https://www.modernescpp.com/index.php/c-20-concepts-the-details