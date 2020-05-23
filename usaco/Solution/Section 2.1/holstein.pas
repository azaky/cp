{
ID: a_zaky01
PROG: holstein
LANG: PASCAL
}

type
  data=array[1..15] of boolean;

var
  i,j,v,g,min:integer;
  d,ans:data;
  a:array[1..15,1..25] of integer;
  vit:array[1..25] of integer;
  fin,fout:text;

procedure holstein(n,k:integer; d:data);
  var
    i:integer;

  function check:boolean;
    var
      i,j:integer;
      sum:array[1..25] of integer;

    begin
      for i:=1 to v do sum[i]:=0;
      for i:=1 to g do
        if d[i] then for j:=1 to v do sum[j]:=sum[j]+a[i,j];
      check:=true;
      for i:=1 to v do
        if sum[i]<vit[i] then
          begin
            check:=false;
            break;
          end;
    end;

  begin
    if check then
      if k<min then
        begin
          for i:=1 to g do ans[i]:=d[i];
          min:=k;
        end
      else
    else if n<g then
      begin
        for i:=(n+1) to g do
          if k<min then
            begin
              d[i]:=true;
              holstein(i,k+1,d);
              d[i]:=false;
            end;
      end;
  end;

begin
  assign(fin,'holstein.in');
  assign(fout,'holstein.out');
  reset(fin);
  rewrite(fout);
  readln(fin,v);
  for i:=1 to v do read(fin,vit[i]);
  readln(fin,g);
  for i:=1 to g do
    for j:=1 to v do read(fin,a[i,j]);
  min:=g+1;
  for i:=1 to g do
    begin
      d[i]:=true;
      holstein(i,1,d);
      d[i]:=false;
    end;
  write(fout,min);
  for i:=1 to g do
    if ans[i] then write(fout,' ',i);
  writeln(fout);
  close(fin);
  close(fout);
end.
