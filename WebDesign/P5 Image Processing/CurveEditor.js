// import Point from "./Custom Files/Point"

let points = [];
let resPoint;
let pX, pY;
let numLines = 1;
let pClicked = -1;
let slider;
let resultCanvas;
let canvasSize = {
	x:1200,
	y:700
};

function setup() {
	createCanvas(canvasSize.x, canvasSize.y);
	resultCanvas = createGraphics(width, height);
	// resultCanvas.clear();
	slider = createSlider(0, 1, .5, 0);
	//Make Points
	let section = width / (3 * numLines);
	let x = section / 2, y = height / 2;
	points.push(new Point(x, y, 20));
	points.push(new Point(x + section, y));
	points.push(new Point(x + 2 * section, y, 20));
	temp.push(points[1].copy());
	pX = points[1].x; py = points[1].y;
	resPoint = points[1].copy();
	resPoint.r = 20;
}

let temp = [];
function draw() {
	background(0);
	let t = slider.value();
	if (pClicked != -1 && pClicked % 3 != 1) {
		points[pClicked].move(mouseX, mouseY);
		resultCanvas.clear();
		resultCanvas.background(0, 0, 0, 0);
	}

	let j = 0;
	for (let i = 0; i < points.length; i += 3) {
		points[i + 1].move(mylerp(points[i].x, points[i + 2].x, t), mylerp(points[i].y, points[i + 2].y, t));
		temp[j++] = points[i + 1].copy();
	}
	let n = temp.length, i = 0;
	while (slider.mousePressed && n != 1) {
		if (i == n - 1) {
			i = 0;
			n--;
		}
		temp[i].move(mylerp(temp[i].x, temp[i + 1].x, t), mylerp(temp[i].y, temp[i + 1].y, t));
		i++;
	}
	pX = resPoint.x;
	pY = resPoint.y;
	resPoint = temp[0];
	resPoint.r = 20;

	display();
	image(resultCanvas, 0, 0);
}

function display() {
	for (let i = 0; i < numLines * 3; i += 3) {
		DrawLine(points[i], points[i + 2]);
		points[i].show();
		points[i + 2].show();
	}
	for (let i = 1; i < numLines * 3; i += 3)
		points[i].show(false, color(255));

	resultCanvas.stroke(0, 100, 0)
	resultCanvas.strokeWeight(5)
	if (!mousePressed || !inScreenPress())
		resultCanvas.line(pX, pY, resPoint.x, resPoint.y);

	resPoint.show(false, color(0, 100, 0));
}

function DrawLine(p1, p2, col = color(255)) {
	push();
	stroke(col)
	strokeWeight(3)
	line(p1.x, p1.y, p2.x, p2.y);
	pop();
}

function midPoint(p1, p2) {
	return new Point((p1.x + p2.x) / 2, (p1.y + p2.y) / 2);
}

function inScreenPress() {
	return mouseX > 0 && mouseX < width && mouseY > 0 && mouseY < height;
}

function mousePressed() {
	//bug: when t is 0, point not moving
	if (!inScreenPress()) return;
	for (let i = points.length - 1; i >= 0; i--) {
		if (points[i].clicked(mouseX, mouseY) && i % 3 != 1) {
			pClicked = i;
			return;
		}
	}
	let last = points[points.length - 1];
	let curr = new Point(mouseX, mouseY, 20);
	points.push(last);
	points.push(midPoint(last, curr));
	points.push(curr);
	numLines++;
	resultCanvas.clear();
	resultCanvas.background(0, 0, 0, 0);
	temp.push(midPoint(last, curr));
}

function mouseReleased() {
	pClicked = -1;
}

function mylerp(a, b, t) {
	return (b - a) * t + a
}

class Point {
	constructor(x, y, r = 15) {
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
			resultCanvas.ellipse(this.x, this.y, this.r*2);
		}
		else
			ellipse(this.x, this.y, this.r*2);
		pop();
	}

	clicked(mX, mY) {
		return dist(mX, mY, this.x, this.y) <= this.r;
	}

	getVec3 = () => [this.x, this.y, 1];
}

