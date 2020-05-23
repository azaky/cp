import java.io.*;
import java.util.*;

public class B {
	public static void main(String[] args) throws Exception {
		BufferedReader sc = new BufferedReader(new InputStreamReader(System.in));
		int ntc = Integer.parseInt(sc.readLine());
		for (int itc = 0; itc < ntc; itc++) {
			String[] in;
			in = sc.readLine().split(" ");
			int n = Integer.parseInt(in[0]);
			int m = Integer.parseInt(in[1]);
			List<List<Integer>> adj = new ArrayList<List<Integer>>();
			for (int i = 0; i < n; i++) {
				adj.add(new ArrayList<Integer>());
			}
			for (int i = 0; i < m; i++) {
				in = sc.readLine().split(" ");
				int x = Integer.parseInt(in[0]) - 1;
				int y = Integer.parseInt(in[1]) - 1;
				adj.get(x).add(y);
				adj.get(y).add(x);
			}
			boolean cantik = true;
			if (m != n-1) {
				cantik = false;
			}
			int[] d = new int[4]; 
			for (int i = 0; i < n && cantik; i++) {
				int degree = adj.get(i).size();
				if (degree > 3 || degree < 1) {
					cantik = false;
				}
				else {
					d[degree]++;
				}
				if (degree == 1) {
					if (adj.get(adj.get(i).get(0)).size() != 3) {
						cantik = false;
					}
				}
			}
			if (d[1] != 4 || d[2] != n-6 || d[3] != 2) {
				cantik = false;
			}
			boolean[] v = new boolean[n];
			fill(v, adj, 0);
			for (int i = 0; i < n && cantik; i++) {
				if (!v[i]) {
					cantik = false;
				}
			}
			if (cantik) {
				System.out.println("cantik");
			}
			else {
				System.out.println("tidak cantik");
			}
		}
	}
	public static void fill(boolean[] v, List<List<Integer>> adj, int u) {
		if (v[u]) {
			return;
		}
		v[u] = true;
		for (int w : adj.get(u)) {
			fill(v, adj, w);
		}
	}
	
}
