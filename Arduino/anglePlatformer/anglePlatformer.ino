
#include <TLE5012-ino.hpp>

Tle5012Ino Tle5012Sensor = Tle5012Ino();
double angleBuffer[3]={0};
int indexCounter=0;
errorTypes checkError = NO_ERROR;

//function to shift the buffer to the right 
void shiftRight(double arr[3]) {
    double last = arr[2];
    for (int i = 2; i > 0; i--) {
        arr[i] = arr[i-1];
    }
    arr[0] = last;
}


void setup() {
  delay(2000);
  Serial.begin(9600);
  while (!Serial) {};
  checkError = Tle5012Sensor.begin();
  Serial.print("checkError: ");
  Serial.println(checkError,HEX);
  delay(1000);
  Serial.println("Init done");
  int counterIndex=0;
}

void loop() {
  

  
  shiftRight(angleBuffer);
  Tle5012Sensor.getAngleValue(angleBuffer[0]);


  //Rotation Direction Calculation
  if(indexCounter==2){

  if(abs(abs(angleBuffer[0])-abs(angleBuffer[1]))>4){

   
    // Assuming all are positive (Right side of the circle)
    if((angleBuffer[0]>0) && (angleBuffer[1]>0) && (angleBuffer[2]>0) ){


        // Clockwise
        if((angleBuffer[0]<angleBuffer[1])&&(angleBuffer[1]<=angleBuffer[2])){
            Serial.println(angleBuffer[0]);
            Serial.println("Clockwise Motion Detected");
        }
    
    
    
        // Anti Clockwise
        if((angleBuffer[0]>angleBuffer[1])&&(angleBuffer[1]>angleBuffer[2])){
            Serial.println(angleBuffer[0]);
            Serial.println("Anti Clockwise Motion Detected");
        }
        
    }




      
    //Assuming all are negative (Left Side of the circle)
   if((angleBuffer[0]<0) && (angleBuffer[1]<0) && (angleBuffer[2]<0) ){
      
        // Clockwise
        if((angleBuffer[0]<angleBuffer[1])&&(angleBuffer[1]<angleBuffer[2])){
            Serial.println(angleBuffer[0]);
            Serial.println("Clockwise Motion Detected");
        }
    
    
    
        // Anti Clockwise
        if((angleBuffer[0]>angleBuffer[1])&&(angleBuffer[1]>angleBuffer[2])){
            Serial.println(angleBuffer[0]);
            Serial.println("Anti Clockwise Motion Detected");
        }
   }






   //Assuming only last is negative and bf and f are positive (TOP SIDE)
  if((angleBuffer[0]<0) && (angleBuffer[1]>0) && (angleBuffer[2]>0)){




      // Anti Clockwise
      if((angleBuffer[0]<angleBuffer[1])&&(angleBuffer[1]>angleBuffer[2])){
           Serial.println(angleBuffer[0]);
           Serial.println("Anti Clockwise Motion Detected");
      }
  
    
  }



//Assuming last and bf are negative and f is positive (TOP SIDE)
  if((angleBuffer[0]<0) && (angleBuffer[1]<0) && (angleBuffer[2]>0)){







    // Anti Clockwise

    if((angleBuffer[0]>angleBuffer[1])&&(angleBuffer[1]<angleBuffer[2])){
        Serial.println(angleBuffer[0]);
        Serial.println("Anti Clockwise Motion Detected");
    }
  }


//Assuming last and bf are positive and f is negative (TOP SIDE)
  if((angleBuffer[0]>0) && (angleBuffer[1]>0) && (angleBuffer[2]<0)){



    //Clockwise
    if((angleBuffer[0]<angleBuffer[1])&&(angleBuffer[1]>angleBuffer[2])){
      Serial.println(angleBuffer[0]);
      Serial.println("Clockwise Motion Detected");
    }

    
  }


//Assuming last is positive and bf and f are negative (TOP SIDE)
  if((angleBuffer[0]>0) && (angleBuffer[1]<0) && (angleBuffer[2]<0)){

      if((angleBuffer[0]>angleBuffer[1])&&(angleBuffer[1]<angleBuffer[2])){
        Serial.println(angleBuffer[0]);
        Serial.println("Clockwise Motion Detected");
      }



    
  }
  }






  
  indexCounter=0;
 }else{
  
  indexCounter++;
  }







  delay(20);
}
