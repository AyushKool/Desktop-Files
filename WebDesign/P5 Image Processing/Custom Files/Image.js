class Img {
     constructor(img, cWidth, cHeight) {
          this.img = img;
          this.width = this.img.width;
          this.height = this.img.height;
          
          //set up 4 corners

          this.corners = [new Point((int(cWidth - this.width) / 2), int((cHeight - this.height) / 2))]
          this.corners.push(new Point(this.corners[0].x + this.width, this.corners[0].y))
          this.corners.push(new Point(this.corners[0].x, this.corners[0].y + this.height))
          this.corners.push(new Point(this.corners[0].x + this.width, this.corners[0].y + this.height))

          // console.log(this.corners[0].x + ", " + this.corners[0].y)
     }

     show() {
          image(this.img, this.corners[0].x, this.corners[0].y);
          for(let p of this.corners)
               p.show();
     }
}