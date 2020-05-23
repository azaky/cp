{
ID: a_zaky01
PROG: contact
LANG: PASCAL
}

var
  a,b,n,max,temp,c,i,j,k,len:longint;
  ch:char;
  z:array[1..13] of integer;
  count,v:array[0..8189] of longint;
  scan:array[1..200000] of byte;

procedure sort(l,r:longint);
  var
    i,j,mid,temp:longint;

  begin
    i:=l;
    j:=r;
    mid:=count[(l+r) div 2];
    repeat
      while count[i]<mid do inc(i);
      while count[j]>mid do dec(j);
      if i<=j then
        begin
          if count[i]>count[j] then
            begin
              temp:=count[i];
              count[i]:=count[j];
              count[j]:=temp;
              temp:=v[i];
              v[i]:=v[j];
              v[j]:=temp;
            end;
          inc(i);
          dec(j);
        end;
    until i>j;
    if l<j then sort(l,j);
    if i<r then sort(i,r);
  end;

procedure sort2(l,r:longint);
  var
    i,j,mid,temp:longint;

  begin
    i:=l;
    j:=r;
    mid:=v[(l+r) div 2];
    repeat
      while v[i]<mid do inc(i);
      while v[j]>mid do dec(j);
      if i<=j then
        begin
          if i<j then
            begin
              temp:=v[i];
              v[i]:=v[j];
              v[j]:=temp;
            end;
          inc(i);
          dec(j);
        end;
    until i>j;
    if l<j then sort2(l,j);
    if i<r then sort2(i,r);
  end;

function binary(x:integer):string;
  var
    i,len:integer;

  begin
    len:=1;
    while z[len]<=x do inc(len);
    binary:='';
    dec(len);
    x:=x-z[len];
    for i:=1 to len do
      begin
        binary:=char(48+(x mod 2))+binary;
        x:=x div 2;
      end;
  end;

begin
  assign(input,'contact.in');
  assign(output,'contact.out');
  reset(input);
  rewrite(output);
  readln(a,b,n);
  max:=0;
  while not eof do
    begin
      read(ch);
      if (ch='0') or (ch='1') then
        begin
          inc(max);
          scan[max]:=ord(ch)-48;
        end;
    end;
  z[1]:=0;
  for i:=2 to 13 do z[i]:=2*z[i-1]+2;
  for i:=0 to 8189 do v[i]:=i;
  for len:=a to b do
    for i:=0 to max-len do
      begin
        temp:=0;
        for j:=1 to len do temp:=2*temp+scan[i+j];
        inc(count[temp+z[len]]);
      end;
  sort(0,8189);
  i:=8189;
  while n>0 do
    begin
      dec(n);
      if count[i]=0 then break;
      write(count[i]);
      j:=i;
      while count[j]=count[i] do dec(i);
      sort2(i+1,j);
      c:=6;
      for k:=i+1 to j do
        begin
          if c=6 then
            begin
              writeln;
              write(binary(v[k]));
            end
          else write(' ',binary(v[k]));
          c:=(c mod 6)+1;
        end;
      writeln;
    end;
  close(input);
  close(output);
end.
