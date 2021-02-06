import java.util.LinkedHashMap;
import java.util.Map;
import java.io.InputStreamReader;
import java.io.FileInputStream;
import java.io.OutputStreamWriter;
import java.io.FileOutputStream;
import java.util.Iterator;
import java.io.Writer;
import java.io.IOException;



public class WordStatLineIndex {
	public static void main(String[] args) {
		LinkedHashMap<String, IntList> map = new LinkedHashMap<String, IntList>();

		try {
			Scanner fin = new Scanner(args[0], "utf-8");
			try {
				int cnt_line = 1;
				while (fin.hasNextLine()) {
					//проходим по строкам
					int cnt_word = 1;
					Scanner line = new Scanner(fin.nextLine());
					while (line.hasNext()) {
						//проходим по словам в строке
						String word = line.next().toLowerCase();
						if (word.length() > 0) {
							if (map.get(word) != null) {
								map.get(word).add(cnt_line, cnt_word);
							} else {
								IntList cur = new IntList();
								cur.add(cnt_line, cnt_word);
								map.put(word, cur);
							}
						}
						cnt_word++;
					}
					cnt_line++;
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