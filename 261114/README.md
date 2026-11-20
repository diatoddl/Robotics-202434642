# 2026.11.14 실습 — Tinkercad LED

**202434642 유주원**

## 실습 수행 과정
수업에서 로봇의 고수준/저수준 제어 구조, Linux 기본 명령어, 임베디드 기초 전기를 배움. 이후 Tinkercad에서 Arduino Uno의 7번 핀에 저항과 LED를 연결하고, LED를 1초 간격으로 깜빡이게 만드는 실습을 수행함. (자세한 필기 내용은 **1114_수업필기.txt** 파일 참조)

## 적용된 이론 및 기술
- 고수준(SBC, 판단·계획)과 저수준(MCU, 실시간 제어)의 역할 분리
- GPIO 디지털 출력 (pinMode, digitalWrite)
- 옴의 법칙(V=IR): LED 보호용 직렬 저항

## 구현 결과
LED 1초 켜짐 -> 1초 꺼짐 반복을 시뮬레이션으로 확인함. (tinkercadLedTest.png)

## 제출 파일
- `tinkercadLedTest.txt`: LED 깜빡 코드
- `tinkercadLedTest.png`: 회로 캡처
- `1114_수업필기.txt`: 수업 필기

## 실행 방법
Tinkercad Circuits에서 캡처 화면대로 회로를 구성함. Code를 Text 모드로 바꾸고 `tinkercadLedTest.txt`를 붙여넣은 뒤 Start Simulation을 누름.

## 필수 의존성
- Tinkercad Circuits (Arduino Uno R3, LED, 저항)
- 외부 라이브러리 없음

## 참고 사항
- LED는 긴 다리(+)를 출력 핀 쪽에 연결해야 한다!
- LED에는 반드시 저항을 직렬로 달아야 한다. 없으면 과전류가 난다!
- 출력으로 쓸 핀은 setup에서 pinMode(pin, OUTPUT)으로 설정해야 한다!
 
