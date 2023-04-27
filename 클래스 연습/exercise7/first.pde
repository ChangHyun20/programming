Siha [] aa;
punleu [] pp;
robot [] dd;
void setup() {
  size(800, 600);
  aa = new Siha[5];
  for (int i=0; i<5; i++) {
    aa[i] = new Siha();
  }
  pp = new punleu[3];
  for (int i=0; i<3; i++) {
    pp[i] = new punleu(random(width),random(height));
  }  
  dd = new robot[3];
 for (int i=0; i<3; i++) {
    dd[i] = new robot(random(width),random(height),1);
  } 
}
  void draw(){
  background(0,255,255);
  for (int i=0; i<3; i++){
    dd[i].update();
    dd[i].robotShow();
  }
  for (int i=0; i<3; i++) {
    pp[i].update2();
    pp[i].punleuShow();
  }  
  for (int i=0; i<5; i++) {
    if(i != 4){
      for(int j=i+1;j<5;j++){
        aa[i].collide(aa[j]);
      }
    }
    aa[i].act();
    aa[i].Life();
  }  
}
