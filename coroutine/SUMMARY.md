# Coroutine

Function vs Routine

명령의 집합 = Routine

## 코루틴의 4단계
호출 /  활성화 / 중단 / 종결

호출 -> 시작점
활성화 -> 루틴 안으로 점프
중단 -> 루틴의 끝이 도달하지 않은 상태
종결 -> 루틴이 끝남 -> 함수 종료랑 같음


일반적으로 서브루틴은 함수프레임을 이용해서 관리.
시작/종료에는 편한데 중단/재개를 하려면 함수프레임 관리가 까다로워진다. (사라지면 안되므로)

일반적으로 똑같은 -> 호출
co_return -> 종결
co_await, co_yield -> 중단
coro.resume() -> 재개


함수 안에 코루틴 관련된 함수가 하나라도 있으면 코루틴으로 판단한다 -> 컴파일러가.
메인함수는 코루틴이 될 수가 없어.. 

코루틴을 쓸려면 특별타입 (Promise Type)을 구현해줘야 한다.

P{}
p.get_return_object()
return_value
initial_suspend
final_suspend
return_void
unhandled_exception

return_ignore(const promise_type*) noexcept