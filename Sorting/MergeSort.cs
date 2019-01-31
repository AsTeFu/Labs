public class Sort {
	public static int[] MergeSort(int[] array) {
            if (array.Length == 1)
                return array;
            int half = array.Length / 2;
            
            return Merge(MergeSort(array.Take(half).ToArray()), MergeSort(array.Skip(half).ToArray()));
        }
        public static int[] Merge(int[] left, int[] right) {
            int[] result = new int[left.Length + right.Length];

            int i = 0, j = 0;
            int r = 0;

            while (i < left.Length || j < right.Length) {
                if (i == left.Length)
                    result[r++] = right[j++];
                else if (j == right.Length)
                    result[r++] = left[i++];
                else if (left[i] < right[j]) 
                    result[r++] = left[i++];
                else result[r++] = right[j++];
            }

            return result;
        }
}