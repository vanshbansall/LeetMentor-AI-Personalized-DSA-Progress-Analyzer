const express = require("express");
const app = express();

app.use(express.json());

let problems = [];

app.post("/addProblem", (req, res) => {
    const { name, topic, difficulty, date } = req.body;

    const problem = {
        id: problems.length + 1,
        name,
        topic,
        difficulty,
        date
    };

    problems.push(problem);

    res.json({
        message: "Problem added successfully",
        problem
    });
});

app.get("/problems", (req, res) => {
    res.json(problems);
});

app.get("/analysis/topics", (req, res) => {
    let topicCount = {};

    problems.forEach(p => {
        topicCount[p.topic] = (topicCount[p.topic] || 0) + 1;
    });

    res.json(topicCount);
});

app.get("/analysis/weak-topic", (req, res) => {
    let topicCount = {};

    problems.forEach(p => {
        topicCount[p.topic] = (topicCount[p.topic] || 0) + 1;
    });

    let weakTopic = null;
    let min = Infinity;

    for (let t in topicCount) {
        if (topicCount[t] < min) {
            min = topicCount[t];
            weakTopic = t;
        }
    }

    res.json({ weakTopic });
});

app.listen(3000, () => {
    console.log("LeetMentor AI running on port 3000");
});
