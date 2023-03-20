int score, result;
void timer() {
  textSize(100);
  text(score, width/2-30, height/2);
  score++;
  if(start==0){
    score=0;
  }
}
