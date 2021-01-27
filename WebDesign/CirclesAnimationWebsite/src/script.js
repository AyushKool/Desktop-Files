/*
	
	Click and drag to pan around
	
*/
// Remember the current panning position.
let pan_ = createVector();
// This is the smooth pan position.
let pan = createVector();
// Similar to the global mouseDown but allows the code to populate mousePosPrev
// with a value /after/ mouseDown before using it for the panning.
let isClicking = false;
// The length of the animation.
let totalFrames = 200;
// The reciprocal of the total frames, premultiplied by TAU.
let recipTotalFrames = 1 / totalFrames * TAU;
// The amount of fully shown lissajous. It will render count + 1.
let count = 5;
// The reciprocal of count.
let recipCount = 1 / count;
// The draw loop function.
function draw(e) {
	// Size based on the window's width and height.
	let maxSize = min(width, height);
	// Scale the radius based on the window's width and height.
	let radius = map(maxSize, 0, 800, 0, 50);
	// Just 1/10th of the radius for use in the small circle around the left/top
	// circles.
	let radiusTenth = radius * 0.1;
	// Double the radius is the circumference.
	let circumference = radius * 2;
	// The total space for each lissajous.
	let spread = circumference * 1.2;
	// Half the spread.
	let spread_half = spread * 0.5;
	// Just the gap distance between lissajous.
	let gap = spread - circumference;
	// Half the gap.
	let gap_half = gap * 0.5;
	// The total width of the lissajous table -ish.
	let w = count * spread;
	// Half the total table width -ish.
	let w_half = 0.5 * w;
	// An offset that is negative half the total table width.
	let o = -w_half;
	// If the mouse is down,
	if(mouseDown) {
		// Check if we're already clicking.
		if(isClicking) {
			// Prevent drifting by requiring a mouse move from the last frame
			// time.
			if(_lastCanvasTime - mouseMove < 20) {
				// Add the difference of the last mouse position and the current
				// mouse position. This tells how far the mouse has moved since
				// the last frame. Min with 0 to prevent panning in the negative
				// direction.
				pan_.add(mousePos.copy().sub(mousePosPrev)).min(0, 0);
			}
		}
		// Not already clicking.
		else {
			// Set clicking to true for the next frame.
			isClicking = true;
		}
	}
	// Definitely not clicking.
	else {
		// Mark isClicking as false.
		isClicking = false;
		// Demo mode for CodePen previews.
		if(isPreviewEmbed()) {
			// Base time span for the demo animation
			let timeSpan = 3000;
			// The distance that the demo animation will pan around.
			let distance = spread * -8;
			// Generate the x/y positions by easing with 2 different easing
			// functions to create an asynchronous look between the X and Y
			// movement. This looks more interesting and is very smooth.
			let x = ease.quart.inOut(min(e, timeSpan * 1.5), 0, distance, timeSpan * 1.5);
			let y = ease.cubic.inOut(min(e, timeSpan), 0, distance, timeSpan);
			// Set these values to the pan offset
			pan.set(x, y, 0);
		}
	}
	// Smoothly lerp to the real pan position.
	pan.lerp(pan_, 0.1);
	// Scale the time to the pan distance? (scrapped)
	// let totalFrames = map(pan.mag(), 0, w, 300, 400);
	// Extend past the set amount of frames to create a pause.
	let frames = min(frameCount % (totalFrames * 1.2), totalFrames);
	// The current time based on the frames
	let frameT = frames * recipTotalFrames;
	// An integer offset to create an infinite plane of lissajous by reusing
	// spaces rather than rendering all possibly lissajous all the time. The pan
	// is inverted, divided by the spread, and then floored to create integers.
	let offset = pan.copy().mult(-1).div(spread).floor();
	/*
	 	Generate and invert an alpha mask for the table.
	*/
	// The edges of the inner section, used in the masking gradients.
	let outA = -w_half + spread_half;
	let outB = outA + w - radius * 0.5;
	// These masks will be used to fade the edges of the table.
	let outLeft = createLinearGradient(outA, 0, outB, 0);
	let outTop = createLinearGradient(0, outA, 0, outB);
	let outRight = createLinearGradient(outA, 0, outB, 0);
	let outBottom = createLinearGradient(0, outA, 0, outB);
	// Add the color stops to the left and top edges of these gradients.
	[ outLeft, outTop ].forEach(grad => {
		// Full alpha at this left stop.
		grad.addColorStop(0, hsl(0, 0, 0, 1));
		// Slightly over at 0 alpha.
		grad.addColorStop(recipCount * 0.25, hsl(0, 0, 0, 0));
	});
	// Add the color stops to the right and bottom edges of the gradients.
	[ outRight, outBottom ].forEach(grad => {
		// Full alpha at this right stop.
		grad.addColorStop(1, hsl(0, 0, 0, 1));
		// Over a partial lissajous at 0 alpha.
		grad.addColorStop((count - 1) * recipCount, hsl(0, 0, 0, 0));
	});
	// Only if there will be something painted later.
	if(frames) {
		// Create a rectangle that covers the entire canvas.
		beginPath();
		rect(-width_half, -height_half, width, height);
		// Fill it with the side gradients.
		fill(outLeft);
		fill(outTop);
		// fill(outRight);
		// fill(outBottom);
		// Don't remember settings in this section.
		push();
		// Create a rectangle that only covers the lissajous table elements.
		beginPath();
		rect(outA - 1, outA - 1, w);
		// This will invert the alpha of this section of the canvas. It will
		// create a square with specially faded edges for later compositing.
		compositeOperation(compOper.source.out);
		fill('black');
		pop();
	}
	// Cut off sharp line meetings.
	miterLimit(2);
	push();
	/*
	 	Draw the actual table of lissajous.
	*/
	// Get the pan position offset remainder after diving by the spread width
	// (aka the mod of the pan position and the spread width).
	let { x: panX, y: panY } = pan.copy().mod(spread);
	// This is effectively the x iterations of the table.
	for(let g = 1; g <= count + 1; g++) {
		// The offset position X of a future lissajous.
		let xOff = panX + (g * recipCount - 0.5) * w;
		// This is effectively the y iterations of the table.
		for(let h = 1; h <= count + 1; h++) {
			// The offset position Y of a future lissajous.
			let yOff = panY + (h * recipCount - 0.5) * w;
			// Iterate through this lissajous's points, up to the current frame
			// count of the animation.
			for(let i = 0; i < frames; i++) {
				// The current time position through the animation segment.
				let t = i * recipTotalFrames;
				// The time multiplied by the current iteration's X/Y count plus
				// the offset integer from the pan position.
				let s = t * (g + offset.x) + PI;
				let c = t * (h + offset.y) + PI;
				// The X and Y positions of this point in the animation.
				let x = sin(s) * radius + xOff;
				let y = cos(c) * radius + yOff;
				// If it's the first point in the loop, use moveTo.
				(!i ? moveTo : lineTo)(x, y);
			}
			// If the animation has hit the end,
			if(frames >= totalFrames) {
				// Close the lissajous.
				closePath();
			}
		}
	}
	// This keeps the alpha of the faded rectangle generated earlier.
	compositeOperation(compOper.source.in);
	// Stroke all of the lissajous at once.
	stroke(hsl(0, 0, 100), radius / 50 * 2);
	pop();
	// Generate X/Y/W/H of clipping rectangles for use in the top and left edge
	// circles.
	let clipRectPos1 = o + radius + gap_half;
	let clipRectPos2 = o - radius - gap_half;
	let clipRectSize1 = w;
	let clipRectSize2 = w + spread;
	let clipRectA = [ clipRectPos1 - 2, clipRectPos2 - 1, clipRectSize1 + 3, clipRectSize2 + 1 ];
	let clipRectB = [ clipRectPos2 - 1, clipRectPos1 - 2, clipRectSize2 + 1, clipRectSize1 + 3 ];
	push();
	/*
		Draw the top and left edge circles, dashed lines, and numbers.
	*/
	// Set up the font size and family.
	font(radius * 0.5 + 'px sans-serif');
	// Set up the text alignment.
	textAlign(TEXTALIGN_CENTER);
	textBaseline(TEXTBASELINE_MIDDLE);
	// Draw semi-transparent.
	fillStyle(hsl(0, 0, 100, 0.75));
	strokeStyle(hsl(0, 0, 100, 0.4));
	// Draw slightly thicker lines
	lineWidth(radius / 50 * 2.5);
	// 
	for(let i = 1; i <= count + 1; i++) {
		let { x, y } = pan.copy().mod(spread).add((i * recipCount - 0.5) * w);
		let iA = i + offset.x;
		let iB = i + offset.y;
		let { x: xA, y: yA } = createVector(0, radius).rotate(-frameT * iA + PI);
		let { x: xB, y: yB } = createVector(0, radius).rotate(-frameT * iB + PI);
		[
			{
				clipRect: clipRectA,
				staticCircle: [ x, o, radius ],
				spinningCircle: [ x + xA, o + yA, radiusTenth ],
				dashedLine: [ x + xA, o - radius, x + xA, w_half + spread ],
				text: iA
			}, {
				clipRect: clipRectB,
				staticCircle: [ o, y, radius ],
				spinningCircle: [ o + xB, y + yB, radiusTenth ],
				dashedLine: [ o - radius, y + yB, w_half + spread, y + yB ],
				text: iB
			}
		].forEach(n => {
			push();
			beginPath();
			rect(...n.clipRect);
			clip();
			fillText(n.text, ...n.staticCircle);
			beginPath();
			circle(...n.staticCircle);
			circle(...n.spinningCircle);
			ctx.setLineDash([]);
			stroke();
			beginPath();
			line(...n.dashedLine);
			ctx.setLineDash([ radius * 0.15 ]);
			stroke();
			pop();
		});
	}
	pop();
	// Fade the edges of the edge circles.
	compositeOperation(compOper.destination.out);
	beginPath();
	rect(...clipRectA);
	fill(outLeft);
	fill(outRight);
	beginPath();
	rect(...clipRectB);
	fill(outTop);
	fill(outBottom);
	if(document.getElementById('rainbow').checked) {
		compositeOperation(compOper.destination.over);
		let rainbowPoints = createVector(maxSize * 0.5 * 1.1, 0).rotate(e * 0.001);
		let rainbow = createLinearGradient(...rainbowPoints.xy, ...rainbowPoints.mult(-1).xy);
		let rainbowCount = 14;
		for(let i = 0; i <= rainbowCount; i++) {
			let t = i / rainbowCount;
			rainbow.addColorStop(t, hsl(t * 360, 100, 50));
		}
		globalAlpha(0.8);
		background(rainbow);
	}
}