import java.util.*;
import java.io.*;


public class WordStatInputShingles {
	public static void main(String[] args) {
		try {
			Reader fin = new InputStreamReader(new FileInputStream(args[0]), "utf-8");
			Writer fout = new OutputStreamWriter(new FileOutputStream(args[1]), "utf-8");

			try {
				Map<String, Integer> map = new LinkedHashMap<String, Integer>();
				//ввод из файла
				char[] buffer = new char[1000];
				StringBuilder word = new StringBuilder();
				while (true) {
					int num = fin.read(buffer); //сколько символов считано
					if (num == -1) {
						break;
					}
					//формирование словаря
					String s = new String(buffer, 0, num);
					s = s.toLowerCase();
					for (int i = 0; i < num; i++) {
						//записываем слово в word
						if (Character.isAlphabetic(s.charAt(i)) || 
							Character.getType(s.charAt(i)) == Character.DASH_PUNCTUATION || 
							s.charAt(i) == '\'') { 
							word.append(s.charAt(i));
						} else {
							//добавляем в map
							if (word.length() != 0) {
								//считаем все подстроки длины 3
								for (int j = 0; j < word.length() - 2; j++) {
									String key = word.toString().substring(j, j + 3);
									if (map.get(key) != null) {
										map.put(key, map.get(key) + 1);
									} else {
										map.put(key, 1);
									}
								}
							}
							word.setLength(0);
						}
					}
				}
				//последнее слово
				if (word.length() != 0) {
					//считаем все подстроки длины 3
					for (int i = 0; i < word.length() - 2; i++) {
						String key = word.toString().substring(i, i + 3);
						if (map.get(key) != null) {
							map.put(key, map.get(key) + 1);
						} else {
							map.put(key, 1);
						}
					}
				}
				//вывод словаря
				Iterator iter = map.keySet().iterator();
				while (iter.hasNext()) {
					String key = (String) iter.next();
					fout.write(key + " " + map.get(key) + '\n');
				}
			} finally {
				//закрытие файлов
				fin.close();
				fout.close();
			}
		} catch(IOException e) {
			System.out.println(e.getMessage());
		}
	}
}