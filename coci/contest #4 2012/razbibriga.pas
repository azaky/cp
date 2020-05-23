var
  n,i,len:longint;
  s:string;
  w,x,y,z:char;
  ans,add:int64;
  a,temp:array['A'..'Z','A'..'Z'] of int64;

begin
  ans:=0;
  readln(n);
  for i:=1 to n do
    begin
      readln(s); if i=1 then len:=length(s);
      inc(a[s[1],s[len]]);
    end;
  for w:='A' to 'Z' do
    for x:='A' to 'Z' do
      for y:='A' to 'Z' do
        for z:='A' to 'Z' do
          begin
            add:=1;
            add:=add*a[w,x]; dec(a[w,x]);
            add:=add*a[w,y]; dec(a[w,y]);
            add:=add*a[x,z]; dec(a[x,z]);
            add:=add*a[y,z]; dec(a[y,z]);
            inc(ans,add);
            inc(a[w,x]); inc(a[w,y]); inc(a[x,z]); inc(a[y,z]);
          end;
  writeln(ans);
end.
