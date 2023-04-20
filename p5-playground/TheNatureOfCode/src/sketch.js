var xoff = 0
var yoff = 0
function setup() {
    //Initialize canvas createCanvas(w,h,[renderer]) [renderer] = P2D or WEBGL
    // P2D origin is on the top-left while WEBGL is at the center of the canvas
    //none = default
    createCanvas(windowWidth,windowHeight-4);
    background(11,13,22)
}

// this will update all code at 60fps
function draw() {
    background(11,13,22)
    // var x = map(noise(mouseX), 0, 1, 0, windowWidth, false)
    // var y = map(noise(mouseY), 0, 1, 0, windowHeight, false)
    line(0,mouseY,windowWidth,mouseY)
    line(mouseX,0,mouseX,windowHeight)
    xoff += 0.02
    yoff += 0.01
    // Clicking in the box toggles fullscreen on and off.
    print("mousePos: %d-%d", mouseX, mouseY)
    if (mouseIsPressed) {
        rect(0,0,mouseX,mouseY)
        fill(30,30,30)
    }
}

function mousePressed() {
}
