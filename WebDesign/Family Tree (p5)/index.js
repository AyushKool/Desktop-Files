const gender = {
  male: true,
  female: false,
};

const pDim = {
  width: 150,
  height: 50,
  cornerRad: 10,
};

class Person {
  constructor(fname, lname, sex, pos = { x: width / 2, y: 20 }, level = 1) {
    this.fname = fname;
    this.lname = lname;
    this.gender = sex; //true for male and false for female
    this.parents = [];
    this.siblings = [];
    this.children = [];
    this.level = level;
    this.pos = pos;
    this.pos.x -= pDim.width / 2;
    // this.log = this.log.bind(this)
    // this.addParent = this.addParent.bind(this);
  }

  log() {
    console.log(
      `Name: ${this.fname} ${this.lname}\tGender: ${
        this.gender ? "Male" : "Female"
      }\tLevel:${this.level}`
    );
    console.log("Parents:");
    this.parents.forEach((parent) => {
      console.log(`\t${parent.fname} ${parent.lname}\tLevel:${parent.level}`);
    });
    console.log("Siblings:");
    this.siblings.forEach((sibling) => {
      console.log(
        `\t${sibling.fname} ${sibling.lname}\tLevel:${sibling.level}`
      );
    });
    console.log("Children:");
    this.children.forEach((child) => {
      console.log(`\t${child.fname} ${child.lname}\tLevel:${child.level}`);
    });
  }

  show() {
    stroke(255);
    strokeWeight(2);
    if (this.mouseOn()) fill(255);
    else noFill();

    rect(this.pos.x, this.pos.y, pDim.width, pDim.height, pDim.cornerRad);
  }

  mouseOn() {
    return (
      mouseX > this.pos.x &&
      mouseX < this.pos.x + pDim.width &&
      mouseY > this.pos.y &&
      mouseY < this.pos.y + pDim.height
    );
  }

  addParent(parent) {
    this.parents.push(parent);
    parent.children.push(this);
    parent.level = this.level - 1;
  }

  addSibling(sibling) {
    this.siblings.push(sibling);
    sibling.siblings.push(this);
    sibling.level = this.level;
  }

  addChild(child) {
    this.children.push(child);
    child.parents.push(this);
    child.level = this.level + 1;
  }
}

class Tree {
  constructor() {
    this.nodes = [];
    // this.root = new Person("Ayush", "Koul", gender.male, { x: width / 2, y: 20 });
    // this.node1 = new Person("Ayush", "Koul", gender.male, { x: width / 4, y: 20 });

    // this.root.addParent(new Person("Suhail", "Koul", gender.male));
    // this.root.addParent(new Person("Aruna", "Koul", gender.female));

    // this.root.addSibling(new Person("Aarul", "Koul", gender.male));

    // this.root.addChild(new Person("Child", "Koul", gender.female));

    // this.root.children[0].addChild(new Person("G.Child", "Koul", gender.male));
  }

  log() {
    this.root.log();
    this.root.parents.forEach((p) => {
      p.log();
    });

    this.root.children.forEach((c) => {
      c.log();
    });

    console.log(
      "Generation Gap between Suhail and Ayush: " +
        (this.root.level - this.root.parents[0].level)
    );
  }

  show() {
    this.nodes.forEach((node) => {
      node.show();
    });
  }

  addPerson(fname, lname, sex) {
    this.nodes.push(new Person(fname, lname, sex));
    this.nodes.sort((a, b) => {
      a.level - b.level;
    });
    this.nodes.forEach((node) => {
      console.log(node.fname);
    });
    console.log(this.nodes.length);
  }
}

let t;
let pos;

var modal = document.getElementById("modal");
var span = document.getElementById("close");

function setup() {
  // createCanvas(windowWidth,windowHeight);
  createCanvas(1200, 600);
  background(0);
  t = new Tree();
  t.addPerson("Ayush", "Koul", gender.male);
  t.addPerson("Aarul", "Koul", gender.female);
  // modal = select("#modal");
}

function draw() {
  background(0);
  t.show();
}

function mousePressed() {
  t.nodes.forEach(node => {
    if(node.mouseOn())
    modal.style.display = "block";
  });
  
}

// When the user clicks on <span> (x), close the modal

span.onclick = function () {
  modal.style.display = "none";
};

// When the user clicks anywhere outside of the modal, close it
window.onclick = function (event) {
  if (event.target === modal) {
    modal.style.display = "none";
  }
};
