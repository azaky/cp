const
  a1 = 'rakit.out';
  a2 = 'rakit.ans';
  res = 'result.txt';

var
  line:longint;
  f1,f2:text;
  s1,s2:string;
  same:boolean;
  
begin
  assign(f1,a1); reset(f1);
  assign(f2,a2); reset(f2);
  assign(output,res); rewrite(output);
  line:=0; same:=true;
  while not eof(f1) and not eof(f2) do
    begin
      inc(line);
      readln(f1,s1); readln(f2,s2);
      if s1<>s2 then
        begin
          same:=false;
          writeln(line);
        end;
    end;
  if same then writeln('positive');
  close(f1); close(f2); close(output);
end.
