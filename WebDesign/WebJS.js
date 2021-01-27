//watch 2.6 createGraphics()
//watch 7.8 sting cat ES6

var pos = {x : 0, y : 0};
var speed = {x:3.0, y:0.0};
var g = 1;
function setup()
{
	createCanvas(600, 600);
	pos.x = random(50, width-50);
	pos.y = random(50, height-50);
	background(0);
}

function draw()
{
	background(0);
	if (abs(speed.x)<.2)
		speed.x = 0;
	pos.x += speed.x;
	pos.y += speed.y;
	speed.y += g;
	circle(pos.x, pos.y, 25);
	if (pos.y >= height-26)
		speed.y *= -.85;
	if (pos.x >= width-26 || pos.x <= 26)
		speed.x *= -.85;
	if (pos.y>height-30 && abs(speed.y)<5)
	{
		pos.y = height-25;
		speed.y = 0.2;
		g=0;
	}
}