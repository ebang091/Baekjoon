import java.io.*;
import java.util.*;

public  class Main {
	static int N, E;
	static int INF = Integer.MAX_VALUE;
	static int n1;
	static int n2;
	static class Edge {
		int node;
		int weight;
		public Edge(int n, int w) {
			this.node = n;
			this.weight = w;
		}
	}
	
	static ArrayList<ArrayList<Edge>> graph;
	public static int dijkstra(int start, int end) {
		PriorityQueue<Edge> pq = new PriorityQueue<>((e1, e2) -> Integer.compare(e1.weight, e2.weight));
		int dist[] = new int[N+1];
		Arrays.fill(dist, INF);

		pq.add(new Edge(start, 0));
		dist[start] = 0;
		while (!pq.isEmpty()) {
			Edge cur = pq.poll();
			if(cur.node == end)
				return dist[cur.node];

			for(int i = 0; i < graph.get(cur.node).size(); i++) {
				Edge adj = graph.get(cur.node).get(i);
				int nextCost = adj.weight + dist[cur.node];
				if(nextCost < dist[adj.node]){
					dist[adj.node] = nextCost;
					pq.add(new Edge(adj.node, nextCost));
				}
			}
		}
		return dist[end];
	}

	public static void main(String []args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String input[] = br.readLine().split(" ");
		N = Integer.parseInt(input[0]);
		E = Integer.parseInt(input[1]);

		graph = new ArrayList<ArrayList<Edge>>();
		for(int i = 0; i < N; i++)
			graph.add(new ArrayList<Edge>());
		
		for(int i = 0; i < E; i++) {
			input = br.readLine().split(" ");		
			int a = Integer.parseInt(input[0])-1;
			int b = Integer.parseInt(input[1])-1;
			int w = Integer.parseInt(input[2]);

			graph.get(a).add(new Edge(b, w));
			graph.get(b).add(new Edge(a, w));
		}

		input = br.readLine().split(" ");
		n1 = Integer.parseInt(input[0]) - 1;
		n2 = Integer.parseInt(input[1]) - 1;

		int r1 = dijkstra(0, n1);
		int r2 = dijkstra(n1, n2);
		int r3 = dijkstra(n2, N-1);

		
		if(r1 == INF || r2 == INF || r3 == INF) {
			System.out.println("-1");
			return ;
		}

		int answer1 = r1 + r2+ r3;
		r1 = dijkstra(0, n2);
		r2 = dijkstra(n2, n1);
		r3 = dijkstra(n1, N-1);

		if(r1 == INF || r2 == INF || r3 == INF)
			System.out.println(-1);
		else
			System.out.println(Math.min(answer1, r1 + r2+ r3));
		

		
	}
}