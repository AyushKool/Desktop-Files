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