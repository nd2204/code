var speed = 1;
var obj_width = 20;
var obj_height = 20;
var x = 0;
var y = 0;
var foo = 0;

function setup() {
    createCanvas(windowWidth, windowHeight);
}

function draw() {
    background(12, 13, 22);
    for (let i = 0; i < windowHeight; i += obj_height) {
        rect(x, y + i, obj_width, obj_height);
        if (y >= windowHeight / 2) {
            foo = windowWidth - (i + obj_width);
        } else {
            foo += obj_width;
        }
        x = windowWidth - foo;
    }
    if (obj_width >= windowWidth - 20 || obj_width < 0) {
        speed *= -1;
    }
    obj_width += speed;
}
