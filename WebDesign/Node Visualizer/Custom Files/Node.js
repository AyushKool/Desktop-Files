class Node {
	constructor(data, next = null) {
		this.data = data;
		this.next = null;
		this.x = 200;
		this.y = 200;
	}

	display()
	{
		noStroke();
		fill(255, 255, 255, 175);
		rect(this.x, this.y, 100, 250, 25);
	}
}