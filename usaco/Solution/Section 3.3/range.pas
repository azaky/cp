{
ID: a_zaky01
PROG: range
LANG: PASCAL
}

var
  n,i,j,size:integer;
  input:string;
  found:boolean;
  fill,temp:array[1..500,1..500] of boolean;
  num:array[2..250] of longint;
  fin,fout:text;

begin
  assign(fin,'range.in');
  assign(fout,'range.out');
  reset(fin);
  rewrite(fout);
  readln(fin,n);
  for i:=1 to n do
    begin
      readln(fin,input);
      for j:=1 to n do
        if input[j]='1' then fill[i,j]:=true;
    end;
  for size:=2 to n do
    begin
      found:=false;
      fillchar(temp,sizeof(temp),false);
      for i:=1 to n-size+1 do
        for j:=1 to n-size+1 do
          if fill[i,j] and fill[i,j+1] and fill[i+1,j] and fill[i+1,j+1] then
            begin
              inc(num[size]);
              found:=true;
              temp[i,j]:=true;
            end;
      if not found then break;
      fill:=temp;
    end;
  for i:=2 to n do
    if num[i]>0 then writeln(fout,i,' ',num[i]);
  close(fin);
  close(fout);
end.
