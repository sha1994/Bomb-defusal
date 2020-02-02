
Timer redTimer;
bool clicked = false;
bool colorOff = false;
bool alone = true;
void setup() {
   if(!isAlone()){
    redTimer.set(6000);
 };
}

void loop() {
FOREACH_FACE(f) {//check every face
    if (isValueReceivedOnFaceExpired(f)) {//no one there
      alone = true;
    } else {//someone there
      alone = false;
    }
  }
  byte dimness = millis() % 30000;
  
  if(alone == false){
      if (redTimer.isExpired()) {
         setColor(GREEN);
         colorOff=true;
      }
    
  }else{
    setColor(dim(CYAN, dimness));
  }
  
}
