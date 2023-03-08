float s,t,u;
void setup(){
  size(600,400);
  s = 100;
  t = 50;
  u = 10;
  house();
}
void house(){
  fill(0,100,0);
  quad(s+t,3*s+t,4*s,3*s+t,4*s,2*s+t+3*u,s+t,2*s+8*u);
  fill(150,150,150);
  s += 200;
  t += 150;
  triangle(s,t,0.5*s,t+80,s+100,t+80);
  s -= 200;
  t -= 150;
  fill(0,100,0);
  quad(4*s,3*s+t,4*s+8*u,3*s+u,4*s+8*u,2*s+40,4*s,2*s+80);
  fill(150,150,150);
  triangle(4*s,2*s+8*u,4*s+8*u,2*s+t-u,3*s,2*s);
  fill(0,0,100);
  u = 0.5*u;
  circle(2*s+t+5*u,3*s+u*3,10*u);
  
}
  
