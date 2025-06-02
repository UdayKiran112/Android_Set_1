
import java.util.*;

class MyHashMap {

    private static final int BUCKET_SIZE = 1009;
    private final List<Pair>[] table;

    @SuppressWarnings("unchecked") // Suppress unchecked cast warning
    public MyHashMap() {
        table = (List<Pair>[]) new ArrayList[BUCKET_SIZE]; // Safe cast
        for (int i = 0; i < BUCKET_SIZE; i++) {
            table[i] = new ArrayList<>();
        }
    }

    private int hash(int key) {
        return key % BUCKET_SIZE;
    }

    public void put(int key, int value) {
        int idx = hash(key);
        for (Pair p : table[idx]) {
            if (p.key == key) {
                p.value = value;
                return;
            }
        }
        table[idx].add(new Pair(key, value));
    }

    public int get(int key) {
        int idx = hash(key);
        for (Pair p : table[idx]) {
            if (p.key == key) {
                return p.value;
            }
        }
        return -1;
    }

    public void remove(int key) {
        int idx = hash(key);
        Iterator<Pair> it = table[idx].iterator();
        while (it.hasNext()) {
            if (it.next().key == key) {
                it.remove();
                return;
            }
        }
    }

    static class Pair {

        int key, value;

        Pair(int k, int v) {
            key = k;
            value = v;
        }
    }

    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in)) { // ✅ Auto-close scanner
            MyHashMap obj = new MyHashMap();

            while (sc.hasNextLine()) {
                String line = sc.nextLine().trim();
                if (line.equals("exit;") || line.equals("exit")) {
                    break;
                }

                if (line.startsWith("obj.put")) {
                    int[] parsed = parseTwoInts(line);
                    obj.put(parsed[0], parsed[1]);
                } else if (line.startsWith("obj.get")) {
                    int key = parseOneInt(line);
                    System.out.println(obj.get(key));
                } else if (line.startsWith("obj.remove")) {
                    int key = parseOneInt(line);
                    obj.remove(key);
                }
            }
        }
    }

    private static int parseOneInt(String line) {
        int start = line.indexOf('(');
        int end = line.indexOf(')');
        return Integer.parseInt(line.substring(start + 1, end).trim());
    }

    private static int[] parseTwoInts(String line) {
        int start = line.indexOf('(');
        int end = line.indexOf(')');
        String[] parts = line.substring(start + 1, end).split(",");
        return new int[]{
            Integer.parseInt(parts[0].trim()),
            Integer.parseInt(parts[1].trim())
        };
    }
}
