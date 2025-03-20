// A Rock
// B Paper
// C Scissors

// X Rock
// Y Paper
// Z Scissors

const fs = require('fs');

const input1 = fs.readFileSync("Day 2\\input1.txt", "utf8");

const tmp1 = input1.split("\r\n");
const moves1 = [];

tmp1.forEach(element => {
    moves1.push(element.split(" "));
});

let score = 0;
moves1.forEach(move => {
    let opponent = move[0];
    let me = move[1];

    score += PartOne(opponent, me);
});

console.log("Part one:",score);

score = 0;

const input2 = fs.readFileSync("Day 2\\input2.txt", "utf8");

const tmp2 = input2.split("\r\n");
const moves2 = [];

tmp2.forEach(element => {
    moves2.push(element.split(" "));
});

moves2.forEach(move => {
    let opponent = move[0];
    let me = move[1];

    score += PartTwo(opponent, me);
});

console.log("Part two:",score);


function PartOne(opponent, me) {
    let score = 0;
    switch (opponent) {
        case "A":
            switch (me) {
                case "X":
                    score += 1;
                    score += 3;
                    break;

                case "Y":
                    score += 2;
                    score += 6;
                    break;

                case "Z":
                    score += 3;
                    break;
            }
            break;

        case "B":
            switch (me) {
                case "X":
                    score += 1;
                    break;

                case "Y":
                    score += 2;
                    score += 3;
                    break;

                case "Z":
                    score += 3;
                    score += 6;
                    break;
            }
            break;

        case "C":
            switch (me) {
                case "X":
                    score += 1;
                    score += 6;
                    break;

                case "Y":
                    score += 2;
                    break;

                case "Z":
                    score += 3;
                    score += 3;
                    break;
            }
            break;
    }
    return score;
}

function PartTwo(opponent, me) {
    let score = 0;
    switch (opponent) {
        case "A":
            switch (me) {
                case "X":
                    // Loose => Scissor 
                    score += 3;
                    break;

                case "Y":
                    // Draw => Rock
                    score += 1;
                    score += 3;
                    break;

                case "Z":
                    // Win => Paper
                    score += 2;
                    score += 6;
                    break;
            }
            break;

        case "B":
            switch (me) {
                case "X":
                    // Loose => Rock
                    score += 1;
                    break;

                case "Y":
                    // Draw => Paper
                    score += 2;
                    score += 3;
                    break;

                case "Z":
                    // Win => Scissor
                    score += 3;
                    score += 6;
                    break;
            }
            break;

        case "C":
            switch (me) {
                case "X":
                    // Loose => Paper
                    score += 2;
                    break;

                case "Y":
                    // Draw => Scissor
                    score += 3;
                    score += 3;
                    break;

                case "Z":
                    // Win => Rock
                    score += 1;
                    score += 6;
                    break;
            }
            break;
    }
    return score;
}