{
ID: a_zaky01
PROG: ariprog
LANG: PASCAL
}

var
  i,j,max,len,limit,diff,diff0,size,num,len0,bound,p,c:longint;
  found,meet:boolean;
  stat:array[0..250000] of boolean;
  temp,bisq:array[1..125000] of longint;
  apadong:boolean;
  fin,fout:text;

procedure sort(l,r:longint);
  var
    i,j,temp,mid:longint;

  begin
    i:=l;
    j:=r;
    mid:=bisq[(l+r) div 2];
    repeat
      while bisq[i]<mid do inc(i);
      while bisq[j]>mid do dec(j);
      if i<=j then
        begin
          temp:=bisq[i];
          bisq[i]:=bisq[j];
          bisq[j]:=temp;
          inc(i);
          dec(j);
        end;
    until i>j;
    if l<j then sort(l,j);
    if i<r then sort(i,r);
  end;

begin
  assign(fin,'ariprog.in');
  assign(fout,'ariprog.out');
  reset(fin);
  rewrite(fout);
  readln(fin,len);
  readln(fin,limit);
  size:=0;
  for i:=0 to limit do
    for j:=i to limit do
      begin
        if not stat[i*i+j*j] then
          begin
            inc(size);
            bisq[size]:=i*i+j*j;
          end;
        stat[i*i+j*j]:=true;
      end;
  sort(1,size);
  max:=2*limit*limit;
  found:=false;
  if len=3 then
    for diff:=1 to (max div (len-1)) do
      begin
        p:=1;
        while bisq[p]<=max-(len-2)*diff do
          begin
            meet:=true;
            for c:=1 to len-1 do
              if not stat[bisq[p]+c*diff] then
                begin
                  meet:=false;
                  break;
                end;
            if meet then
              begin
                found:=true;
                writeln(fout,bisq[p],' ',diff);
              end;
            inc(p);
          end;
      end
  else for diff0:=1 to (max div ((len-1)*4)) do
    begin
      p:=1;
      diff:=4*diff0;
      while bisq[p]<=max-(len-2)*diff do
        begin
          meet:=true;
          for c:=1 to len-1 do
            if not stat[bisq[p]+c*diff] then
              begin
                meet:=false;
                break;
              end;
          if meet then
            begin
              found:=true;
              writeln(fout,bisq[p],' ',diff);
            end;
          inc(p);
        end;
    end;
  if not found then writeln(fout,'NONE');
  close(fin);
  close(fout);
end.
