class Walker {
    constructor(x, y) {
        this.location = createVector(x, y)
        this.velocity = createVector(0, 0);
        this.acceleration = createVector(0.01, 0.01);
        this.topspeed = 5;
    }

    show() {
        stroke(255);
        strokeWeight(2)
        point(this.location.x, this.location.y);
    }

    showEllipse() {
        ellipse(this.location.x, this.location.y, 20, 20);
        stroke(255)
        line(mouseX, mouseY, this.location.x, this.location.y)
    }

    stepSize(magnitute) {
        this.stepsize = magnitute
    }

    update() {
        this.velocity.add(this.acceleration)
        this.velocity.limit(this.topspeed)
        this.location.add(this.velocity)
    }

    walk() {
        let choices = random(1)
        let jumpSize = this.stepsize.mult(100)
        if (choices < 0.001) {
        } else {
            this.vector.add(jumpSize, jumpSize)
        }
        console.log( this.location.x, this.location.y, choices )
    }

    walkToMouse(mouse) {
        let choices = random(1)
        let mouseDir = p5.Vector.sub(mouse, this.location)
        mouseDir.normalize();
        mouseDir.mult(0.5)
        this.velocity.add(this.acceleration)
        this.velocity.limit(this.topspeed)

        if (choices < 1) {
            this.acceleration = mouseDir
            this.location.add( this.velocity );
        } else {
            this.location.add( this.velocity )
        }
        console.log( this.acceleration );
    }
}
