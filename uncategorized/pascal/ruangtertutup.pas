var
  n,m,i,j,xi,xj,count:longint;
  input:string;
  gambar:array[0..251,0..251] of string;

begin
  readln(n,m);
  for i:=1 to m do gambar[0,i]:='.';
  for i:=1 to m do gambar[n+1,i]:='.';
  for i:=1 to n do
    begin
      readln(input);
      gambar[i,0]:='.';
      gambar[i,m+1]:='.';
      for j:=1 to m do gambar[i,j]:=input[j];
    end;
  count:=0;
  for i:=1 to n do
    for j:=1 to m do
      if gambar[i,j]='/' then
        begin
          xi:=i;
          xj:=j;
          while gambar[xi,xj]='/' do
            begin
              inc(xi);
              dec(xj);
            end;
          inc(xj);
          if gambar[xi,xj]='\' then
            begin
              while gambar[xi,xj]='\' do
                begin
                  inc(xi);
                  inc(xj);
                end;
              dec(xi);
              if gambar[xi,xj]='/' then
                begin
                  while gambar[xi,xj]='/' do
                    begin
                      dec(xi);
                      inc(xj);
                    end;
                  dec(xj);
                  if gambar[xi,xj]='\' then
                    begin
                      while gambar[xi,xj]='\' do
                        begin
                          if (xi=i) and (xj=j+1) then
                            begin
                              inc(count);
                              xi:=1;
                              xj:=1;
                            end;
                          dec(xi);
                          dec(xj);
                        end;
                    end;
                end;
            end;
        end;
  writeln(count);
end.