import java.util.*;

public class Prims {

    static class Edge implements Comparable<Edge> {
        int to, weight;

        Edge(int t, int w) {
            to = t;
            weight = w;
        }

        public int compareTo(Edge o) {
            return Integer.compare(weight, o.weight);
        }
    }

    public static void prims(int[][] graph) {
        int n = graph.length;
        boolean[] visited = new boolean[n];
        PriorityQueue<Edge> pq = new PriorityQueue<>();
        pq.add(new Edge(0, 0)); // start from vertex 0

        int mstWeight = 0;

        while (!pq.isEmpty()) {
            Edge e = pq.poll();
            if (visited[e.to]) continue;
            visited[e.to] = true;
            mstWeight += e.weight;

            for (int i = 0; i < n; i++) {
                if (!visited[i] && graph[e.to][i] != 0) {
                    pq.add(new Edge(i, graph[e.to][i]));
                }
            }
        }

        System.out.println("MST Weight: " + mstWeight);
    }

    public static void main(String[] args) {
        // Example graph as adjacency matrix
        // 0 means no edge
        int[][] graph = {
            {0, 2, 0, 6, 0},
            {2, 0, 3, 8, 5},
            {0, 3, 0, 0, 7},
            {6, 8, 0, 0, 9},
            {0, 5, 7, 9, 0}
        };

        prims(graph);
    }
}
