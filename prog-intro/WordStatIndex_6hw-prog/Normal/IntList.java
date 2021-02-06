import java.util.Arrays;


public class IntList {
	private int[] list;
	private int ind;
	private int size;

	public IntList() {
		list = new int[1];
		ind = 0;
		size = 0;
	}

	public void add(int x) {
		if (ind == list.length) {
			list = Arrays.copyOf(list, list.length * 2);
		}
		list[ind] = x;
		size++;
		ind++;
	}

	public int get(int i) {
		if (i < list.length) {
			return list[i];
		} else {
			throw new NullPointerException();
		}
	}

	public String getList() {
		StringBuilder ans = new StringBuilder();
		for (int i = 0; i < size - 1; i++) {
			ans.append(list[i] + " ");
		}
		ans.append(list[size - 1]);
		return ans.toString();
	}

	public int getLength() {
		return size;
	}
}