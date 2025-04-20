const numRabbits = (answers, f = {}) => 
    answers.reduce((m, n) => f[n] ? (f[n]--, m) : (f[n] = n, m + n + 1), 0);
