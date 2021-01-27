class Circle {
	constructor(x, y, r = 15) {
		this.x = x;
		this.y = y;
		this.r = r;
	}

	show(col = color(200, 100)) {
		fill(col)
		strokeWeight(3)
		ellipse(this.x, this.y, this.r*2);
	}

	clicked(mX, mY) {
		return dist(mX, mY, this.x, this.y) < this.r;
	}

	getDist(other)
	{
		return dist(other.x, other.y, this.x, this.y) - other.r;
	}
}

let cWidth = 1201, cHeight = 601;
let point;
let addBtn;
let isPointClicked = false;
let shapes;

function setup() {
	createCanvas(cWidth, cHeight);
	background(51);
	point = new Circle(cWidth/2, cHeight/2);
	shapes = [];
	addBtn = createButton('ADD SHAPE');
	addBtn.position(cWidth/2, cHeight);
	addBtn.mousePressed(addShape);
}

function addShape(x = random(0, cWidth), y = random(0, cHeight))
{
	shapes.push(new Circle(x, y, random(50, 100)))
}

function mousePressed()
{
	if(mouseX <0 || mouseX>cWidth || mouseY<0 || mouseY > cHeight) return;
	isPointClicked = point.clicked(mouseX, mouseY);
	if(!isPointClicked)
	{
		addShape(mouseX, mouseY);
	}
}

function mouseReleased() {isPointClicked = false;}

function draw()
{
	background(51)
	if(isPointClicked)
	{
		point.x = mouseX;
		point.y = mouseY;
	}
	let minDist = Infinity, d;
	for (const shape of shapes) {
		shape.show()
		d = point.getDist(shape)
		if(d < minDist) minDist = d;
	}

	minDist > 0 ? fill(0,200,0, 220) : fill(200,0,0, 220)
	ellipse(point.x, point.y, minDist * 2);
	point.show(color(200,100,100));
}