import java.util.*;

public class bfs {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        System.out.println(minPerfectSquares(n));
    }

    public static int minPerfectSquares(int n) {
        if (n <= 0) return 0;

        // Generate perfect squares up to n
        List<Integer> squares = new ArrayList<>();
        for (int i = 1; i * i <= n; i++) {
            squares.add(i * i);
        }

        // BFS
        Queue<Integer> queue = new LinkedList<>();
        boolean[] visited = new boolean[n + 1];
        queue.add(0);
        visited[0] = true;
        int level = 0;

        while (!queue.isEmpty()) {
            int size = queue.size();
            level++;
            for (int i = 0; i < size; i++) {
                int current = queue.poll();
                for (int sq : squares) {
                    int next = current + sq;
                    if (next == n) {
                        return level;
                    }
                    if (next < n && !visited[next]) {
                        visited[next] = true;
                        queue.add(next);
                    }
                }
            }
        }
        return -1; // Should not reach here for positive n
    }
}
