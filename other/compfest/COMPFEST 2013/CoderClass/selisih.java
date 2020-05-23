import java.io.*;
import java.util.*;

public class Main {
	public static void main (String [] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(in.readLine());

		for(int i=0; i<t; i++){
			StringTokenizer st = new StringTokenizer(in.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			if (a < b) System.out.println(b-a);
				else System.out.println(a-b);
		}
	}
}
