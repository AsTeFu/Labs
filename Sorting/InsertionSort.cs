public class Sort {
	public static int[] InsertionSort(int[] arr) {
            int tmp;
            int elemntIndex;
			
			//Копируем массив, если необходимо
            int[] array = new int[arr.Length];
            for (int i = 0; i < arr.Length; i++) {
                array[i] = arr[i];
            }
			//================================
			
			//Сортируем
            for (int i = 1; i < array.Length; i++) {
                tmp = array[i];
                elemntIndex = i - 1;
                while (elemntIndex >= 0 && array[elemntIndex] > tmp)
                {
                    array[elemntIndex + 1] = array[elemntIndex];
                    array[elemntIndex] = tmp;
                    elemntIndex--;
                }
            }

            return array;
        }
}