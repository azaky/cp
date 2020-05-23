import java.io.BufferedReader;
import java.io.InputStreamReader;


public class E {
	public static void main(String[] args) throws Exception {
		BufferedReader sc = new BufferedReader(new InputStreamReader(System.in));
		int ntc = Integer.parseInt(sc.readLine());
		for (int itc = 0; itc < ntc; itc++) {
			int n = Integer.parseInt(sc.readLine());
			int[][] a = new int[n][2];
			for (int i = 0; i < 2; i++) {
				String s = sc.readLine();
				for (int j = 0; j < n; j++) {
					a[j][i] = s.charAt(j) - '0';
				}
			}
			int[][] dp = new int[n][4];
			dp[0][1] = a[0][0];
			dp[0][2] = a[0][1];
			dp[0][3] = a[0][0] | a[0][1];
			for (int i = 1; i < n; i++) {
				if (a[i][0] == 0) {
					dp[i][1] = dp[i-1][3];
				}
				else {
					dp[i][1] = Math.min(dp[i-1][1], Math.min(dp[i-1][2], dp[i-1][3])) + 1;
				}
				if (a[i][1] == 0) {
					dp[i][2] = dp[i-1][3];
				}
				else {
					dp[i][2] = Math.min(dp[i-1][1], Math.min(dp[i-1][2], dp[i-1][3])) + 1;
				}
				if ((a[i][0] & a[i][1]) == 1) {
					dp[i][3] = dp[i-1][3] + 1;
				}
				else {
					dp[i][3] = Math.max(dp[i][1], dp[i][2]);
				}
			}
			System.out.println(dp[n-1][3]);
		}
	}
}
