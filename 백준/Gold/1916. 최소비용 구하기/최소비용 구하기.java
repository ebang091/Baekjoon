import java.io.*;
import java.util.*;

public class Main{
	static int N, M;
	static ArrayList<ArrayList<Edge>> graph;

	static class Edge {
		int node;
		long weight;
		public Edge(int n, long  w) {
			this.node = n;
			this.weight = w;
		}
	}
	
	public static long dijkstra(int start, int end) {
		long dist[] = new long[N+1];
		Arrays.fill(dist, Integer.MAX_VALUE);
		PriorityQueue<Edge> pq = new PriorityQueue<>((e1, e2) -> Long.compare(e1.weight, e2.weight));
		pq.add(new Edge(start, 0));
		dist[start] = 0;
		
		while(!pq.isEmpty()) {
			Edge cur = (Edge)pq.poll();
			if(cur.node == end)
				return dist[end];
			for(int i = 0; i < graph.get(cur.node).size(); i++){
				Edge adj = graph.get(cur.node).get(i);
				long nextCost = cur.weight + adj.weight;
				if(dist[adj.node] > nextCost) {
					dist[adj.node] = nextCost;
					pq.add(new Edge(adj.node, nextCost));
				}
			}
		}

		// for(int i =0 ;i < N;i++)
			// System.out.print(dist[i] + " ");
		// System.out.println();

		return dist[end];
	}

	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		N = Integer.parseInt(br.readLine());
		M = Integer.parseInt(br.readLine());	

		graph = new ArrayList<ArrayList<Edge>>();
		for(int i = 0; i < N; i++)
			graph.add(new ArrayList<Edge>());

		for(int i = 0; i < M; i++) {
			String input[] = br.readLine().split(" ");
			int a = Integer.parseInt(input[0]) -1;
			int b = Integer.parseInt(input[1]) -1;
			long w = Integer.parseInt(input[2]);
			
			graph.get(a).add(new Edge(b, w));
		}
		String input[] = br.readLine().split(" ");
		int a = Integer.parseInt(input[0]) -1;
		int b = Integer.parseInt(input[1]) -1;

		long result = dijkstra(a, b);
		System.out.println(result);
	}
}