//back motor
const int A1A = 5;
const int A1B = 6;

//front motor
const int B1A = 11;
const int B1B = 10;

const int ir1=A0;
const int ir2=A1;

int val1=0;
int val2=0;




void setup() {
  Serial.begin(9600);
  pinMode(B1A,OUTPUT);// define pin as output
  pinMode(B1B,OUTPUT);
  
  pinMode(A1A,OUTPUT);
  pinMode(A1B,OUTPUT);    
  pinMode(ir1,INPUT);
  pinMode(ir2,INPUT);
}

void loop() {

  val1=analogRead(ir1);
  val2=analogRead(ir2);
  Serial.println(val1);
  Serial.println(val2);
  

  if(val1>200 && val2>200){
    //
    motorA('O');
    motorB('R');
    delay(1000);
    motorA('L');
    motorB('O');
    Serial.println("RIGHT");}
  else if(val2<200 && val1<200){
    motorA('O');
    motorB('L');
    delay(1000);
    motorA('L');
    motorB('O');
    
    Serial.println("LEFT");}
  else if(val1>200 && val2<200){
    motorB('O');
    motorA('O');
    Serial.println("STOP");}
  else{ 
    motorB('O');
    motorA('L');
    Serial.println("STRAIGHT");
}

  /*motorA('R');// Turn motor A to RIGHT
  delay(2000);
   motorA('L');// Turn motor A to LEFT
  delay(2000);   
  motorA('O');// Turn motor A OFF
  delay(2000); 
    
  motorB('R');// Turn motor B to RIGHT
  delay(2000);
   motorB('L');// Turn motor B to LEFT
  delay(2000); 
  motorB('O');// Turn motor B OFF
  delay(2000); 
   
  motorA('R');// Turn motor A to RIGHT
  motorB('R'); // Turn motor A to RIGHT 
  delay(2000);
  motorA('L');// Turn motor A to LEFT
  motorB('L');// Turn motor B to LEFT     
  delay(3000);
  motorA('O');// Turn motor A OFF
  motorB('O');// Turn motor B OFF
  delay(5000);
  */
   
}


void motorA(char d)
{
  if(d =='R'){
    digitalWrite(A1A,LOW);
    digitalWrite(A1B,HIGH); 
  }else if (d =='L'){
    digitalWrite(A1A,HIGH);
    digitalWrite(A1B,LOW);    
  }else{
    digitalWrite(A1A,LOW);
    digitalWrite(A1B,LOW);    
  }
}// motorA end

void motorB(char d)
{

    if(d =='R'){
      digitalWrite(B1A,LOW);
      digitalWrite(B1B,HIGH); 
    }else if(d =='L'){
      digitalWrite(B1A,HIGH);
      digitalWrite(B1B,LOW);    
    }else{   
      digitalWrite(B1A,LOW);
      digitalWrite(B1B,LOW);     
    }

}// motorB end 
