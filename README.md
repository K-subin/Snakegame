# Snakegame

"C++ 프로그래밍 언어로 NCURSES 라이브러리를 사용하여 Snake Game을 구현"

여기서 Snake Game 이란 화면에 보이는 Snake를 플레이어가 직접 방향키를 통해 움직여 아이템들을 얻고 주어진 조건들을 모두 달성하는 게임이다.

## 시현 영상 (2배속)
![snake시현영상](https://user-images.githubusercontent.com/68969252/102793926-ef896080-43ed-11eb-9f1b-a7aed0a895ba.gif)

## 컴파일/실행방법
#### 컴파일
Makefile에 snakegame 컴파일을 수행하는 스크립드가 들어가 있다.

따라서 아래처럼 실행하면 알아서 결과물을 만들어낸다.

$ make

#### 실행방법
$ ./snakegame

## 목표
### [1단계] - MAP

#### 목표 1 : 스테이지마다 한 개의 MAP 구현하기

(1) MAP 크기는 30x30으로 한다.

(2) MAP에 등장하는 요소들을 정의한다.

<img src="https://user-images.githubusercontent.com/68969252/88854891-fd66fb00-d22c-11ea-82fd-f50360b0dbdd.PNG" width="300">

- Wall : Gate로 바뀔 수 있는 벽, 부딪히면 게임 오버
- Immune Wall : Gate로 바뀔 수 없는 벽
- Snake Head : 스네이크의 머리 부분, 방향에 따라 움직인다.
- Snake Body : 스네이크의 몸 부분, 길이가 늘어나기도 하고 줄어들기도 한다.
- Growth Item : 스네이크의 몸 길이를 1 늘려주는 아이템
- Poison Item : 스네이크의 몸 길이를 1 줄여주는 아이템
- Gate : 입구와 출구 2개가 있고, 한 쪽으로 들어가면 다른 쪽으로 나온다.
- Blank : 아이템들이 나올 수 있고 스네이크가 움직일 수 있는 공간

(3) Stage 개수 : 4개 > 1 Stage마다 1개의 MAP

<img src="https://user-images.githubusercontent.com/68969252/88857011-774cb380-d230-11ea-8e3a-3d65c5fcfa4f.PNG" width="650">

#### 목표 2 : 화면 구성하기

예시)

<img src="https://user-images.githubusercontent.com/68969252/88855796-584d2200-d22e-11ea-9b2a-3a7118255438.PNG" width="650">

(1) 게임 설명 화면 출력하기

(2) MAP 화면 출력하기

(3) 점수 화면 출력하기


### [2단계] - Snake
#### 목표 1 : 스네이크 생성하기

(1) 스네이크 위치 설정

(2) 다음 스네이크로 넘어갈 때 스네이크를 초기화

(3) 스네이크 출현
- 스네이크 머리를 기준으로 오른쪽으로 3칸을 스네이크 꼬리로 설정

#### 목표 2 : 사용자의 키보드 입력에 따라 이동방향 설정하기
(1) 키보드 입력에 따라 이동방향 설정

<img src="https://user-images.githubusercontent.com/68969252/88857832-ed9de580-d231-11ea-8fed-957780245f1b.PNG" width="270">

(2) 사용자가 스네이크 진행 방향의 반대방향으로 키보드 입력을 할 경우 게임 오버

(3) 스네이크는 0.5초마다 이동

#### 목표 3 : 이동방향에 따라 스네이크 움직이기
(1) 스네이크 머리의 다음 이동 위치 설정하기

(2) Growth Item 또는 Poison Item을 획득할 경우 스네이크 움직이기

<img src="https://user-images.githubusercontent.com/68969252/88858341-d0b5e200-d232-11ea-8534-b217fa0cb928.PNG" width="500">

- 스네이크 몸 길이가 2 이하가 되는 경우 게임오버

(4) Gate를 만날 경우 스네이크 움직이기

<img src="https://user-images.githubusercontent.com/68969252/88858803-88e38a80-d233-11ea-9278-fe6e11a89829.PNG" width="400">

(5) 벽을 만나는 경우 게임오버


### [3단계] - Item
#### 목표 1 : Item 생성하기
(1) Growth Item과 Poison Item 개수 설정

(2) Growth Item 개수만큼 MAP의 빈 공간인 랜덤한 위치에 Growth Item 생성

(3) Poison Item 개수만큼 MAP의 빈 공간인 랜덤한 위치에 Poison Item 생성


### [4단계] - Gate
#### 목표 1 : MAP의 벽의 랜덤한 위치에 겹치지 않도록 두 개의 Gate 한 쌍을 생성
#### 목표 2 : Gate와 Item을 생성하고 10초가 지나면 다시 새로운 위치에 생성
#### 목표 3 : 스네이크가 진입하는 Gate와 진출하는 Gate 구분하기
#### 목표 4 : Gate 위치와 스네이크가 Gate로 들어가는 진입방향에 따라 Gate에서 나오는 진출방향을 설정
(1) 진출하는 Gate의 위치가 MAP의 가장자리에 있을 경우
- 항상 MAP의 안쪽 방향으로 진출

(2) 진출하는 Gate의 위치가 MAP의 가운데에 있을 경우

(2-1) 진출방향이 위쪽 또는 아래쪽일 경우
- 진입이 좌, 위 -> 위로 진출
- 진입이 우, 하 -> 아래로 진출

(2-2) 진출방향이 왼쪽 또는 오른쪽일 경우
- 진입이 좌, 위 -> 좌로 진출
- 진입이 우, 하 -> 우로 진출


### [5단계] - Score
#### 목표 1 : 점수 출력하기
(1) 점수는 현재 길이와 최대 길이, 획득한 Growth Item, 획득한 Poison Item, Gate 사용 횟수를 나타낸다.
- 최대 길이란, 한 스테이지 내에서 스네이크의 전체 길이가 가장 길었을 때를 말한다.

#### 목표 2 : 목표 달성하기
(1) 스테이지마다 달성해야 하는 목표가 존재한다.
- 1스테이지 : 5, 2, 1, 1
- 2스테이지 : 10, 4, 2, 2
- 3스테이지 : 15, 6, 4, 3
- 4스테이지 : 15, 6, 5, 4

(2) 목표를 달성했을 때 V로 표시한다. 
