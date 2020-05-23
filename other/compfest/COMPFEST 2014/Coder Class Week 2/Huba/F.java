import java.io.*;
import java.util.*;


public class F {
	public static void main(String[] args) throws Exception {
		BufferedReader sc = new BufferedReader(new InputStreamReader(System.in));
		int ntc = Integer.parseInt(sc.readLine());
		for (int itc = 0; itc < ntc; itc++) {
			String[] in = sc.readLine().split(" ");
			int n = Integer.parseInt(in[0]);
			int m = Integer.parseInt(in[1]);
			int k = Integer.parseInt(in[2]);
			List<Integer> a = new ArrayList<Integer>();
			for (int i = 0; i < m; i++) {
				int x = Integer.parseInt(sc.readLine());
				a.add(x);
			}
			a.add(0);
			a.add(n + 1);
			Collections.sort(a);
			int last = -2000000000;
			int ans = m;
			for (int i = 1; i < a.size(); i++) {
				int pos = a.get(i);
				int pre = a.get(i-1);
				if (last + k >= pos) {
					continue;
				}
				int first = Math.max(pre + 1, last + k);
				int count = (pos - first + k - 1) / k;
				ans += count;
				if (count > 0) {
					last = first + (count - 1) * k;
				}
				//System.out.printf("pos = %d, first = %d, last = %d, count = %d\n", pos, first, last, count);
			}
			System.out.println(ans);
		}
	}
}
