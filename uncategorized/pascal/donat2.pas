var
  t,kasus,i,j,i1,j1,k,n,m,ans:longint;
  input:string;
  valid:boolean;
  a:array[0..101,0..101] of char;
  stat:array[0..101,0..101] of boolean;
  sign:array[0..101,0..101] of integer;
  donat:array[0..10000] of integer;

procedure fill1(i,j:integer);
  var
    i1,j1:integer;

  begin
    if not stat[i,j] and (i>0) and (j>0) and (i<=n) and (j<=m) and (a[i,j]='1') then
      begin
        stat[i,j]:=true;
        sign[i,j]:=k;
        for i1:=i-1 to i+1 do
          for j1:=j-1 to j+1 do
            if a[i1,j1]='1' then fill1(i1,j1);
      end;
  end;

procedure fill0(i,j,k:integer);
  var
    i1,j1:integer;

  begin
    if not stat[i,j] and (i>0) and (j>0) and (i<=n) and (j<=m) then
      begin
        stat[i,j]:=true;
        for i1:=i-1 to i+1 do
          for j1:=j-1 to j+1 do
            if (i1=i) or (j1=j) then
              if a[i1,j1]='0' then fill0(i1,j1,k)
                else if sign[i1,j1]<>k then valid:=false;
      end;
  end;

begin
  readln(t);
  for kasus:=1 to t do
    begin
      fillchar(stat,sizeof(stat),false);
      fillchar(sign,sizeof(sign),0);
      fillchar(a,sizeof(a),'?');
      fillchar(donat,sizeof(donat),0);
      readln(n,m);
      for i:=1 to n do
        begin
          readln(input);
          for j:=1 to m do a[i,j]:=input[j];
        end;
      k:=0;
      for i:=1 to n do
        for j:=1 to m do
          if (a[i,j]='1') and not stat[i,j] then
            begin
              inc(k);
              fill1(i,j);
            end;
      for i:=1 to n do
        for j:=1 to m do
          if a[i,j]='1' then
            for i1:=i-1 to i+1 do
              for j1:=j-1 to j+1 do
                if (a[i1,j1]='0') and not stat[i1,j1] then
                  begin
                    valid:=true;
                    fill0(i1,j1,sign[i,j]);
                    if valid then inc(donat[sign[i,j]]);
                  end;
      ans:=0;
      for i:=1 to k do
        if donat[i]=1 then inc(ans);
      writeln(ans);
    end;
end.
