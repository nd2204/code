class Liquid {
  constructor( x_, y_, width_, height_, coeff_) {
    this.x = x_;
    this.y = y_;
    this.width = width_;
    this.height = height_;
    this.coeff = coeff_; 
  }

  display() {
    fill(0,200,255);
    rect(this.x, this.y, this.width, this.height)
  }
}
