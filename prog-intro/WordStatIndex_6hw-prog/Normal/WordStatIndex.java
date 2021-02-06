import java.util.LinkedHashMap;
import java.util.Map;
import java.io.InputStreamReader;
import java.io.FileInputStream;
import java.io.OutputStreamWriter;
import java.io.FileOutputStream;
import java.util.Iterator;
import java.io.Writer;
import java.io.IOException;



public class WordStatIndex {
	public static void main(String[] args) {
		LinkedHashMap<String, IntList> map = new LinkedHashMap<String, IntList>();

		try {
			Scanner fin = new Scanner(args[0], "utf-8");
			try {
				int i = 1;
				while (fin.hasNext()) {
					String word = fin.next().toLowerCase();
					if (word.length() > 0) {
						if (map.get(word) != null) {
							map.get(word).add(i);
						} else {
							IntList cur = new IntList();
							cur.add(i);
							map.put(word, cur);
						}
					}
					i++;
				}
			} finally {
				fin.close();
			}		
		} catch (IOException e) {
			System.out.println("Input error" + e.getMessage());
			return;
		}


		try {
			Writer fout = new OutputStreamWriter(new FileOutputStream(args[1]), "utf-8");
			try {
				 for (Map.Entry<String, IntList> x : map.entrySet()) {
					fout.write(x.getKey() + " " + x.getValue().getLength() + " " + x.getValue().getList() + "\n");
			  	}
			} finally {
				fout.close();
			}
		} catch (IOException e) {
			System.out.println(e);
		}	
	}
}