public class SumFloat {
	public static void main(String[] args) {
		int sum = 0;
		for (int i = 0; i < args.length; i++) {
			String num = "";
			for (int j = 0; j < args[i].length(); j++) {
				if (!Character.isWhitespace(args[i].charAt(j))) {
					num += args[i].charAt(j);
				} else {
					if (!num.equals("")) {
						sum += Float.parseFloat(num);
						num = "";
					}
				}	
			}
			if (!num.equals("")) {
				sum += Float.parseFloat(num);
			}
		}
		System.out.println(sum);
	}
}