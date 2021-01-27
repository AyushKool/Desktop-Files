
let canvas;
let color = 
{
	r:0,
	g:0,
	b:0
};


function setup()
{
	canvas = createCanvas(windowWidth, windowHeight);
	
}

function draw()
{
	background(0);
	
}

mouseClicked()
{
	color.r = map(0,mouseX,0,255);
	color.g = map(0,mouseY,0,255);
	color.b = map(0,mouseX,0,255);
	fill(color.r, color.g, color.b);
	ellipse(mouseX, mouseY, random(10, 20));
}

// class Texture
// {
	
// }