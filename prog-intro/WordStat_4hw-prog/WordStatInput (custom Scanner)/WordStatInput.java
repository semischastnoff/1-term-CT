import java.util.LinkedHashMap;
import java.io.InputStreamReader;
import java.io.FileInputStream;
import java.io.OutputStreamWriter;
import java.io.FileOutputStream;
import java.util.Iterator;
import java.io.Writer;
import java.io.IOException;
import java.util.Map;



public class WordStatInput {
	public static void main(String[] args) {
		LinkedHashMap<String, Integer> map = new LinkedHashMap<String, Integer>();
		try {
			Scanner fin = new Scanner(args[0], "utf-8");
			try {
				while (fin.hasNext()) {
					String word = fin.next().toLowerCase();
					if (word.length() > 0) {
						map.put(word, map.getOrDefault(word, 0) + 1);
					}
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
				 for (Map.Entry<String, Integer> x : map.entrySet()) {
					fout.write(x.getKey() + " " + x.getValue() + "\n");
			  	}
			} finally {
				fout.close();
			}
		} catch (IOException e) {
			System.out.println(e);
		}	
	}
}