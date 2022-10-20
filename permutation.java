/*順列
 * https://qiita.com/suzuki-navi/items/a80677a0747232843957
 */
class Main {
    public static boolean nextPermutation(int[] arr) {
      int len = arr.length;
      int left = len - 2;
      while (left >= 0 && arr[left] >= arr[left+1]) left--;
      if (left < 0) return false;
      int right = len - 1;
      while (arr[left] >= arr[right]) right--;
      { int t = arr[left]; arr[left] = arr[right];  arr[right] = t; }
      left++;
      right = len - 1;
      while (left < right) {
        { int t = arr[left]; arr[left] = arr[right]; arr[right] = t; }
        left++;
        right--;
      }
      return true;
    }
  
    public static void main(String[] args) {
      int len = 4;
      var arr = new int[len];
      for (int i = 0; i < len; i++) {
        arr[i] = 10 * (i+1);
      }
      do {
        var sb = new StringBuilder();
        for (int i = 0; i < len; i++) {
          sb.append(String.format(" %d", arr[i]));
        }
        System.out.println(sb);
      } while (nextPermutation(arr));
    }
  }
  