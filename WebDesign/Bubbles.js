//watch 2.6 createGraphics()
//watch 7.8 sting cat ES6

let bubbles = [];
//let img;

function preload()
{
	//img = loadImage("Image2.jpg")
}

function setup()
{
	createCanvas(800,600);
	getBubbles(5);
	
}

function draw()
{
	background(0);
	//image(img, 0, 0);
	for (let bubble of bubbles)
	{
		if (bubble.contains(mouseX, mouseY))
		{
			fill(200,0,100);
		}
		else
			noFill();
		bubble.move();
		bubble.show();
	}
	if (bubbles.length == 0)
	{
		strokeWeight(1);
		fill(255);
		textSize(20);
		text("All Bubbles Popped!", 100, 100);
	}
}

function mousePressed()
{
	for(let i=0; i<bubbles.length; i++)
		if(bubbles[i].contains(mouseX, mouseY))
			bubbles.splice(i,1);
}

function getBubbles(size)
{
	for (let i=0; i<size; i++)
		bubbles.push(new Bubble(random(50,width-50), random(50, height-50), random(15,50)));
}

class Bubble
{
	//comparing objects use === or !==
	constructor(x, y, r=50)
	{
		this.x = x;
		this.y = y;
		this.r = r;
		this.brightness = 0;
	}
	
	changeColor(bright)
	{
		this.brightness = bright;
	}
	
	contains(x, y)
	{
		let d = dist(x, y, this.x, this.y);
		return d<this.r;
	}
	
	intersects(other)
	{
		let d = dist(this.x, this.y, other.x, other.y);
		return d < this.r + other.r;
	}
	
	show()
	{
		stroke(255);
		strokeWeight(4);
		//fill(this.brightness, 125);
		ellipse(this.x, this.y, this.r*2);
	}
	
	move()
	{
		this.x += random(-5,5);
		this.y += random(-5,5);
	}
}