# Ranges

## 특/장점

조합성 -> 하스켈 같은 함수형 언어에서 나오는 함수 조합 가능.
Lazy Evaluation 
ㄴ 무한범위의 표현 가능. 필요없는 작업 안해도 됨. 
    ㄴ 어떻게 가능 ? vector의 [] 오퍼레이터를 구현.
    ㄴ 처음에 조합할때는 그냥 클래스 형태의 인스턴스.
    ㄴ 트리거 하는 것은 Range로 나온 객체에 직접 접근하는 것들. ex : algorithm::for_each 같은.

view 클래스의 경우 대부분의 범위가 cout으로 뽑을 수 있음.
코드가 직관적이다.
    ㄴ 파이프라인 때문에 가능
        ㄴ 범위 객체로 casting 이 가능 (User Defined Casting : return-type operator(){} ) 하기 때문에 파이프라인 사용이 가능한거.
            ㄴ 구현하려면 어쩔수 없이 구현체 / 생성 함수식으로 가야하는데
                ㄴ ranges 는 생성함수를 Functor로 구현함.
                    ㄴ Functor 를 사용하냐면 주소값을 인자로 받는 함수는 인라인화 되지 않아서.. 