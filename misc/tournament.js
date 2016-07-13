// Generate a tournament schedule for n teams, subject to the following
// rules:
// 1. Each team has to play every other team.
// 2. Each team plays at most once a day.
//
// Questions:
// 1. How many days does the tournament last?
// 2. How many matches are there each day?

function generateSchedule(teams) {
    // Print the tournament schedule for the specified 'teams' to stdout.

    let size = teams.length;
    let days = size - 1;
    let matches = size / 2;
    for (let day = 0; day < days; ++day) {
        console.log("Day", day + 1);
        for (let i = 0; i < matches; ++i) {
            let a = teams[i];
            let b = teams[i + matches];
            console.log("    Team " + a + " vs. Team " + b);
        }
        rotate(teams);
    }
}

function rotate(teams) {
    // Rotate the specified 'teams' in-place such that the first element is
    // unchanged, and the rest of the array is shifted left by one position.

    let size = teams.length;
    let temp = teams[1];
    for (let i = 1; i < size - 1; ++i) {
        teams[i] = teams[i + 1];
    }
    teams[size - 1] = temp;
}

function main() {
    // Generate a tournament schedule for teams of size 'n'.

    let n = 8;
    let teams = [];
    for (let i = 0; i < n; ++i) {
        teams.push(String.fromCharCode("A".charCodeAt(0) + i));
    }
    generateSchedule(teams);
}

main();
