
int led = 13;
String data;
char letter;

void setup() {
  // put your setup code here, to run once:

  pinMode(led,OUTPUT);
  digitalWrite(led,LOW);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  if(Serial.available())
  {
    data = Serial.readString();
    letter = data.charAt(0);
    if(letter =='A')
    {
      digitalWrite(led,HIGH);

    }

  }

}
