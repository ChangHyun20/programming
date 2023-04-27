class robot{
  robot(float a,float b, float c){
    x = a;
    y = b;
    s = c;
    vx = random(5,10);
    vy = random(1,3);
  }
  float s, x, y, vx, vy;
  void update(){
   x += vx;
   y += vy;
   if(x<0 || x>width) vx = - vx;
   if(y<0 || y>height) vy = - vy;
  }
  void robotShow(){
  background(225);
  //face
  fill(0,255,255);
  rect(x-100*s,y-50*s,200*s,100*s);
  //eyes
  fill(255,255,255);
  circle(x-50*s,y-25*s,40*s);
  circle(x+50*s,y-25*s,40*s);
  fill(0,0,0);
  circle(x-50*s,y-25*s,30*s);
  circle(x+50*s,y-25*s,30*s);
  //mouth
  fill(255,255,255);
  rect(x-50*s,y+25-2.5*s,100*s,5*s);
  //neck
  rect(x-40*s,y+50*s,80*s,5*s);
  //body
  fill(0,255,0);
  square(x-75*s,y+55*s,150*s);
  //foot
  fill(0,0,0);
  circle(x-40*s,y+230*s,50*s);
  circle(x+40*s,y+230*s,50*s);
}
}
