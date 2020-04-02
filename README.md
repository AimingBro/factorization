# 심심풀이소인수분해 프로그램 대회

### 문제: 소인수 분해하기

어떤 숫자 하나를 명령어 라인 인자로 입력하면 해당 숫자를 소인수 분해해서, 결과적으로 나오는 소수들을 작은 수에서 큰 수의 순서대로 딱 한번씩만 차례로 출력하는 프로그램 짜기입니다. 입력으로 들어가는 수는 1보다 큰 32bit unsigned integer (즉 2 부터 2^32 -1 까지)만 허용, 그 밖의 입력에 대해서는 에러메시지 출력. 참 쉽죠?
(그것까지 알려주마 : [위키백과 : 소인수분해](https://ko.wikipedia.org/wiki/소인수분해))

- #### 출력 

  예 1:

  ```shell
  $ factorization 18
  2 3
  $
  ```

  예 2:

  ```shell
  $ factorization 7
  7
  $
  ```

  그리고 기타 가능한 (딱 지정된 범위의 숫자 하나만 인자로 받아야 하는데 아닌) 모든 경우의 에러에 대해서는 **합당한** 에러 메시지 출력.

- #### 결과물 제출 방법

  - **이 이벤트는** **개인 제출** **이벤트 입니다. (팀으로 해도 한 사람이 대표 제출)**
  - 제출 마감: **2020년 4월 3일 오전 0시 42분 까지**
  - 제출방법 : 해당 코드가 들어있는 github repository link를 이래 form에 등록 제출 (제출 시점에 찍힌 time stamp가 위 마감시간 안 쪽에 있어야 하며, 마감 시간이후 repo에 commit한 기록이 있어도 자동 탈락) 
  - 제출한 github repo에는 반드시 다음 세 파일이 있어야 함 (어느 하나라도 없거나 public access가 안되면 제출 명단에서 제외) 
    - [Makefile](.Makefile) : factorization.c 소스를 실행파일 factorization으로 바꾸는 makefile
    - [factorization.c](./factorization.c) : 위 문제를 해결한 소스 **(C 프로그램 only)**
    - [test.md](./test.md) : 나만의 테스트 과정과 예외처리 결과를 담은 markdown 문서