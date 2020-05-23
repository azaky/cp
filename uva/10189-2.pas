var
  tc,r,c,i,j,i1,j1:longint;
  a:array[0..111,0..111] of char;
  x:array[0..111,0..111] of longint;

begin
  while true do
    begin
      inc(tc);
      readln(r,c);
      if r+c=0 then exit;
      fillchar(a,sizeof(a),'.');
      for i:=1 to r do
        begin
         for j:=1 to c do read(a[i][j]);readln;
        end;
      for i:=1 to r do
        for j:=1 to c do
          begin
            if a[i][j]='*' then continue;
            x[i][j]:=0;
            for i1:=i-1 to i+1 do
              for j1:=j-1 to j+1 do
                if a[i1][j1]='*' then inc(x[i][j]);
          end;
      if tc>1 then writeln;
      for i:=1 to r do
        begin
          for j:=1 to c do write(x[i][j]);writeln;
        end;
    end;
end.
