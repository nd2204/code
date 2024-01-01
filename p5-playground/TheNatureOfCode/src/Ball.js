class Ball {
    constructor(x, y, m)
    {
        this.location = new p5.Vector(x, y);
        this.velocity = createVector(0, 0);
        this.acceleration = createVector(0, 0);
        this.mass = m;
    }

    show()
    {
        fill(100, 150, 100, 200);
        stroke(0, 50);
        ellipse(this.location.x, this.location.y, this.mass*20, this.mass*20);
    }

    update()
    {
        this.velocity.add(this.acceleration)
        this.location.add(this.velocity)
        this.acceleration.mult(0)
    }

    checkEdge()
    {
        if (this.location.x > width)
        {
            this.location.x = width;
            this.velocity.x *= -1;
        }
        else if (this.location.x < 0 + this.mass * 10)
        {
            this.location.x = 0 + this.mass * 10;
            this.velocity.x *= -1;
        }

        if (this.location.y > height - this.mass * 10)
        {
            this.location.y = height - this.mass * 10;
            this.velocity.y *= -1;
        }
        else if (this.location.y < 0)
        {
            this.location.y = 0;
            this.velocity.y *= -1;
        }
    }

    applyForce(force)
    {
        let f = p5.Vector.div(force, this.mass)
        this.acceleration.add(f)
    }

    isInside(liquid)
    {
        if (this.location.x > liquid.x && this.location.x < liquid.x + liquid.width)
        {
            if (this.location.y > liquid.y && this.location.y < liquid.y + liquid.height)
            {
                return true;
            }
            return false
        }
        return false
    }

    drag(liquid) {
        if (this.isInside(liquid)) {
            let speed = this.velocity.mag();
            let dragMagnitute = liquid.coeff * speed * speed;  
            let drag = this.velocity.copy();

            drag.normalize().mult(-1);
            drag.mult(dragMagnitute)

            this.applyForce(drag)
        }
    }
}
