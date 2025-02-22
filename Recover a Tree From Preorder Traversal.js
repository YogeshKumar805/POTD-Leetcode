const recoverFromPreorder = f = (traversal, d = 1) => {
    if (!traversal) return null;
    let [val, l, r] = traversal.split(new RegExp(`(?<!-)-{${d}}(?!-)`,'g'));
    return { val: +val, left: f(l, d + 1), right: f(r, d + 1)};
};
