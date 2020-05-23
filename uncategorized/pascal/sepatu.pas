var
  n,m,i,hasil,max:integer;
  bebek,sepatu:array[1..1000] of integer;
  statsepatu:array[1..1000] of boolean;

procedure pakai(k:integer);
  var
    i,j,temphasil:integer;
    tempsepatu:array[1..1000] of boolean;

  begin
    if k>n then
      begin
        if hasil>max then max:=hasil;
      end
    else
      begin
        temphasil:=hasil;
        for i:=1 to m do tempsepatu[i]:=statsepatu[i];
        pakai(k+1);
        for i:=1 to m do if not(tempsepatu[i]) and ((bebek[k]=sepatu[i]) or (bebek[k]=sepatu[i]-1)) then
          begin
            hasil:=temphasil;
            for j:=1 to m do statsepatu[j]:=tempsepatu[j];
            statsepatu[i]:=true;
            inc(hasil);
            pakai(k+1);
          end;
      end;
  end;

begin
  readln(n,m);
  for i:=1 to n do readln(bebek[i]);
  for i:=1 to m do readln(sepatu[i]);
  hasil:=0;
  max:=0;
  pakai(1);
  writeln(max);
end.
