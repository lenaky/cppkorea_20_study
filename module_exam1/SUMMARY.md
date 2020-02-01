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