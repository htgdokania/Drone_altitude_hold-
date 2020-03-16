void loop() { 
  input_THROTTLE1=map(input_THROTTLE,1100,1800,1000,2000);//map the throttle value as per requirement
  switch ((input_modeval>1500))//output of the channel 5
    {
      case 0: //normal mode
              //reset the error values
              error=0; pre_error=0; derror=0;ierror=0;
              temp1_height=find_height();
              if(temp1_height<1000)
                Required_height=temp1_height;    //keep updating the required height in normal mode  
              break;
              
      case 1://altitute hold mode
              temp2_height=find_height(); 
              if(temp2_height<1000)
                current_height=temp2_height;
                
              //PID implementation  //update values
              error=Required_height-current_height;     derror=error-pre_error;     pre_error=error;    ierror+=error;
              
              p_value=p*(error);      I_value=I*(ierror);     D_value=D*(derror);
              
              total=p_value+I_value+D_value;
              input_THROTTLE1+=total;
              break; 
    }
  channel3.writeMicroseconds(input_THROTTLE1);          
}
