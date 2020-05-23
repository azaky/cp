var
  n,i,input:longint;

function prime(n:longint):boolean;
  var
    i:longint;

  begin
    prime:=true;
    if n=1 then prime:=false
      else for i:=2 to trunc(sqrt(n)) do if n mod i = 0 then
        begin
          prime:=false;
          break;
        end;
    end;

procedure dinner(n:longint);
  var
    i:longint;
    portion:real;

  begin
    portion:=-0.5;
    if prime(n+1) then write('NO ') else write('YES ');
    for i:=2 to n+1 do if prime(i) then portion:=portion+0.5 else portion:=portion+1;
    writeln(portion:0:1);
  end;

begin
  readln(n);
  for i:=1 to n do
    begin
      readln(input);
      dinner(input);
    end;
end.