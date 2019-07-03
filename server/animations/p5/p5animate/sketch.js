var y = 100;
var s=0;
var k=0;
var c=255;
var a=255;
var d;
var state=0;

// The statements in the setup() function 
// execute once when the program begins
function setup() {
  noStroke();
	// createCanvas must be the first statement
  createCanvas(800, 475);  
  frameRate(30);
  textSize(35);
  textAlign(CENTER, CENTER);
}
// The statements in draw() are executed until the 
// program is stopped. Each statement is executed in 
// sequence and after the last line is read, the first 
// line is executed again.
function draw() {
  if (state==0){
background(0);  
 fill(c,c,c,a);
  ellipse(width/2, height/2, s, s);
  fill(255,200,200,a);
  ellipse(width/2,height/2,k,k);
  s++;
  k=k+2;
  a-=.25;
   d = dist(width/2, height/2, mouseX, mouseY);  
 // if (d<s/2){
 //  background(255,0,0);
 // }
   // if (d<20){
   //   background(255,0,0); 
   // }else{
   //   background(0); 
   // }
if(k>1500){
    k=0;
   ka=255
  }
  if(s>1500){
    s=0;
    a=255;
  }
}
if(state==1){
    background(255,0,0);
   
fill(0);
textAlign(CENTER);
  text("select archive by tapping glowing panels", width/2, 80);
  text("then press button to email your selecton", width/2, 400);
   d = dist(width/2, height/2, mouseX, mouseY);
  ellipse(width/2,height/2,s,s);
  
  s++;
  
  a--;
  if(s>300){
    s=0;
    a=255;
  }
   
}
} 
function touchEnded(){

// function mouseReleased() {
  if(state==0){
  if (d<s/2){
    state=1;
    s=0;
    a=255;
}
}

    if(state==1){
  if (d<s/2){
    // 
window.location.href = "http://127.0.0.1:9030";
 
 }
}
}