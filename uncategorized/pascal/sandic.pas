var
  i,k,step:longint;
  a,s:string[6];
  ch,space:char;

begin
  randomize;a:='';
  for i:=1 to 6 do a:=a+chr(random(10)+ord('0'));
  while true do
    begin
      read(ch,space);
      readln(s);
      if ch='!' then
        begin
          write(s=a); writeln(', ',step,' steps');
          writeln(a);
          halt;
        end;
      k:=0; inc(step);
      for i:=1 to 6 do
        if a[i]=s[i] then inc(k);
      writeln(k); flush(output);
    end;
end.

