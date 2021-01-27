
//watch 2.6 createGraphics()
//watch 7.8 sting cat ES6

var col = 
{
	r: 0,
	g: 0,
	b: 255
};

function setup()
{
	createCanvas(windowWidth,windowHeight);
	background(0);
	noStroke();
}

function draw() 
{
	col.r = map(mouseX, 0, width, 0, 255);
	col.g = map(mouseY, 0, height, 0, 255);
	col.b = map(mouseX, 0, width, 255, 0);
	//background(col.r, col.g, col.b);
	
	fill(col.r, col.g, col.b, random(256));
	
	if (mouseX>=width)
		mouseX=width;
	if(mouseY>=height)
		mouseY = height;
	if (mouseIsPressed)
		ellipse(mouseX, mouseY, random(5,100));
}

function mousePressed()
{
	//background(random(256), random(256), random(256));
	//fill(col.r,col.g,col.b);
	//ellipse(mouseX, mouseY, 50);
}