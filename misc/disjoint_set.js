// Input
// a_id  b_id c_id
// x     0    9
// y     0    7
// z     1    7
// t     1    6
// s     9    2

// Step 1: Break the input into pairs
let input = [
    ["ax", "b0"],
    ["ax", "c9"],
    ["ay", "b0"],
    ["ay", "c7"],
    ["az", "b1"],
    ["az", "c7"],
    ["at", "b1"],
    ["at", "c6"],
    ["as", "b9"],
    ["as", "c2"]
];

// Step 2: Create the Disjoint Set data structure
function DisjointSet() {
    this.map = new Map();
}

DisjointSet.prototype.findRoot = function(x) {
    let map = this.map;
    if (!map.has(x)) {
        throw new Error(x + " is not in the disjoint set");
    }
    let parent = map.get(x);
    if (0 < +parent) {
        return x;
    }
    let root = this.findRoot(parent);
    map.set(x, root);
    return root;
};

DisjointSet.prototype.merge = function(x, y) {
    let map = this.map;
    if (!map.has(x)) {
        map.set(x, 1);
    }
    if (!map.has(y)) {
        map.set(y, 1);
    }
    let rootX = this.findRoot(x);
    let rootY = this.findRoot(y);
    if (rootX === rootY) {
        return;
    }
    let sizeX = map.get(rootX);
    let sizeY = map.get(rootY);
    if (sizeX > sizeY) {
        map.set(rootX, sizeX + sizeY);
        map.set(rootY, rootX);
    } else {
        map.set(rootY, sizeX + sizeY);
        map.set(rootX, rootY);
    }
};

// Step 3: Feed the input to the disjoint set
function run() {
    let ds = new DisjointSet();
    input.forEach(([x, y]) => {
        ds.merge(x, y);
    });
    let groups = new Map();
    for (let node of ds.map.keys()) {
        let root = ds.findRoot(node);
        let group = groups.get(root);
        if (group) {
            group.add(node);
        } else {
            groups.set(root, new Set([node]));
        }
    }
    console.log(groups);
}

run();
