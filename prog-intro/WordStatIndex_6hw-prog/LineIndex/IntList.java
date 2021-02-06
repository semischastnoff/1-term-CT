import java.util.Arrays;


public class IntList {
	private String[] list;
	private int ind;
	private int size;

	public IntList() {
		list = new String[1];
		ind = 0;
		size = 0;
	}

	public void add(int line, int num) {
		if (ind == list.length) {
			list = Arrays.copyOf(list, list.length * 2);
		}
		String elem = line + ":" + num;
		list[ind] = elem;
		size++;
		ind++;
	}

	public String get(int i) {
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