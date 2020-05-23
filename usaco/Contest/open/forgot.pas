{
ID: a_zaky01
PROG: forgot
LANG: PASCAL
}

var
  l,n,i:integer;
  pass:string;
  w:array[1..1000] of string[20];
  ans:array[0..1000] of ansistring;
  visit:array[0..1000] of boolean;

procedure sort(l,r:integer);
  var
    i,j:integer;
    mid,temp:string[20];
  
  begin
    i:=l; j:=r; mid:=w[(l+r) div 2];
    repeat
      while w[i]<mid do inc(i);
      while w[j]>mid do dec(j);
      if i>j then break;
      temp:=w[i]; w[i]:=w[j]; w[j]:=temp;
      inc(i); dec(j);
    until false;
    if l<j then sort(l,j);
    if i<r then sort(i,r);
  end;

procedure check(k:integer; s:string);
  var
    i,j:integer;
    match:boolean;
  
  begin
    if visit[k] then
      begin
        if ans[k]>s then
          for i:=1 to k do ans[k][i]:=s[i];
        exit;
      end;
    visit[k]:=true; ans[k]:=s;
    for i:=1 to n do
      begin
        if k+length(w[i])>l then continue;
        match:=true;
        for j:=1 to length(w[i]) do
          if (w[i][j]<>pass[k+j]) and (pass[k+j]<>'?') then
            begin
              match:=false;
              break;
            end;
        if match then check(k+length(w[i]),s+w[i]);
      end;
  end;

begin
  assign(input,'forgot.in'); reset(input);
  assign(output,'forgot.out'); rewrite(output);

  readln(l,n);
  readln(pass);
  for i:=1 to n do readln(w[i]);
  sort(1,n);
  check(0,'');
  writeln(ans[l]);

  close(input);
  close(output);
end.
