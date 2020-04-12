int time_slot;
 int i;
void setup()
{
  pinMode(2,OUTPUT); // Signal 1->RED
  pinMode(3,OUTPUT); // Signal 1->YELLOW
  pinMode(4,OUTPUT); // Signal 1->GREEN
  
  pinMode(5,OUTPUT); // Signal 2->RED
  pinMode(6,OUTPUT); // Signal 2->YELLOW
  pinMode(7,OUTPUT); // Signal 2->GREEN
  
  pinMode(8,OUTPUT); // Signal 3->RED
  pinMode(9,OUTPUT); // Signal 3->YELLOW
  pinMode(10,OUTPUT); // Signal 3->GREEN
  
  pinMode(11,OUTPUT); // Signal 4->RED
  pinMode(12,OUTPUT); // Signal 4->YELLOW
  pinMode(13,OUTPUT); // Signal 4->GREEN
 
  Serial.begin(9600);
  Serial.println("Tell the Time Slot :");
}

void loop()
{  for(i=2;i<=13;i++)
  {
    digitalWrite(i,LOW);
  }
  
  if(Serial.available())
  {   time_slot = Serial.read()-48;
        Serial.print("Current Time Slot: " );
        Serial.println(time_slot);
    
       if(time_slot==1)
        { for(i=0;i<3;i++)
        {
        digitalWrite(3,HIGH);digitalWrite(6,HIGH);
        digitalWrite(9,HIGH);digitalWrite(12,HIGH);
        delay(1000);
        digitalWrite(3,LOW);digitalWrite(6,LOW);
        digitalWrite(9,LOW);digitalWrite(12,LOW);
        delay(1000);
        }
        }
       if(time_slot==2 || time_slot==4)
       { for(i=0;i<2;i++)
       {
        digitalWrite(4,HIGH);digitalWrite(5,HIGH);
        digitalWrite(8,HIGH);digitalWrite(11,HIGH);
         digitalWrite(12,LOW);digitalWrite(2,LOW);
          delay(3000);
        digitalWrite(3,HIGH);digitalWrite(4,LOW);
          delay(1000);
        digitalWrite(2,HIGH);digitalWrite(3,LOW);
        digitalWrite(5,LOW);digitalWrite(7,HIGH);
         delay(3000);
        digitalWrite(6,HIGH);digitalWrite(7,LOW); 
         delay(1000);
        digitalWrite(5,HIGH);digitalWrite(6,LOW);
        digitalWrite(8,LOW);digitalWrite(10,HIGH);
         delay(3000);
        digitalWrite(9,HIGH);digitalWrite(10,LOW);
         delay(1000);
        digitalWrite(8,HIGH);digitalWrite(9,LOW);
        digitalWrite(11,LOW);digitalWrite(13,HIGH);
         delay(3000);
        digitalWrite(12,HIGH);digitalWrite(13,LOW);
         delay(1000);
          }
        
       }
      if(time_slot==3)
      {
        for(i=0;i<2;i++)
        { digitalWrite(5,LOW);digitalWrite(11,LOW);
          digitalWrite(3,LOW);digitalWrite(9,LOW);
          digitalWrite(7,HIGH);digitalWrite(13,HIGH);
          digitalWrite(2,HIGH);digitalWrite(8,HIGH);
          delay(3000);
          digitalWrite(7,LOW);digitalWrite(13,LOW);
          digitalWrite(6,HIGH);digitalWrite(12,HIGH);
          delay(1000);
          digitalWrite(6,LOW);digitalWrite(12,LOW);
          digitalWrite(5,HIGH);digitalWrite(11,HIGH);
          digitalWrite(4,HIGH);digitalWrite(10,HIGH);
          digitalWrite(2,LOW);digitalWrite(8,LOW);
          delay(3000);
          digitalWrite(4,LOW);digitalWrite(10,LOW);
          digitalWrite(3,HIGH);digitalWrite(9,HIGH);
          delay(1000);
        }
      }
    /*For a given time slot,the corresponding output will
    be present(time specified),and then wait for next command.
    In case,a command is given before the completion of task in
    current time slot,it will be queued,and will be executed once
    the current task is completed.*/
    
  }
}
/*For eg. if inputs 1,2,3,4 are given one after another,
and time for slots is 3hr,3hr,12hr,6hr respectively.
It will work in sequence and complete its work for 24hr.
    */