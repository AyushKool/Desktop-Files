let nodes = [];
let addNodeBtn;

function setup() {
	createCanvas(screen.width, screen.height);
	console.log(nodes);
	addNodeBtn = createButton("Create new node");
	addNodeBtn.position(50, 50);
	addNodeBtn.mouseClicked(addNode);
}

function draw() {
	background(0);
	// addNodeBtn.draw();
	for(let n of nodes) n.display();

}

function addNode() {
	nodes.push(new Node());
	console.log(nodes);
}