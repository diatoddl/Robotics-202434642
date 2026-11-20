# 2026.11.15 실습 — 버튼, 가변저항, PWM, 서보 모터

**202434642 유주원**

## 실습 수행 과정
1. 버튼 상태를 읽어 시리얼 모니터에 출력 (Tinkercad)
2. 버튼으로 LED 켜고 끄기 (Tinkercad)
3. 가변저항 값을 `analogRead`로 읽기 (Tinkercad)
4. 가변저항으로 LED 밝기 조절 (Tinkercad)
5. ESP32로 서보 모터 제어: 0°↔180° 왕복, for문 회전, 가변저항으로 각도 조절

## 적용된 이론 및 기술
- 시리얼 통신: `Serial.begin(115200)`
- `map(value, 0, 1023, 0, 255)` 범위 바꿔서 `analogWrite`로 밝기 제어 (`~` 핀)
- 서보 모터도 매핑을 통해 각도 조절
- 서보 모터: 갈색 GND, 빨강 VCC, 노랑 Signal

## 구현 결과
- 버튼 상태(Pressed / Not Pressed)가 시리얼에 출력되고, 버튼으로 LED가 켜지고 꺼짐.
- 가변저항을 돌리면 값에 따라 LED 밝기가 달라짐.
- 서보가 0°~180°를 왕복하고, 가변저항을 돌리는 대로 각도가 바뀜.

## 제출 파일
- `1_button.txt`, `2_Button-Led.txt`, `3_potentiometer.txt`, `4_Pot-Led.txt` (+ 각 회로 캡처 `.png`)
- `5-1_servo_test.ino`, `5-2_Servo180.c`, `5-3_Servo-Pot.c`
- `1115_수업필기.txt`: 수업 필기

## 실행 방법
- **1–4번**: Tinkercad에서 캡처 화면대로 회로를 구성하고, 코드를 붙여넣은 뒤 Start Simulation을 누름.
- **5번**: Arduino IDE에 ESP32 보드 패키지와 `ESP32Servo` 라이브러리를 설치함. 코드를 붙여넣고 ESP32 보드로 업로드함.

## 필수 의존성
- Tinkercad Circuits (Arduino Uno R3)
- Arduino IDE, `esp32` 보드 패키지, `ESP32Servo` 라이브러리
- 부품: 버튼, 가변저항, LED, 저항, 서보 모터

## 참고 사항

**1_button**
- 버튼에 풀다운 저항을 달지 않으면 값이 HIGH/LOW로 불안정하게 튄다!
- 시리얼 통신은 보통 `Serial.begin(115200)`

**3_potentiometer**
- 가변저항의 가운데 핀은 아날로그 핀(A2), 양 끝은 5V와 GND에 연결한다.
- 아날로그 입력은 `pinMode` 없이 `analogRead`로 바로 읽을 수 있다!

**4_Pot-led**
- PWM은 `~` 표시가 있는 핀(3, 5, 6, 9, 10, 11)에서만 가능
- 입력(0–1023)과 출력(0–255)의 범위가 달라서 매핑해야 한다!!!

**5_servo**
- 서보는 갈색 GND, 빨강 VCC, 노랑 Signal
- ESP32는 ADC가 12bit라서 매핑할 때 0–4095로 써야 한다. (Uno는 0–1023)
- GPIO 34–39는 입력 전용!
