{
ID: a_zaky01
PROG: tour
LANG: PASCAL
}

var
  n,v,i,j,k,ans,p,c1,c2:longint;
  str,city1,city2:string;
  name:array[1..100] of string;
  con:array[1..100,1..100] of boolean;
  f:array[1..100,1..100] of integer;
  
begin

  assign(input,'tour.in');
  assign(output,'tour.out');
  reset(input);
  rewrite(output);

  readln(n,v);
  for i:=1 to n do readln(name[i]);
  for i:=1 to v do
    begin
      readln(str);
      p:=pos(' ',str);
      city1:=copy(str,1,p-1);
      city2:=copy(str,p+1,length(str)-p);
      for c1:=1 to n do
        if city1=name[c1] then break;
      for c2:=1 to n do
        if city2=name[c2] then break;
      con[c1,c2]:=true; con[c2,c1]:=true;
    end;
  
  fillchar(f,sizeof(f),0);
  f[1,1]:=1;
  for i:=1 to n-1 do
    for j:=i+1 to n do
      for k:=1 to j-1 do
        if (f[i,k]>0) and con[k,j] then
          if f[i,k]+1>f[i,j] then
            begin
              f[i,j]:=f[i,k]+1;
              f[j,i]:=f[i,j];
            end;
  
  ans:=0;
  for i:=1 to n-1 do
    if con[i,n] and (f[i,n]>ans) then ans:=f[i,n];
  
  if ans=0 then writeln(1)
    else writeln(ans);
  
  close(input);
  close(output);

end.

