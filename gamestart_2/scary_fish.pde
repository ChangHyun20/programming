void scary_shark(float a, float b){
//지느러미
noStroke();
fill(96,96,96);
beginShape();
vertex(a,b);
bezierVertex(a-40,b-40,a-90,b-70,a-170,b-50);
bezierVertex(a-120,b-20,a-110,b-10,a-110,b+30);
bezierVertex(a-110,b+30,a,b,a,b);
endShape();
//아랫배
fill(255);
beginShape();
vertex(a+80,b+80);
bezierVertex(a+80,b+90,a+100,b+140,a+140,b+120);
bezierVertex(a,b+230,a-130,b+190,a-250,b+90);
bezierVertex(a-250,b+90,a+80,b+80,a+80,b+80);
endShape();
//몸통
fill(128,128,128);
beginShape();
vertex(a+180,b+40);
bezierVertex(a+170,b+30,a+60,b-10,a,b-10);
bezierVertex(a-50,b-10,a-170,b+60,a-250,b+50);
bezierVertex(a-260,b,a-310,b-20,a-330,b-20);
bezierVertex(a-300,b+10,a-290,b+90,a-300,b+130);
bezierVertex(a-280,b+130,a-250,b+100,a-250,b+90);
bezierVertex(a-220,b+110,a-160,b+130,a-110,b+140);
bezierVertex(a-110,b+150,a-120,b+190,a-120,b+200);
bezierVertex(a-80,b+190,a-50,b+160,a-40,b+150);
bezierVertex(a+10,b+150,a+70,b+110,a+80,b+80);
bezierVertex(a+90,b+90,a+120,b+110,a+140,b+120);
bezierVertex(a+160,b+100,a+180,b+50,a+180,b+40);
endShape();
//눈
fill(255);
ellipse(a+30,b+30,60,48);
fill(255,0,0);
ellipse(a+38,b+30,44,32);
}
