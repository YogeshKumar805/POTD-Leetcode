var maxAverageRatio = function (classes, extraStudents) {
    let heap = new MaxPriorityQueue({ priority: x => x[2] });

    for (let [pass, total] of classes) {
        let before = pass / total;
        let after = (pass + 1) / (total + 1);
        heap.enqueue([pass, total, after - before]);
    }

    while (extraStudents--) {
        let [pass, total] = heap.dequeue().element;
        pass++;
        total++;
        let before = pass / total;
        let after = (pass + 1) / (total + 1);
        heap.enqueue([pass, total, after - before]);
    }

    let sum = 0;

    while (!heap.isEmpty()) {
        let [pass, total] = heap.dequeue().element;
        sum += pass / total;
    }
    return sum / classes.length;
};
