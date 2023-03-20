int buttonX, buttonY;
int buttonSize = 90;
color buttonColor, baseColor;
color buttonHighlight;
color currentColor;
boolean buttonOver = false;
int start;
int level;
int count;

float [] x,y,vx,vy;
float xx,yy;
float [] d,dd,ddd,dddd;
int gameOver;
float p_m,p_s,p_ms;

void setup() {
  size(1600, 900);
  buttonColor = color(0);
  buttonHighlight = color(51);
  baseColor = color(102);
  currentColor = baseColor;
  buttonX = width/2-buttonSize;
  buttonY = height/2-buttonSize/2;
  start = 0;
  level = 1;
  ellipseMode(CENTER);
  
  x = new float[10];
  y = new float[10];
  vx = new float[10];
  vy = new float[10];
  d = new float[10];
  dd= new float[10];
  ddd= new float[10];
  dddd= new float[10];
  
  for(int i = 0; i<10; i++){
  x[i] = 0;
  y[i] = 0;
  vx[i] = random(10);
  vy[i] = random(10);
  }
}

void draw() {
  if (start == 0){
  update(mouseX, mouseY);
  for (int i=0; i<width; i=i+1) {
  stroke(16+i/30, 160+i/20, 255);
  line(i,0,i,height);
  }
  scary_shark(600,500);
  my_fish(800,400);
  buble(200,500,60);
  buble(1200,700,70);
  buble(1000,300,50);
  buble(100,100,60);
  
  if (buttonOver) {
    fill(buttonHighlight);
  } else {
    fill(buttonColor);
  }
  stroke(255);
  rect(buttonX, buttonY, buttonSize, buttonSize);
  }
  else if (start == 1){
    count++;
    background(17,204,237);
    timer();
    if (count>600 && level<10){
      level++;
      count=0;
    }
    
    

     
  // 마우스 따라다니는 움직임 구현
   xx=mouseX;
   yy=mouseY;
   my_fish(xx,yy);
   
   // 벽과 충돌 및 폭탄 움직임 구현
   for(int i=0;i<level; i++){
    scary_shark(x[i],y[i]);
    x[i] += vx[i];
    y[i] += vy[i];
    if(x[i]<0 || x[i]>width) vx[i] = - vx[i];
    if(y[i]<0 || y[i]>height) vy[i] =  - vy[i];
  }
  
  for(int i=0;i<level;i++){
    d[i] = sqrt((xx-x[i]+202.5)*(xx-x[i]+202.5)+(yy-y[i]-100)*(yy-y[i]-100));
    if(d[i]<=72.5){
       gameOver = 1;
       result = score;
    }
     dd[i] = sqrt((xx-x[i]-82.5)*(xx-x[i]-82.5)+(yy-y[i]-110)*(yy-y[i]-110));
    if(dd[i]<=148.5){
       gameOver = 1;
       result = score;
    }
    ddd[i] = sqrt((xx-x[i]+77.5)*(xx-x[i]+77.5)+(yy-y[i]-15)*(yy-y[i]-15));
    if(ddd[i]<=86){
       gameOver = 1;
       result = score;
    }
    dddd[i] = sqrt((xx-x[i]-107.5)*(xx-x[i]-107.5)+(yy-y[i]-65)*(yy-y[i]-65));
    if(dddd[i]<=81){
       gameOver = 1;
       result = score;
    }  
  }
  
  if(gameOver==1){
    for (int i=0; i<width; i=i+1) {
  stroke(16+i/30, 160+i/20, 255);
  line(i,0,i,height);
  }
  scary_shark(600,500);
  my_fish(800,400);
  buble(200,500,60);
  buble(1200,700,70);
  buble(1000,300,50);
  buble(100,100,60);
    text("Game Over",height/2,width/2);
    text("Your score" +" "+ result,height/2-60,width/2-100);
    for(int i = 0; i<10; i++){
      x[i] = 0;
      y[i] = 0;
      vx[i]=0;
      vy[i]=0;
    }
    
    update(mouseX, mouseY);
    if (buttonOver) {
      fill(204);
    }
    else {
      fill(255);
    }
    stroke(255);
    rect(buttonX, buttonY, buttonSize, buttonSize);
  }
  
}
}

void update(int x, int y) {
  if ( overButton(buttonX, buttonY, buttonSize, buttonSize) ) {
    buttonOver = true;
  } else {
    buttonOver = false;
  }
}

void mousePressed() {
 if(start==1 && gameOver == 0 && level>=1){
  }
  else if (buttonOver && start==0) {
    gameOver = 0;
    start = 1;
    level = 1;
    count = 0;
  }
  else if(buttonOver && start==1) {
    gameOver = 0;
    start = 0;
    score = 0;
    result = 0;
    level = 1;
    count = 0;
    for(int i = 0; i<10; i++) {
      vx[i] = random(10);
      vy[i] = random(10);
    }
  }
  
}


boolean overButton(int x, int y, int width, int height)  {
  if (mouseX >= x && mouseX <= x+width && 
      mouseY >= y && mouseY <= y+height) {
    return true;
  } else {
    return false;
  }
}
