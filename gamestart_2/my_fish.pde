void my_fish(float a,float b){
//몸통
  fill(252,121,21);
beginShape();
vertex(a,b);
bezierVertex(a,b,a+10,b-40,a+55,b-10);
endShape();
beginShape();
vertex(a,b);
bezierVertex(a,b,a+10,b+40,a+55,b-10);
endShape();
//지느러미
fill(252,121,21);
beginShape();
vertex(a+10,b-10);
bezierVertex(a+8,b-10,a+16,b-50,a+50,b-20);
endShape();
//눈
fill(0);
circle(a+10,b,12);
fill(255);
circle(a+9,b,7);

//꼬리
 fill(252,121,21);
beginShape();
vertex(a+55,b-10);
bezierVertex(a+55,b-10,a+60,b-50,a+70,b+5);
endShape();
beginShape();
vertex(a+55,b-10);
bezierVertex(a+55,b-10,a+60,b-60,a+70,b-15);
endShape();
//아가미
strokeWeight(2.5);
stroke(255,229,203);
bezier(a+30,b-20,a+15,b-10,a+35,b,a+30,b+10);
bezier(a+40,b-16,a+30,b-10,a+45,b-5,a+40,b+5);

}