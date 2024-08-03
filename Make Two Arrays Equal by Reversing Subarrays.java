class Solution {
  public boolean canBeEqual(int[] target, int[] arr) {
    var map = new int[1001];

    for (var n : arr) map[n]++;
    for (var n : target) map[n]--;

    return Arrays.equals(map, new int[1001]);
  }
}
