Siha [] aa;
void setup() {
  size(1000, 500);
  aa = new Siha[50];
  for (int i=0; i<50; i++) {
    aa[i] = new Siha(random(0,1000), random(0,500), 5*random(10,20));
    aa[i].Life();
  }
}
