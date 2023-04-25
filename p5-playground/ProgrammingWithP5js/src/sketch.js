let ball = [];
let count = 0;

function createBall() {
    let x = random(windowWidth)
    let y = random(windowHeight)
    let radius = random(50,100)
    let b = new Ball( x, y, radius)
    ball.push(b)
}

function setup() {
    createCanvas(windowWidth, windowHeight)
    textSize(20)
    textAlign(CENTER, CENTER)
    for (let i = 0 ; i < 10; i++) {
        let x = random(windowWidth)
        let y = random(windowHeight)
        let radius = random(10,100)
        ball[i] = new Ball( x, y, radius);
    }
}

function mousePressed() {
    for (i = 0; i < ball.length; i++) {
        if (ball[i].contain( mouseX, mouseY)) {
            ball.splice(i,1)
            createBall()
            count +=1
        }
    }
}

function draw() {
    background(21,22,23)
    for (let elem of ball) {
        elem.show();
        elem.randomWalk()
        if (elem.contain(mouseX,mouseY)) {
            elem.changeColor(9,20)
        } else {
            elem.changeColor(9,0)
        }
        // elem.reset();
    }
    fill(255)
    noStroke()
    text(count, 20, 20);
}
