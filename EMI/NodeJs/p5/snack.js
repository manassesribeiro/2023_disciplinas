let player;
let snacks = [];
let score = 0;
let time = 30;

function setup() {
    createCanvas(400, 400);
    player = new Player();
    setInterval(addSnack, 1000);
    setInterval(updateTime, 1000);
}

function draw() {
    background(220);

    player.display();
    player.update();

    for (let i = snacks.length - 1; i >= 0; i--) {
        snacks[i].display();
        snacks[i].update();

        if (player.hits(snacks[i])) {
            snacks.splice(i, 1);
            score++;
        }
    }

    textSize(20);
    textAlign(LEFT);
    text('Score: ' + score, 10, 30);
    text('Time: ' + time, 10, 60);

    if (time === 0) {
        gameOver();
    }
}

function addSnack() {
    snacks.push(new Snack());
}

function updateTime() {
    if (time > 0) {
        time--;
    }
}

function gameOver() {
    noLoop();
    textSize(40);
    textAlign(CENTER);
    text('Game Over', width / 2, height / 2);
}

class Player {
    constructor() {
        this.x = width / 2;
        this.y = height / 2;
        this.size = 50;
    }

    display() {
        ellipse(this.x, this.y, this.size);
    }

    update() {
        this.x = mouseX;
        this.y = mouseY;
    }

    hits(snack) {
        let distance = dist(this.x, this.y, snack.x, snack.y);
        if (distance < (this.size + snack.size) / 2) {
        return true;
        } else {
        return false;
        }
    }
}

class Snack {
    constructor() {
        this.x = random(width);
        this.y = random(height);
        this.size = 20;
    }

    display() {
        ellipse(this.x, this.y, this.size);
    }

    update() {
        // Snacks can move or change properties here
    }
}