# 테스트 환경
Visual Studio Code + WSL + Clang9

> curl -SL http://releases.llvm.org/9.0.0/clang%2bllvm-9.0.0-x86_64-linux-gnu-ubuntu-18.04.tar.xz | tar -xJC . <br>
mv clang+llvm-9.0.0-x86_64-linux-gnu-ubuntu-18.04 clang_9.0.0<br>
sudo mv clang_9.0.0 /usr/local<br>
export PATH=/usr/local/clang_9.0.0/bin:$PATH<br>
export LD_LIBRARY_PATH=/usr/local/clang_9.0.0/lib:$LD_LIBRARY_PATH<br>

# 왜 모듈을 쓰는가?
* 속도 문제
* encapsulation

# 작성법
* 파일 하나에 넣어도 OK
* 나눠서 만들어도 OK

# 차이점
* 헤더파일 
    * 오너십 존재하지 않는다
* 모듈
    * 오너십 존재 - 어떤걸 보일지 보이지 말지 결정할 수 있음.

Essential Physical Design Rules

No Cyclic Physical Dependencies.
- 순환식으로 물리적 의존이 존재해선 안됨. (A lib -> B lib 참조, B lib -> A lib 참조)
No Long-Distance Friendships.
- 절대 외부에서 접근해선 안됨.

# 이런저런..
core 한 부분이 많이 변경되므로 11버전 이후에 역대급.
모듈은 그중에서 기존 소스에 큰 변화가 오게 될 예정

치환단위 translation unit * 헤더 파일 -> 매 빌드마다 일어남. 겁나 문제임.
언리얼은 빌드할때 2시간 걸린데 ㄷㄷ

소스파일과 헤더파일이 분리될 필요가 없어짐

러스트 -> 메모리 릴리즈에 대한 점이 좀 특이하다. 컴파일 성공시키기가 어렵데. ㅋㅋㅋ 컴파일 속도도 느리다고.. 생산성이 매우 떨어질듯. OOP가 안돼..

3가지 중점. 
import export module

microsoft STL github이 있답니다


컴파일 파일 크기도 꽤 차이가 난다. 
바이너리 크기도 꽤 차이가 난다.

기본적으로 export 하면 global 네임스페이스로 들어가게 되기 때문에.. 다른곳에서 같은 이름을 사용하게 되는 경우에는 ambiguous 가 뜬다.
네임스페이스로 갈러야 하겠지 당연하겠지만서도.
