
import java.util.*;

class LRUCache {

    private final int capacity;
    private final LinkedHashMap<Integer, Integer> map;

    public LRUCache(int capacity) {
        this.capacity = capacity;
        this.map = new LinkedHashMap<>(capacity, 0.75f, true) {
            @Override
            protected boolean removeEldestEntry(Map.Entry<Integer, Integer> eldest) {
                return size() > LRUCache.this.capacity;
            }
        };
    }

    public int get(int key) {
        return map.getOrDefault(key, -1);
    }

    public void put(int key, int value) {
        map.put(key, value);
    }
}

public class LRUCacheApp {

    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in)) {
            LRUCache lru = null;

            while (sc.hasNextLine()) {
                String line = sc.nextLine().trim().replaceAll("\\s+", "");
                if (line.isEmpty()) {
                    continue;
                }

                if (line.equalsIgnoreCase("exit;") || line.equalsIgnoreCase("exit")) {
                    break;
                }

                if (line.startsWith("LRUCache")) {
                    // LRUCache lru(2);
                    int start = line.indexOf('(') + 1;
                    int end = line.indexOf(')');
                    int capacity = Integer.parseInt(line.substring(start, end));
                    lru = new LRUCache(capacity);
                } else if (line.startsWith("lru.put")) {
                    // lru.put(1,1);
                    int start = line.indexOf('(') + 1;
                    int end = line.indexOf(')');
                    String[] parts = line.substring(start, end).split(",");
                    int key = Integer.parseInt(parts[0]);
                    int value = Integer.parseInt(parts[1]);
                    if (lru != null) {
                        lru.put(key, value);
                    }
                } else if (line.startsWith("lru.get")) {
                    // lru.get(1);
                    int start = line.indexOf('(') + 1;
                    int end = line.indexOf(')');
                    int key = Integer.parseInt(line.substring(start, end));
                    if (lru != null) {
                        System.out.println(lru.get(key));
                    }
                }
            }
        }
    }
}
