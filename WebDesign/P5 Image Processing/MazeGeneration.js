class Cell {
	constructor(i, j, isObstacle = false) {
		this.i = i;
		this.j = j;
		this.isObstacle = isObstacle;
	}
}

class Grid {
	constructor(x, y, w, h, cellSize, borderSize) {
		this.counter = 0;

		this.x = x;
		this.y = y;
		this.w = w;
		this.h = h;
		this.cellSize = cellSize;
		this.borderSize = borderSize;

		//Calculate Number of Rows and Columns
		this.nRow = int((h - borderSize) / (borderSize + cellSize));
		this.nCol = int((w - borderSize) / (borderSize + cellSize));

		//Center the Grid
		let extraX = w - this.nCol * (borderSize + cellSize);
		let extraY = h - this.nRow * (borderSize + cellSize);
		this.x += int((extraX + borderSize) / 2.0 - borderSize);
		this.y += int((extraY + borderSize) / 2.0 - borderSize);

		this.grid = [];
		for (let i = 0; i < this.nRow; ++i)
			for (let j = 0; j < this.nCol; ++j)
				this.grid.push(new Cell(i, j));
	}

	show() {
		let startX = this.x + this.borderSize;
		let startY = this.y + this.borderSize;

		for (let i = 0; i < this.nRow; ++i) {
			for (let j = 0; j < this.nCol; ++j) {
				noStroke();
				this.grid[i * this.nCol + j].isObstacle ? fill(0) : fill(255);
				rect(startX + j * (this.cellSize + this.borderSize), startY + i * (this.cellSize + this.borderSize), this.cellSize);
			}
		}
	}

	generateMaze(startX = 1, endX = this.nCol - 2, startY = 1, endY = this.nRow - 2, excludeIND = -1) {

		let width = endX - startX + 1;
		let height = endY - startY + 1;

		let threshold = 3
		if (width < threshold || height < threshold) return;
		this.counter++;
		// if(this.counter > 9) return;
		let isVertical = height < width;
		// let isVertical = int(random(0, 2)) %2 == 0;
		if (isVertical) {
			// console.log('Vertical');
			let wallInd = int(random(startX + 1, endX - 1));
			// let wallInd = int((startX + endX) / 2);
			if (wallInd == excludeIND) {
				wallInd += endX - wallInd > wallInd - startX ? 1 : -1;
			}
			while (!this.grid[ (startY - 1)* this.nCol + wallInd].isObstacle || !this.grid[(endY + 1) * this.nCol + wallInd].isObstacle)
			{
				let dir = 1;
				if(wallInd == endX || wallInd == startX) dir *= -1;
				wallInd += dir;

			}

			let notWallInd = int(random(startY, endY));


			for (let i = startY; i <= endY; ++i)
				if (i != notWallInd)
					this.grid[i * this.nCol + wallInd].isObstacle = true;

			this.generateMaze(startX, wallInd - 1, startY, endY, notWallInd);
			this.generateMaze(wallInd + 1, endX, startY, endY, notWallInd);

		}
		else {
			// console.log('Horizontal');

			let wallInd = int(random(startY + 1, endY - 1));
			// let wallInd = int((startY + endY) / 2);

			if (wallInd == excludeIND) 
			{
				wallInd += endY - wallInd > wallInd - startY ? 1 : -1;
			}
			if (!this.grid[wallInd * this.nCol + startX - 1].isObstacle || !this.grid[wallInd * this.nCol + endX + 1].isObstacle)
			{
				let dir = 1;
				if(wallInd == endY || wallInd == startY) dir *= -1;
				wallInd += dir;
			}
			let notWallInd = int(random(startX, endX));

			for (let j = startX; j <= endX; ++j)
				if (j != notWallInd)
					this.grid[wallInd * this.nCol + j].isObstacle = true;

			this.generateMaze(startX, endX, startY, wallInd - 1, notWallInd);
			this.generateMaze(startX, endX, wallInd + 1, endY, notWallInd);


		}
	}

	makeBordersObstacle() {
		for (let j = 0; j < grid.nCol; ++j) {
			this.grid[j].isObstacle = true;
			this.grid[(this.nRow - 1) * this.nCol + j].isObstacle = true;
		}

		for (let i = 0; i < grid.nRow; ++i) {
			this.grid[i * this.nCol].isObstacle = true;
			this.grid[i * this.nCol + this.nCol - 1].isObstacle = true;
		}
	}
}

let grid;
let cWidth = 1201, cHeight = 601;
function setup() {
	createCanvas(cWidth, cHeight);
	background(51);
	grid = new Grid(0, 0, cWidth, cHeight, 29, 1);
	// frameRate(5);
	grid.makeBordersObstacle();
	grid.generateMaze();
	grid.show();
}

function draw() {
	// background(100);
}