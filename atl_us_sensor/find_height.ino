float find_height()
{
  digitalWrite(trigPin1,LOW);  
  delayMicroseconds(2); 
  digitalWrite(trigPin1,HIGH);  
  delayMicroseconds(10); 
  digitalWrite(trigPin1,LOW);   
  temp_height= pulseIn(echoPin1,HIGH);
  temp_height= (temp_height/2)/29.1; 
  return(temp_height);   
}
