const fs = require('fs');

// Part one
const input1 = fs.readFileSync("Day 1\\input1.txt", "utf8");
const elvesCaloriesSum1 = getCaloriesSum(input1);
console.log("Max calories:", elvesCaloriesSum1[elvesCaloriesSum1.length - 1]);

// Part two
const input2 = fs.readFileSync("Day 1\\input2.txt", "utf8");
const elvesCaloriesSum2 = getCaloriesSum(input2);

let topThreeTotal = 0;

for (let i = 1; i < 4; i++) {
    topThreeTotal += elvesCaloriesSum2[elvesCaloriesSum2.length - i];
}

console.log("Top three total calories:", topThreeTotal);

function getCaloriesSum(input) {

    let elvesCalories = input.split("\n\r")
    let elvesCaloriesInt = []

    elvesCalories.forEach(element => {
        let tmp = []
        let nums = element.split("\r\n")
        nums.forEach(num => {
            tmp.push(parseInt(num))
        });
        elvesCaloriesInt.push(tmp)
    });

    let elvesCaloriesSum = [];

    elvesCaloriesInt.forEach(element => {
        let sum = 0;
        element.forEach(num => {
            sum += num;
        });
        elvesCaloriesSum.push(sum);
    });

    return elvesCaloriesSum.sort();
}