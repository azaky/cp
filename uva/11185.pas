var
  n:int64;
  ans:string;

begin
  repeat
    readln(n); if n<0 then break else ans:='';
	repeat
	  ans:=chr((n mod 3)+ord('0'))+ans;
	  n:=n div 3;
	until n=0;
	writeln(ans);
  until false;
end.
