class punleu {
  // constructor
  punleu() {
    x = random(width);
    y = random(height);
    vx = 6;
    vy = 3;
    aa = new Siha[2];
    bb = new robot[1];
    for(int i=0;i<2;i++){
      aa[i] = new Siha(x+i*200-100,y);
    }
      bb[0] = new robot(x+100,y,1);
    
  }
  // member data
  float x, y, vx, vy;
  Siha [] aa;
  robot [] bb;
  // member function
  void update(){
   x += vx;
   y += vy;
   if(x<0 || x>width) vx = - vx;
   if(y<0 || y>height) vy = - vy;   
   for(int i=0;i<2;i++){
      aa[i].x =x+i*240-120;
      aa[i].y = y;
      bb[0].y = y-300;
      bb[0].x = x;
    
   }
  }
  void punleuShow() {
   
   bb[0].robotShow();
   for(int i=0;i<2;i++) aa[i].Life();
    fill(0, 0, 255);
    ellipse(x, y+30, 200, 210);
    fill(255);
    // eye
    ellipse(x-40, y, 50, 50);
    ellipse(x+30, y, 50, 50);
    // black eye
    fill(0);
    ellipse(x-40, y, 20, 20);
    ellipse(x+30, y, 20, 20);
    fill(0, 255, 0);
    //mouth
    arc(x, y+75, 80, 50, 0, 3.14);
    fill(0, 255, 0);
  }
}
