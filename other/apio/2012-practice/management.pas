var
  N,i,j:longint;
  s:string;

begin
  readln(N);
  for i:=1 to n do
    begin
      readln(s);
      for j:=1 to length(s) do s[j] := upcase(s[j]);
      for j:=1 to length(s) do s[j] := chr(ord(s[j])+ord('a')-ord('A'));
      writeln(s);
    end;
end.
