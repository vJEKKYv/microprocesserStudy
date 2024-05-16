# 마이크로프로세서응용 과제
## 1장 연습문제 1번~5번 풀이
### 2019152014 김제원
 
1. Mbed에서 지원하는 시간지연 함수 3가지를 이용하여 0.0039 초를 지연시키기 위한 3가
지의 코드를 모두 적어라. <br>
 wait(0.0039) // wait() 함수는 이제 쓰지 않기에 형식만 작성. <br>
 wait_us(3900) <br>
 wait_ns(3900000); <br>
 /* <br>
 wait_ms는 int형의 parameter를 가지기 때문에 3.9ms를 표현할 수 없다. <br>
 ThisThread::sleep_for() 함수도 ms의 소수점을 인식하지 못하기에 할 수 없다. <br>
 */ <br>
 
2. float 자료형 변수 v에 -100과 100 사이의 난수를 대입하는 한 줄을 완성하라. <br>
Rand() % n 을 하면 0~(n-1) 범위의 랜덤 변수를 얻을 수 있다. 이를 이용해 0~200 사이
의 랜덤 변수를 구하고 그것에서 -100을 해서 해당 범위의 변수를 구할 수 있다. <br>
 ➔ float v= (float)rand() % (float)201 – (float)100;
 
3. D10, D12핀을 각각 할당하여 DigitalOut 객체 pump와 valve를 생성하는 코드를 작성하라. <br>
DigitalOut의 클래스를 이용해 pump와 valve라는 이름으로 객체를 생성한다. <br>
 ➔ DigitalOut pump(D10), valve(D12);
 
4. 3번 문제에서 pump의 출력값을 읽어와 value의 출력값을 정하는 코드를 작성하라. <br>
value의 출력값에 특정 값을 대입하려면 writ() 함수를 사용한다. <br>
pump의 출력값을 받아오기 위해서는 read() 함수를 사용한다. <br>
 ➔ value.write(pump.read());

5. v 값이 30보다 작으면 DigitalOut 객체 pump를 켜고 크면 pump를 끄는 코드를 조건연
산자를 이용하여 작성하라. <br>
v가 30보다 작을 때 pump를 킨다면 pump에 1을 대입해야 하고, 아닐때 pump를 끈다면 v<30? 이라는 문구로 크거나 작을때의 값을 true false로 반환하고 이를 대입하기 위
해 뒤에 1:0으로 true일 때 앞의 값인 1, false일 때 뒤의 값인 0을 대입할 수 있게 한다. <br>
 ➔ pump = v < 30? 1:0;
