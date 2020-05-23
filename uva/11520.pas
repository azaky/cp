var
  tc,kasus,i,j,n,k:longint;
  ch:char;
  a:array[0..11,0..11] of char;
  map:array[chr(0)..chr(255)] of longint;
  num:array[0..11,0..11] of longint;
  alpha:array[1..26] of char;

begin
  readln(tc);
  fillchar(map,sizeof(map),255);
  for ch:='A' to 'Z' do map[ch]:=ord(ch)-ord('A')+1;
  map['.']:=0;
  for i:=1 to 26 do alpha[i]:=chr(ord('A')-1+i);
  for kasus:=1 to tc do
    begin
	  readln(n); fillchar(num,sizeof(num),255);
	  for i:=1 to n do
	    begin
		  for j:=1 to n do
		    begin
			  read(a[i,j]); num[i,j]:=map[a[i,j]];
			end;
		  readln;
		end;
      writeln('Case ',kasus,':');
	  for i:=1 to n do
	    begin
	      for j:=1 to n do
		    begin
		      if a[i,j]<>'.' then
			    begin
				  write(a[i,j]); continue;
				end;
			  for k:=1 to 26 do
			    if (k<>num[i-1,j]) and (k<>num[i,j-1]) and (k<>num[i+1,j]) and (k<>num[i,j+1]) then break;
			  num[i,j]:=k; write(alpha[k]);
		    end;
		  writeln;
		end;
	end;
end.
