import java.io.*;

public class D {
	public static void main(String[] args) throws Exception {
		BufferedReader sc = new BufferedReader(new InputStreamReader(System.in));
		int ntc = Integer.parseInt(sc.readLine());
		for (int itc = 0; itc < ntc; itc++) {
			String[] in = sc.readLine().split(" ");
			long k = Long.parseLong(in[0]);
			long n = Long.parseLong(in[1]);
			long x = Long.parseLong(in[2]);
			System.out.println(power(2, (n-1) * k));
		}
	}
	static long power(long a, long b) {
		if (b == 0) {
			return 1;
		}
		long temp = power(a, b / 2);
		temp *= temp;
		temp %= 1000000007;
		if (b % 2 == 1) {
			temp *= a;
			temp %= 1000000007;
		}
		return temp;
	}
}
