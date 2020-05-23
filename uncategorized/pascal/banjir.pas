var
  t,kasus,n,m,i,j:integer;
  full:boolean;
  ch:char;
  obs:array[0..81,0..81] of boolean;

procedure flood(a,b:integer);
  begin
    if obs[a,b] then exit
      else obs[a,b]:=true;
    flood(a+1,b);
    flood(a-1,b);
    flood(a,b+1);
    flood(a,b-1);
  end;

begin
  readln(t);
  for kasus:=1 to t do
    begin
      fillchar(obs,sizeof(obs),true);
      readln(n,m);
      for i:=1 to n do
        begin
          for j:=1 to m do
            begin
              read(ch);
              obs[i,j]:=ch='#';
            end;
          readln;
        end;
      for i:=1 to n do
        if not obs[i,1] then flood(i,1);
      for i:=1 to n do
        if not obs[i,m] then  flood(i,m);
      for i:=1 to m do
        if not obs[n,i] then  flood(n,i);
      for i:=1 to m do
        if not obs[1,i] then  flood(1,i);
      full:=true;
      for i:=1 to n do
        for j:=1 to m do
          if not obs[i,j] then full:=false;
      if full then writeln('TIDAK')
        else writeln('YA');
    end;
end.

