import java.io.*;


public class C {
	public static void main(String[] args) throws Exception {
		BufferedReader sc = new BufferedReader(new InputStreamReader(System.in));
		int ntc = Integer.parseInt(sc.readLine());
		for (int itc = 0; itc < ntc; itc++) {
			String in[] = sc.readLine().split(" ");
			int n = Integer.parseInt(in[0]);
			int m = Integer.parseInt(in[1]);
			in = sc.readLine().split(" ");
			int d = Integer.parseInt(in[0]);
			int a = Integer.parseInt(in[1]);
			int b = Integer.parseInt(in[2]);
			int c = Integer.parseInt(in[3]);
			int p = Integer.parseInt(in[4]);
			int[][] r = tanam(d, a, b, c, p, n);
			in = sc.readLine().split(" ");
			d = Integer.parseInt(in[0]);
			a = Integer.parseInt(in[1]);
			b = Integer.parseInt(in[2]);
			c = Integer.parseInt(in[3]);
			p = Integer.parseInt(in[4]);
			int[][] s = tanam(d, a, b, c, p, m);
			
			int[][] sum = new int[n][n];
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (i == 0 && j == 0) {
						sum[i][j] = r[i][j];
					}
					else if (i == 0) {
						sum[i][j] = sum[i][j-1] + r[i][j];
					}
					else if (j == 0) {
						sum[i][j] = sum[i-1][j] + r[i][j];
					}
					else {
						sum[i][j] = sum[i][j-1] + sum[i-1][j] - sum[i-1][j-1] + r[i][j];
					}
				}
			}
			long ans = 0;
			for (int i = 0; i < m; i++) {
				for (int j = 0; j < m; j++) {
					/* sum(i, j, i + n-m, j + n-m) */
					int total = sum[i + n-m][j + n-m] - (i == 0 ? 0 : sum[i-1][j + n-m]) - (j == 0 ? 0 : sum[i + n-m][j-1]) + (i == 0 | j == 0 ? 0 : sum[i-1][j-1]);
					if (s[i][j] == 1) {
						total = (n - m + 1) * (n - m + 1) - total;
					}
					ans += (long)total;
				}
			}
			System.out.println(ans);
		}
	}
	static int[][] tanam(int d, int a, int b, int c, int p, int n) {
		int[] r = new int[n*n];
		int[][] rr = new int[n][n];
		r[0] = d;
		for (int i = 1; i < n*n; i++) {
			r[i] = (a * r[i-1] + b) % c;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				rr[i][j] = (r[n * i + j] >= p) ? 1 : 0;
			}
		}
		return rr;
	}
}
