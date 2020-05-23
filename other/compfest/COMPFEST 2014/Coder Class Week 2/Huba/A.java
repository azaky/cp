import java.io.*;


public class A {
	public static void main(String[] args) throws Exception {
		BufferedReader sc = new BufferedReader(new InputStreamReader(System.in));
		int ntc = Integer.parseInt(sc.readLine());
		for (int itc = 0; itc < ntc; itc++) {
			String[] in = sc.readLine().split(" ");
			int n = Integer.parseInt(in[0]);
			int m = Integer.parseInt(in[1]);
			int[][] a = new int[n+1][m+1];
			int[][] s = new int[n+1][m+1];
			for (int i = 1; i <= n; i++) {
				in = sc.readLine().split(" ");
				s[i][0] = 0;
				for (int j = 1; j <= m; j++) {
					a[i][j] = Integer.parseInt(in[j-1]);
					s[i][j] = (s[i][j-1] + a[i][j]) & 1;
				}
			}
			int ans = 0;
			for (int l = 1; l <= m; l++) {
				for (int r = l; r <= m; r++) {
					int[] t = new int[2];
					t[0] = 1;
					int temp = 0;
					for (int i = 1; i <= n; i++) {
						temp = (temp ^ s[i][r] ^ s[i][l-1]) & 1;
						ans += t[temp];
						t[temp]++;
					}
				}
			}
			System.out.println(ans);
		}
	}
}
