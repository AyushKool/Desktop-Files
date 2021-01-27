let cWidth = 600, cHeight = 600;
let pixDen;
let img;
const gpu = new GPU();

const multiplyMat = gpu.createKernel(function (a, b) {
	let sum = 0;
	for (let i = 0; i < 3; i++) {
		sum += a[this.thread.y][i] * b[i][this.thread.x];
	}
	return sum;
}).setOutput([3,3]);

function preload() {
	img = loadImage('./Rainbow.png');
}

function setup() {
	createCanvas(cWidth, cHeight);
	img = new Img(img, cWidth, cHeight);
	

	let a = new Mat3x3(1, 2, 3, 4, 5, 6, 7, 8, 9);
	let b = new Mat3x3(9, 8, 7, 6, 5, 4, 3, 2, 1);
	// console.log(a);
	// console.log(b);
	console.log(multiplyMat(a.mat, b.mat));
	// pixDen = pixelDensity();
}

function draw() {
	background(0)
	img.show();


	// let pink = color(255, 102, 204);
	// loadPixels();
	// let halfImage = 4 * (width * pixDen) * (height / 2 * pixDen);
	// for (let i = 0; i < halfImage; i += 4) {
	//      pixels[i] = red(pink);
	//      pixels[i + 1] = green(pink);
	//      pixels[i + 2] = blue(pink);
	//      pixels[i + 3] = alpha(pink);
	// }
	// updatePixels();

}

//--------------------------------
//Helper Classes and functions
class Point {
	constructor(x, y, r = 30) {
		this.x = x;
		this.y = y;
		this.r = r;
	}

	copy() {
		return new Point(this.x, this.y, this.r);
	}

	move(x, y) {
		this.x = x;
		this.y = y;
	}

	show(isResult = false, col = color(200, 0, 100)) {
		push();
		fill(col)
		strokeWeight(3)
		if (isResult) {
			resultCanvas.noStroke();
			resultCanvas.fill(color(0, 150, 0))
			resultCanvas.ellipse(this.x, this.y, this.r);
		}
		else
			ellipse(this.x, this.y, this.r);
		pop();
	}

	clicked(mX, mY) {
		return dist(mX, mY, this.x, this.y) <= this.r - 3;
	}

	getVec3 = () => [this.x, this.y, 1];
}

class Mat3x3 {
     constructor(a = 1, b = 0, c = 0, d = 0, e = 1, f = 0, g = 0, h = 0, i = 1) {
          this.mat = [
               [a, b, c],
               [d, e, f],
               [g, h, i]
          ];
     }

     multiply(other) {
          if (other instanceof Mat3x3) {
               //Mat * Mat
               let ans = new Mat3x3();
               for (let i = 0; i < 3; i++) {
                    for (let j = 0; j < 3; j++) {
                         let sum = 0;
                         for (let k = 0; k < 3; k++)
                              sum += this.mat[i][k] * other.mat[k][j];
                         ans.mat[i][j] = sum;
                    }
               }
               return ans;
          }
          else if (Array.isArray(other) && other.length == 3) {
               //Mat * vec
               let ans = [0, 0, 0];
               for (let i = 0; i < 3; i++) {
                    for (let j = 0; j < 3; j++) {
                         ans[i] += this.mat[i][j] * other[j];
                    }
               }
               return ans;
          }
          return null;
     }

     scale(factor = 1)
     {
          if(!Number.isFinite(factor)) return;
          for (let i = 0; i < 3; i++) {
               for (let j = 0; j < 3; j++) {
                    this.mat[i][j] *= factor;
               }
          }
     }

     set(i, j, val) {
          if (i < 0 || i >= 3 || j < 0 || j >= 3) return;
          this.mat[i][j] = val;
     }

     get(i, j) {
          if (i < 0 || i >= 3 || j < 0 || j >= 3) return;
          return this.mat[i][j];
     }

     inverse()
     {
          //https://semath.info/src/inverse-cofactor-ex3.html

          //calculate determinant
          let det = this.mat[0][0]*this.mat[1][1]*this.mat[2][2] //11*22*33
               + this.mat[0][1]*this.mat[1][2]*this.mat[2][0]    //12*23*31
               + this.mat[0][2]*this.mat[1][0]*this.mat[2][1]    //13*21*32
               - this.mat[0][2]*this.mat[1][1]*this.mat[2][0]    //13*22*31
               - this.mat[0][1]*this.mat[1][0]*this.mat[2][2]    //12*21*33
               - this.mat[0][0]*this.mat[1][2]*this.mat[2][1];   //11*23*32
          det = 1.0/det;

          //calculate adj(M)
          let adj = new Mat3x3();
          adj.mat[0][0] = this.mat[1][1]*this.mat[2][2] - this.mat[1][2]*this.mat[2][1];
          adj.mat[0][1] = this.mat[0][2]*this.mat[2][1] - this.mat[0][1]*this.mat[2][2];
          adj.mat[0][2] = this.mat[0][1]*this.mat[1][2] - this.mat[0][2]*this.mat[1][1];

          adj.mat[1][0] = this.mat[1][2]*this.mat[2][0] - this.mat[1][0]*this.mat[2][2];
          adj.mat[1][1] = this.mat[0][0]*this.mat[2][2] - this.mat[0][2]*this.mat[2][0];
          adj.mat[1][2] = this.mat[0][2]*this.mat[1][0] - this.mat[0][0]*this.mat[1][2];

          adj.mat[2][0] = this.mat[1][0]*this.mat[2][1] - this.mat[1][1]*this.mat[2][0];
          adj.mat[2][1] = this.mat[0][1]*this.mat[2][0] - this.mat[0][0]*this.mat[2][1];
          adj.mat[2][2] = this.mat[0][0]*this.mat[1][1] - this.mat[0][1]*this.mat[1][0];

          adj.scale(det);
          return adj;
     }
}

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
		for (let p of this.corners)
			p.show();
	}
}

function getTransformationMat(srcPts, dstPoints) {
	const A = [
		[srcPts[0].x, srcPts[0].y, 1, 0, 0, 0, - srcPts[0].x * dstPoints[0].x, - srcPts[0].y * dstPoints[0].x],
		[0, 0, 0, srcPts[0].x, srcPts[0].y, 1, - srcPts[0].x * dstPoints[0].y, - srcPts[0].y * dstPoints[0].y],
		[srcPts[1].x, srcPts[1].y, 1, 0, 0, 0, - srcPts[1].x * dstPoints[1].x, - srcPts[1].y * dstPoints[1].x],
		[0, 0, 0, srcPts[1].x, srcPts[1].y, 1, - srcPts[1].x * dstPoints[1].y, - srcPts[1].y * dstPoints[1].y],
		[srcPts[2].x, srcPts[2].y, 1, 0, 0, 0, - srcPts[2].x * dstPoints[2].x, - srcPts[2].y * dstPoints[2].x],
		[0, 0, 0, srcPts[2].x, srcPts[2].y, 1, - srcPts[2].x * dstPoints[2].y, - srcPts[2].y * dstPoints[2].y],
		[srcPts[3].x, srcPts[3].y, 1, 0, 0, 0, - srcPts[3].x * dstPoints[3].x, - srcPts[3].y * dstPoints[3].x],
		[0, 0, 0, srcPts[3].x, srcPts[3].y, 1, - srcPts[3].x * dstPoints[3].y, - srcPts[3].y * dstPoints[3].y]

	];
	const x = [dstPoints[0].x, dstPoints[0].y, dstPoints[1].x, dstPoints[1].y, dstPoints[2].x, dstPoints[2].y, dstPoints[3].x, dstPoints[3].y]
}

//https://p5js.org/reference/#/p5/pixels
//https://www.bennettnotes.com/gpu-programming-in-javascript/
//https://compform.net/pixels/

//https://gist.github.com/ognjenvucko/1e6ee7b3ee62f0ee4fde4255384f4352#file-gettransformationmatrix-js
//https://discourse.processing.org/t/how-to-position-image-correctly-with-applymatrix/21766/4