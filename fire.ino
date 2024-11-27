int sensor = 4;
int fire;
int smoke = A0;
int data = 0;
int led =13;
const int buzzerPin = 7;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(buzzerPin, OUTPUT);
  pinMode(sensor, INPUT);
  pinMode(smoke,INPUT);
  pinMode(led,OUTPUT);
  digitalWrite(led,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  data = analogRead(smoke);
  Serial.print("smoke : ");
  Serial.println(data);
  fire = digitalRead(sensor);
  if (fire == 1)
  {
    Serial.println("fIRE EM");
  }
  else {
    Serial.println("no fire");
  }
  if ((data <230 ) &&  (fire==0))
  {
    digitalWrite(led,LOW);
  }
  else if ((data <230 ) &&  (fire==1))
  {
    digitalWrite(led,HIGH);
    digitalWrite(buzzerPin, HIGH);
    delay(1000); // delay 1 giây
  }
  else if ((data >=230 ) &&  (fire==0))
  {
    digitalWrite(led,HIGH);
    digitalWrite(buzzerPin, HIGH);
    delay(1000); // delay 1 giây
  }
  else if((data > 230 ) &&  (fire==1))
  {
    digitalWrite(led,HIGH);
    digitalWrite(buzzerPin, HIGH);
    delay(1000); // delay 1 giây
  }
  delay (1000);
}
