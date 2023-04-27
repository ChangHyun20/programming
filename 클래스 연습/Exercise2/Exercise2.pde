Siha a, b, c, d, e;
void setup() {
  size(1000, 300);
  a = new Siha(100, 100, 100,0);
  b = new Siha(200, 100, 150,1);
  c = new Siha(300, 100, 150,2);
  d = new Siha(400, 100, 150,3);
  e = new Siha(500, 100, 150,4);
  a.Life();   b.Life();   c.Life(); d.Life(); e.Life();
}
class Siha {  
  Siha(float p, float q, float r, int cc) {
    x = p;      y = q;     d = r;   c=cc;
  }
  Siha() {  
    x = random(0,width);
    y = random(0,height);
    d = 50;
  };
  float x, y, d; int c;
  void Life() {
    if (c==0){
      fill(255,255,0);
    }
    else if(c==1){
      fill(255);
    }
    else if(c==2){
      fill(0,255,255);
    }
    else if(c==3){
      fill(255,0,0);
    }
    else if(c==4){
      fill(0,0,255);
    }
    ellipse(x, y, d, d/3*2);
    circle(x-d/5, y-d/6, d/5);
    arc(x+d/5, y-d/6, d/5, d/5, PI, 2*PI);
    arc(x, y, d*2/3, d/5, 0, PI);
  }
}
