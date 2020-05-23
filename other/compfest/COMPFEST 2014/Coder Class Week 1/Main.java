import java.util.*;
import java.lang.*;
import java.io.*;

public class Main
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner sc = new Scanner(System.in);
		int ntc = Integer.parseInt(sc.nextLine());
		for (int itc = 0; itc < ntc; itc++) {
			String s = sc.nextLine();
			int n = s.length();
			int[] lis = new int[n];
			int nlis = 0;
			for (int i = 0; i < n; i++) {
				lis[i] = 1;
				for (int j = 0; j < i; j++) {
					if (s.charAt(j) <= s.charAt(i) && lis[i] <= lis[j]+1) {
						lis[i] = lis[j] + 1;
					}
				}
				if (lis[i] > nlis) {
					nlis = lis[i];
				}
			}
			System.out.println(n - nlis);
		} 
	}
}
