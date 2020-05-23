var
	ans, n, ntc, itc, i, j: longint;
	lis: array[0..1111] of longint;
	s: ansistring;

begin
	readln(ntc);
	for itc:=1 to ntc do
	begin
		readln(s);
		n := length(s);
		ans := 0;
		for i := 1 to n do
		begin
			lis[i] := 1;
			for j := 1 to i-1 do
				if (s[j] <= s[i]) and (lis[j]+1 > lis[i]) then
					lis[i] := lis[j] + 1;
			if (ans < lis[i]) then ans := lis[i];
		end;
		writeln(n - ans);
	end;
end.
