const Width = 800;
const Height = 800;
var sizeX = 100;
var sizeY = 100;
var x = sizeX/2;
var y = 450;
var speedX = 10;
var speedY = 10;
let r,g,b;
function setup() {
    //Initialize canvas createCanvas(w,h,[renderer]) [renderer] = P2D or WEBGL
    // P2D origin is on the top-left while WEBGL is at the center of the canvas
    //none = default
    createCanvas(windowWidth,windowHeight-4);
    print(windowWidth + "x" + windowHeight-4 + "px Canvas");
    background(25, 24, 36);
}

function normalize(x, y) {
    return sqrt(x*x+y*y)
}

// this will update all code at 60fps
function draw() {
    background(25, 24, 36);
    r = g = b = 100;
    ellipse(x,y,sizeX,sizeY);
    fill(r,g,b,50);
    noStroke();

    if (y+sizeY/2 > windowHeight || y-sizeY/2 < 0) {
        speedY = -speedY;
    }    
    if (x+sizeX/2 > windowWidth || x-sizeX/2 < 0) {
        speedX = -speedX;
    }    
    x += speedX;
    y += speedY;
}
