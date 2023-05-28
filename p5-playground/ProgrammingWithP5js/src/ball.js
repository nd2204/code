class Ball {
  constructor (x, y, radius) {
    this.x = x || 300;
    this.y = y || 300;
    this.xspeed = 3;
    this.yspeed = -3;
    this.radius = radius || 100;
    this.i = Math.round(random(0,4));
    this.alpha = 0;
  }

  changeColor(index, alpha) {
    this.alpha = alpha
    switch (index) {
      case 0: fill(184, 187, 38, alpha); break;
      case 1: fill(250, 189, 47, alpha); break;
      case 2: fill(131, 165, 152, alpha); break;
      case 3: fill(211, 134, 155, alpha); break;
      case 4: fill(142, 192, 124, alpha); break;
      case 5: fill(254, 128, 25, alpha); break;
      case 6: fill(235, 219, 178, alpha); break;
      case 7: fill(251, 72, 52, alpha); break;
      case 8: fill(29, 32, 33, alpha); break;
    }
  }

  contain(px , py) {
    let mouseToObjectDist = dist(this.x, this.y, px, py)
    if ( mouseToObjectDist <= this.radius/2) {
      return true
    }
    return false
  }

  show() {
    stroke(255)
    strokeWeight(5)
    fill(255, this.alpha)
    ellipse(this.x, this.y, this.radius);
  }

  randomWalk() {
    this.x += random(-this.xspeed, this.xspeed)
    this.y += random(-this.yspeed, this.yspeed)
  }

  move() {
    this.x += this.xspeed
    this.y += this.yspeed
  }

  bounce() {
    let bounced = false;

    if (this.x > windowWidth - this.radius || this.x < 0 + this.radius) {
      this.xspeed *= -1;
      bounced = true;
    } else if (this.y > windowHeight - this.radius || this.y < 0 + this.radius) {
      this.yspeed *= -1;
      bounced = true
    } else bounced = false;

    if (bounced) changeColor(this.i)
  }
  reset() {

    if (this.x > windowWidth - this.radius)  {
      this.x = this.radius;
    } else if (this.x < this.radius) {
      this.x = windowWidth - this.radius;
    } 

    if (this.y > windowHeight - this.radius ) {
      this.y = this.radius;
    } else if (this.y < this.radius) {
      this.y = windowHeight - this.radius;
    }

    changeColor(this.i, this.alpha)
  }
}
