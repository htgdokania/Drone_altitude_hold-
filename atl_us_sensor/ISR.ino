//ISR means Interrupt service routine______________________________________________________________________________________
//Here we use software interrupt to read the transmitter channel values

ISR(PCINT0_vect){
//First we take the current count value in micro seconds using the micros() function
  current_count = micros();  
  ///////////////////////////////////////Channel 3
  if(PINB & B00000100 ){                             //pin D10 - B00000100                                         
    if(last_CH3_state == 0){                                             
      last_CH3_state = 1;                                                  
      counter_3 = current_count;                                               
    }
  }
  else if(last_CH3_state == 1){                                             
    last_CH3_state = 0;                                                    
    input_THROTTLE = current_count - counter_3;                            

  }
  ///////////////////////////////////////Channel 5
  if(PINB & B00000010 ){                             //pin D09 - B00000010                                         
    if(last_CH5_state == 0){                                             
      last_CH5_state = 1;                                                  
      counter_5 = current_count;                                               
    }
  }
  else if(last_CH5_state == 1){                                             
    last_CH5_state = 0;                                                    
    input_modeval = current_count - counter_5;                            
  }
}
