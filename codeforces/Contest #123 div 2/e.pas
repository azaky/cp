var

procedure connect(v,u:longint);
  begin
    parent[v] := u;
    top[v] := top[u];
  end;

begin
  readln(n);
  for i:=1 to n do
    begin
      read(k[i]); k[i]:=k[i]+k[i-1];
      for j:=k[i-1]+1 to k[i] do read(v[j],x[j]);
    end;
  for i:=n downto 1 do
    begin
      top[i] := i;
      for j:=k[i-1]+1 to k[i] do
        begin
          if root[v[j]]>0 then connect(i,root[v[j]]);
          root[v[j]] := i;
        end;
      if root[i]>0 then connect(top[i],root[i]);
    end;
end.
