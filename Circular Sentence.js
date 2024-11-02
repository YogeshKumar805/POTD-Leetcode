/**
 * @param {string} sentence
 * @return {boolean}
 */
var isCircularSentence = function(s) {
    s=s.split(' ')
    s.push(s[0])

    for (let i=0;i<s.length-1;i++){
        if(s[i].at(-1)!==s[i+1].at(0))return false
    }
    return true
};
