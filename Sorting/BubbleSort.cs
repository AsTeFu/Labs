public class Sort {
	public static int[] BubbleSort(int[] arr) {
            bool exit = false;

			//Копируем массив, если необходимо
            int[] array = new int[arr.Length];
            for (int i = 0; i < arr.Length; i++) {
                array[i] = arr[i];
            }
			//================================

            while (!exit) {
                exit = true;
                for (int i = 0; i < array.Length - 1; i++) {
                    if (array[i] > array[i + 1]) {
                        int tmp = array[i];
                        array[i] = array[i + 1];
                        array[i + 1] = tmp;
                        exit = false;
                    }
                }

            }

            return array;
        }
}